/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/15 19:28:53 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void	draw_2d_outline(void *mlx, void *win, t_point **start)
{
	t_point *curr;
	int	color;

	curr = *start;
	while (curr)
	{
		if (curr->z != 0)
			color = 0x800080;
		else
			color = 0x008080;
		mlx_pixel_put(mlx, win, 500 + curr->x, 500 + curr->y, color);
		curr = curr->next;
	}
}


void	draw_window(void *mlx, t_point **start)
{
	void *win;
	t_draw draw;

	draw.zoom = 1;
	if ((win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF 0.01 // ehalmkro // 2020")) == NULL)
		perror("Error: ");
	mlx_clear_window(mlx, win);
	mlx_string_put(mlx, win, 20, 20, 0x00FF00, "THIS IS FDF");
	draw_2d_outline(mlx, win, start);
	mlx_loop(mlx);
}*/
