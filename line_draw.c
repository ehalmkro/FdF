/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:22:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/21 16:38:46 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// TODO: IMPLEMENT XIAOLIN WU LINE ALGORITHM

/*
void	draw_line(t_point *start, t_point *end, t_draw *draw)
{
	double delta_x;
	double delta_y;
	double x0;
	double x1;
	double y0;
	double y1;
	double gradient;
	int steep;
	float intery;

	x0 = start->x;
	x1 = end->x;
	y0 = start->y;
	y1 = end->y;
	steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep)
	{
		ft_swap(&x0, &y0);
		ft_swap(&x1, &y1);
	}
	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);

	}
	delta_x = (x1 - x0);
	delta_y = (y1 - y0);
	gradient = delta_y/delta_x;
	if (delta_x == 0.0)
		gradient = 1;
	double xend = round(x0);
	double yend = y0 + gradient * (xend - x0);
	double xgap = rfpart_(x0 + 0.5);
	double xplx1 = xend;
	double yplx1 = ipart_(yend);
	if (steep)
	{
		mlx_pixel_put (draw->mlx, draw->win, yplx1, xplx1, decrease_brightness(draw->map->data->color,\
		rfpart_(yend) * xgap));
		mlx_pixel_put (draw->mlx, draw->win,yplx1 + 1, xplx1, decrease_brightness(draw->map->data->color,\
		fpart_(yend) * xgap));
	}
	else
	{
		mlx_pixel_put (draw->mlx, draw->win, xplx1, yplx1, decrease_brightness (draw->map->data->color,\
		rfpart_(yend) * xgap));
		mlx_pixel_put (draw->mlx, draw->win, xplx1, yplx1 + 1, decrease_brightness (draw->map->data->color,\
		fpart_(yend) * xgap));
	}

	intery = yend + gradient;
	xend = round_(x1);
	yend = y1 + gradient * (xend - x1);
	xgap = fpart_(x1 + 0.5);
	double xplx2 = xend;
	double yplx2 = ipart_(yend);
	if (steep)
	{
		mlx_pixel_put (draw->mlx, draw->win, yplx2, xplx2, decrease_brightness (draw->map->data->color,\
		rfpart_(yend) * xgap));
		mlx_pixel_put (draw->mlx, draw->win, yplx2 + 1, xplx2, decrease_brightness (draw->map->data->color,\
		rfpart_(yend) * xgap));
	}
	else
	{
		mlx_pixel_put (draw->mlx, draw->win, xplx2, yplx2, decrease_brightness (draw->map->data->color,\
		rfpart_(yend) * xgap));
		mlx_pixel_put (draw->mlx, draw->win, xplx2, yplx2 + 1, decrease_brightness (draw->map->data->color,\
		rfpart_(yend) * xgap));
	}


	// MAIN LOOP
	int x = xplx1;
	if (steep)
	{
		while (x <= xplx2)
		{
			mlx_pixel_put(draw->mlx, draw->win, ipart_(intery), x, rfpart_(intery));
			mlx_pixel_put(draw->mlx, draw->win, ipart_(intery) + 1, x, rfpart_(intery));
			x++;
		}
	}
	else
	{
		while (x <= xplx2)
		{
			mlx_pixel_put(draw->mlx, draw->win, ipart_(intery), x, rfpart_(intery));
			mlx_pixel_put(draw->mlx, draw->win, ipart_(intery) + 1, x, rfpart_(intery));
			x++;
		}
	}
}
*/

//		BRESENHAM LINE ALGORITHM
void draw_line(t_point *start, t_point *end, t_draw *draw)
{
	double delta_x;
	double delta_y;
	double pixelcount;
	double x_pixel;
	double y_pixel;

	delta_x = end->x - start->x;
	delta_y = end->y - start->y;
	pixelcount = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	x_pixel = start->x;
	y_pixel = start->y;
	delta_x /= pixelcount;
	delta_y /= pixelcount;
	while (pixelcount > 0)
	{
		mlx_pixel_put(draw->mlx, draw->win, (int)(x_pixel), (int)(y_pixel),\
		set_color(start, end));
		x_pixel += delta_x;
		y_pixel += delta_y;
		pixelcount--;
	}
}



void	draw_matrix(t_map *start, t_draw *draw)
{
	if (start->right)
		draw_line (start->data, start->right->data, draw);
	if (start->down)
		draw_line (start->data, start->down->data, draw);
	if (start->next)
		draw_matrix (start->next, draw);
	if (!(start->next) && !(start->down) && !(start->right))
		mlx_pixel_put(draw->mlx, draw->win, (int)(start->data->x), (int)\
		(start->data->y), set_color(start->data, start->data));
}