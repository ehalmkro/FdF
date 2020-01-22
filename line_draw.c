/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:22:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/22 20:02:27 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	put_pixel(double x, double y, double brightness, t_draw *draw)
{
	mlx_pixel_put(draw->mlx, draw->win, (int)x, (int)y, decrease_brightness(0xFFFF00, brightness));
}

// TODO: IMPLEMENT XIAOLIN WU LINE ALGORITHM
// swaps two numbers
void swap(int* a , int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*static double	frc_part(double nbr)
{
	return (ceil(nbr) - nbr);
}


static void		draw_wu_slope(double x, double y, t_draw *draw)
{
	if (draw->slope >= 0)
	{
		put_pixel(floor(x), y, 1 - frc_part(y), draw);
		put_pixel(floor(x) + 1, y, frc_part (y), draw);
	}
	else if (draw->slope < 0)
	{
		put_pixel(floor(x), y, 1 - frc_part(y), draw);
		put_pixel(floor(x) - 1, y, frc_part(y), draw);
	}

}

static void		draw_wu_dots(t_point start, t_point end, t_draw *draw)
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

void	draw_line_wu(t_point start, t_point end, t_draw *draw)
{
	double	dx;
	double	dy;

	draw->steep = fabs(end.y - start.y) > fabs(end.x - start.x) ? 1 : 0;
	if (draw->steep)
	{
		swap(&start.x, &start.y);
		swap(&end.x, &end.y);
	}
	if (end.x < start.x)
	{
		swap(&start.x, &end.x);
		swap(&start.y, &end.y);
	}
	dx = end.x - start.x;
	dy = end.y - start.y;
	draw->slope = dx == 0 ? 1 : dy / dx;
	draw_wu_dots(start, end, draw);

}*/

void	draw_line_gupta_sproull(t_point start, t_point end, t_draw *draw)
{
	double dx;
	double dy;

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
	put_pixel(x, y, 1.0, draw);
	put_pixel(x, y+1, two_dx_invdenom, draw);
	put_pixel(x, y-1, two_dx_invdenom, draw);
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
		put_pixel(x, y, two_v_dx * invdenom, draw);
		put_pixel(x, y + 1, two_dx_invdenom - two_v_dx * invdenom, draw);
		put_pixel(x, y - 1, two_dx_invdenom + two_v_dx * invdenom, draw);
	}
}


/*
void	draw_line_wu(t_point *start, t_point *end, t_draw *draw)
{
	double x0 = start->x;
	double x1 = end->x;
	double y0 = start->y;
	double y1 = end->y;
	int x_dir;
	if (y0 > y1)
		ft_swap(&y0, &y1);
	mlx_pixel_put(draw->mlx, draw->win, (int)x0, (int)y0, set_color(start, end));
	double delta_x = x1 - x0;
	if (delta_x >= 0.0)
		x_dir = 1;
	else
	{
		x_dir = -1;
		delta_x *= -1;
	}
	double delta_y = y1 - y0;
	if (delta_y == 0)
	{
		while (delta_x-- > 0)
		{
			x0 += x_dir;
			mlx_pixel_put(draw->mlx, draw->win, (int)x0, (int)y0, set_color(start, end));
		}
		return;
	}
	if (delta_x == 0)
	{
		while (delta_y-- > 0)
		{
			y0++;
			mlx_pixel_put(draw->mlx, draw->win, (int)x0, (int)y0, set_color(start, end));
		}
		return;
	}
	if (delta_x == delta_y)
	{
		while (delta_y-- > 0)
		{
			x0 += x_dir;
			y0++;
			mlx_pixel_put(draw->mlx, draw->win, (int)x0, (int)y0, set_color(start, end));
		}
		return;
	}
	double erroracc = 0;
	double erroracc_tmp = 0;
	double erroradj = 0;
	double weighting = 0;
	if (delta_y > delta_x)
	{
		erroradj = (int)delta_x << 16 / (int)delta_y;
		while (--delta_y)
		{
			erroracc_tmp = erroracc;
			erroracc += erroradj;
			if (erroracc  <= erroracc_tmp)
				x0 += x_dir;
			y0++;
			weightin
		}
	}

}*/

//		BRESENHAM LINE ALGORITHM
void draw_line_bresenham(t_point start, t_point end, t_draw *draw)
{
	double delta_x;
	double delta_y;
	double pixelcount;
	double x_pixel;
	double y_pixel;

	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	pixelcount = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	x_pixel = start.x;
	y_pixel = start.y;
	delta_x /= pixelcount;
	delta_y /= pixelcount;
	while (pixelcount > 0)
	{
		mlx_pixel_put(draw->mlx, draw->win, (int)(x_pixel), (int)(y_pixel),\
		set_color(&start, &end));
		x_pixel += delta_x;
		y_pixel += delta_y;
		pixelcount--;
	}
}


void	draw_matrix(t_map *start, t_draw *draw)
{
	if (start->right)
		draw->draw_algorithm((*start->data), (*start->right->data), draw);
	if (start->down)
		draw->draw_algorithm((*start->data), (*start->down->data), draw);
	if (start->next)
		draw_matrix(start->next, draw);
	draw->draw_algorithm((*start->data), (*start->data), draw);
	/*if (!(start->next) && !(start->down) && !(start->right))
		mlx_pixel_put(draw->mlx, draw->win, (int)(start->data->x), (int)\
		(start->data->y),set_color(start->data, start->data));*/
}