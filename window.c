/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/20 13:22:44 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_matrix(t_map **start, t_draw **draw)
{
	t_map *list_curr;
	t_draw *draw_curr;

	list_curr = *start;
	draw_curr = *draw;
	while (list_curr)
	{
		printf("X: %f Y: %f Z: %f\n", list_curr->data->x, list_curr->data->y, list_curr->data->z);
		list_curr->data->x *= draw_curr->zoom;
		list_curr->data->y *= draw_curr->zoom;
		list_curr->data->z *= draw_curr->zoom;
		list_curr = list_curr->next;
	}
}

void	*draw_window(t_draw **draw)
{
	t_draw *draw_curr;

	draw_curr = *draw;

	mlx_clear_window(draw_curr->mlx, draw_curr->win);
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 20, 0x00FF00, "X");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 60, 0x00FF00, "Y");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 40, 20, 0x00FF00, ft_itoa((int)draw_curr->max_x));
	mlx_string_put(draw_curr->mlx, draw_curr->win, 40, 60, 0x00FF00, ft_itoa((int)draw_curr->max_y));
}