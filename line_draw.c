/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:22:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/20 12:55:44 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_point *start, t_point *end, void *mlx, void *win)
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
		mlx_pixel_put(mlx, win, (int)x_pixel , (int)y_pixel + 200, set_color(start, end));
		x_pixel += delta_x;
		y_pixel += delta_y;
		pixelcount--;
	}
}

void	draw_matrix(t_map *start, t_draw *draw)
{
	if (start->right)
		draw_line (start->data, start->right->data, draw->mlx, draw->win);
	if (start->down)
		draw_line (start->data, start->down->data, draw->mlx, draw->win);
	if (start->next)
		draw_matrix (start->next, draw);
	if (!(start->next) && !(start->down) && !(start->right))
		mlx_pixel_put(draw->mlx, draw->win, (int)start->data->x + 100, (int)start->data->y + 100, set_color(start->data, start->data));
}