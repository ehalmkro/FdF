/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/20 18:40:29 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_matrix(t_draw **draw)
{
	t_map *map;

	map = (*draw)->map;
	while (map && (*draw)->zoom > 0)
	{
		printf ("X: %f Y: %f Z: %f\n", map->data->x, map->data->y, map->data->z);
		map->data->x *= (*draw)->zoom;
		map->data->y *= (*draw)->zoom;
		map->data->z *= (*draw)->zoom;
		map = map->next;
	}
}


void	*draw_window(t_draw **draw)
{
	t_draw *draw_curr;

	draw_curr = *draw;

	mlx_clear_window(draw_curr->mlx, draw_curr->win);
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 20, 0x00FF00, "X max");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 40, 0x00FF00, "Y max");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 60, 0x00FF00, "Z max");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 20, 0x00FF00, ft_itoa((int)draw_curr->max_x));
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 40, 0x00FF00, ft_itoa((int)draw_curr->max_y));
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 60, 0x00FF00, ft_itoa((int)draw_curr->max_z));
}
