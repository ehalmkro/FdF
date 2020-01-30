/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:22:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/30 16:15:20 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>


void correct_axis(t_point *start, t_point *end, t_scene *draw)
{
	double x0;
	double x1;
	double y0;
	double y1;

	x0 = start->x;
	x1 = end->x;
	y0 = start->y;
	y1 = end->y;

	if (fabs(y1 - y0) < fabs(x1 - x0))
	{
		if (x0 > x1)
		{
			ft_swap(&(start->x), &(end->x));
			ft_swap(&(start->y), &(end->y));
		}
	}
	else
	{
		if (y0 > y1)
		{
			ft_swap(&(start->x), &(end->x));
			ft_swap(&(start->y), &(end->y));
		}
	}
}

void	put_pixel(double x, double y, int color, t_scene *draw)
{
	mlx_pixel_put(draw->mlx, draw->win, x + draw->padding_x, y + draw->padding_y, color);
}

static double	frc_part(double nbr)
{
	return (ceil(nbr) - nbr);
}


static void		draw_wu_slope(double x, double y, t_scene *draw)
{
	if (draw->slope >= 0)
	{
		put_pixel (floor (x), y, decrease_brightness (0xFFFFFF, 1 - frc_part (y)), draw);
		put_pixel (floor (x) + 1, y, decrease_brightness (0xFFFFFF, frc_part (y)), draw);
	}
	else if (draw->slope < 0)
	{
		put_pixel(floor(x), y, decrease_brightness (0xFFFFFF, 1 - frc_part(y)), draw);
		put_pixel(floor(x) - 1, y, decrease_brightness (0xFFFFFF, frc_part(y)), draw);
	}

}

static void		draw_wu_dots(t_point start, t_point end, t_scene *draw)
{
	while (start.x <= end.x)
	{
		if (draw->steep)
			draw_wu_slope(start.y, start.x, draw);
		else
			draw_wu_slope(start.x, start.y, draw);
		start.y += draw->slope;
		start.x++;
	}

}

void	draw_line_wu(t_point start, t_point end, t_scene *draw)
{
	double	dx;
	double	dy;

	draw->steep = fabs(end.y - start.y) > fabs(end.x - start.x) ? 1 : 0;
	if (draw->steep)
	{
		ft_swap(&start.x, &start.y);
		ft_swap(&end.x, &end.y);
	}
	if (end.x < start.x)
	{
		ft_swap(&start.x, &end.x);
		ft_swap(&start.y, &end.y);
	}
	dx = end.x - start.x;
	dy = end.y - start.y;
	draw->slope = dx == 0 ? 1 : dy / dx;
	draw_wu_dots(start, end, draw);


}

void	draw_line_gupta_sproull(t_point start, t_point end, t_scene *draw)
{
	correct_axis(&start, &end, draw);
	double dx;
	double dy;

	if (abs(end.y - start.y) < abs(end.x - start.x))
	{
		if (draw->steep)
		{
			ft_swap (&start.x, &start.y);
			ft_swap (&end.x, &end.y);
		}
		if (end.x < start.x)
		{
			ft_swap (&start.x, &end.x);
			ft_swap (&start.y, &end.y);
		}
	}
	dx = end.x - start.x;
	dy = end.y - start.y;
	int d = 2 * dy - dx;
	int incr_e = 2*dy;
	int incr_ne = 2*(dy-dx);
	int two_v_dx = 0;
	double invdenom = 1.0/(2.0*sqrt(dx*dx+dy*dy));
	double two_dx_invdenom = 2.0*dx*invdenom;

	double x = start.x;
	double y = start.y;

	put_pixel(x, y, decrease_brightness (0xFFFFFFF, 1.0), draw);
	put_pixel(x, y+1, decrease_brightness(0xFFFFFFF,two_dx_invdenom), draw);
	put_pixel(x, y-1, decrease_brightness(0xFFFFFFF,two_dx_invdenom), draw);
	while (x < end.x)
	{
		if (d < 0)
		{
			two_v_dx = d + dx;
			d += incr_e;
			x++;
		}
		else
		{
			two_v_dx = d - dx;
			d += incr_ne;
			x++;
			y++;
		}
		put_pixel(x, y, decrease_brightness (0xFFFFFFF, two_v_dx * invdenom), draw);
		put_pixel(x, y + 1, decrease_brightness (0xFFFFFFF, two_dx_invdenom - two_v_dx * invdenom), draw);
		put_pixel(x, y - 1, decrease_brightness (0xFFFFFFF, two_dx_invdenom + two_v_dx * invdenom), draw);
	}
}

//		BRESENHAM LINE ALGORITHM
void draw_line_bresenham(t_point start, t_point end, t_scene *draw)
{
	correct_axis(&start, &end, draw);
	t_point *delta;
	t_point *current;
	double pixelcount;

	current = point_node_new(start.x, start.y, 0, draw);
	delta = point_node_new(end.x - start.x,  end.y - start.y, 0, draw);
	pixelcount = sqrt((delta->x * delta->x) + (delta->y * delta->y));
	delta->x /= pixelcount;
	delta->y /= pixelcount;
	while (pixelcount > 0)
	{
		put_pixel(current->x, current->y, set_color(start, end, *delta, *current, *draw), draw);
		current->x += delta->x;
		current->y += delta->y;
		pixelcount--;
	}
	free(current);
	free(delta);
}
static void 	draw_isometric(t_map *start, t_scene *draw)
{
	t_point *begin;
	t_point *end;
	if (start->right)
	{
		begin = transform_isometric(start->data, draw);
		end = transform_isometric (start->right->data, draw);
		draw->draw_algorithm(*begin, *end, draw);
		free(begin);
		free(end);
	}
	if (start->down)
	{
		begin = transform_isometric(start->data, draw);
		end = transform_isometric (start->down->data, draw);
		draw->draw_algorithm(*begin, *end, draw);
		free(begin);
		free(end);
	}
	if (start->next)
		draw_isometric(start->next, draw);
	begin = transform_isometric(start->data, draw);
	draw->draw_algorithm(*begin ,*begin, draw);
	free(begin);
}

void	draw_matrix(t_map *start, t_scene *draw)
{
	if (draw->projection == ISOMETRIC)
		draw_isometric (start, draw);
	else
	{
		if (start->right)
			draw->draw_algorithm ((*start->data), (*start->right->data), draw);
		if (start->down)
			draw->draw_algorithm ((*start->data), (*start->down->data), draw);
		if (start->next)
			draw_matrix (start->next, draw);
		draw->draw_algorithm ((*start->data), (*start->data), draw);
	}
}