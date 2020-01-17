/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/17 18:19:00 by ehalmkro         ###   ########.fr       */
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

	set_color(start);
	set_color(end);
	delta_x = end->x - start->x;
	delta_y = end->y - start->y;
	pixelcount = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	x_pixel = start->x;
	y_pixel = start->y;
	delta_x /= pixelcount;
	delta_y /= pixelcount;
	while (pixelcount > 0)
	{
		mlx_pixel_put(mlx, win, (int)x_pixel + 100, (int)y_pixel + 100, end->color);
		x_pixel += delta_x;
		y_pixel += delta_y;
		pixelcount--;
	}
}

static void	zoom_matrix(t_map ***start, t_draw *draw)
{
	t_map *curr;

	curr = **start;

	while (curr)
	{
		printf("X: %f Y: %f Z: %f\n", curr->data->x, curr->data->y, curr->data->z);
		curr->data->x *= draw->zoom;
		curr->data->y *= draw->zoom;
		curr->data->z *= draw->zoom;
		curr = curr->next;
	}
}

void	*draw_window(void *mlx, t_map **start)
{
	void *win;
	t_draw draw;

	draw.zoom = 26;
	if ((win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF 0.01 // ehalmkro // 2020")) == NULL)
		perror("Error: ");
	mlx_clear_window(mlx, win);
	zoom_matrix (&start, &draw);
	return (win);
}
