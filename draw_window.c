/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/16 18:03:01 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void draw_line(t_point *start, t_point *end, void *mlx, void *win)
{
	double delta_x;
	double delta_y;
	double pixelcount;

	printf("start X %f Y %f\n", start->x, start->y);
	printf("end X %f Y %f\n", end->x, end->y);
	delta_x = end->x - start->x;
	delta_y = end->y - start->y;
	pixelcount = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	double x_pixel;
	double y_pixel;

	x_pixel = start->x;
	y_pixel = start->y;
	delta_x /= pixelcount;
	delta_y /= pixelcount;
	while (pixelcount)
	{
		mlx_pixel_put(mlx, win, (int)x_pixel, (int)y_pixel, 0xFFFFFF);
		x_pixel += delta_x;
		y_pixel += delta_y;
		pixelcount--;
	}
}
static void	draw_2d_outline(void *mlx, void *win, t_map **start)
{

/*	t_map *curr;
	int	color;

	curr = *start;
	while (curr)
	{
		if (curr->right)
			draw_line(curr->data, curr->right->data);
		if (curr->down)
			draw_line(curr->data, curr->right->data);

	}*/


}


void	draw_window(void *mlx, t_map **start)
{
	void *win;
	t_draw draw;

	draw.zoom = 1;
	if ((win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF 0.01 // ehalmkro // 2020")) == NULL)
		perror("Error: ");
	mlx_clear_window(mlx, win);
	mlx_string_put(mlx, win, 20, 20, 0x00FF00, "THIS IS FDF");
//	draw_2d_outline(mlx, win, start);
	t_map *end;
	end = *start;
	while (end->next)
		end = end->next;
	draw_line((*start)->data, end->data, mlx, win);
	mlx_loop(mlx);
}
