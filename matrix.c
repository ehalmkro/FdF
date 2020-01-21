/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:47:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/21 16:33:03 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	move_matrix_pos(t_draw **draw)
{
	t_map *map;

	map = (*draw)->map;
	while (map)
	{
		((*draw)->padding_x == 1) ? map->data->x += DEFAULT_INCREMENT : 0;
		((*draw)->padding_x == -1) ? map->data->x -= DEFAULT_INCREMENT : 0;
		((*draw)->padding_y == 1) ? map->data->y += DEFAULT_INCREMENT : 0;
		((*draw)->padding_y == -1) ? map->data->y -= DEFAULT_INCREMENT : 0;
		((*draw)->padding_z == 1) ? map->data->z += DEFAULT_INCREMENT : 0;
		((*draw)->padding_z == -1) ? map->data->z -= DEFAULT_INCREMENT : 0;
		map = map->next;
	}
	(*draw)->padding_x = 0;
	(*draw)->padding_y = 0;
	(*draw)->padding_z = 0;
}

void	zoom_matrix(t_draw **draw)
{
	t_map *map;

	map = (*draw)->map;
	while (map && (*draw)->zoom > 0)
	{
		printf ("X: %f Y: %f Z: %f\n", map->data->x, map->data->y, map->data->z);
		map->data->x *= (*draw)->zoom;
		map->data->y *= (*draw)->zoom;
//		map->data->z *= (*draw)->zoom;
		map = map->next;
	}
}

void	rotate_2d(t_draw *draw)
{
	t_map *matrix;
	double prev_y;
	double prev_x;

	matrix = draw->map;
	while (matrix)
	{
		prev_y = matrix->data->y;
		prev_x = matrix->data->x;
		matrix->data->x = prev_x * cos(MATRIX_ROTATION_DEG) - prev_y * sin(MATRIX_ROTATION_DEG);
		matrix->data->y = prev_x * sin(MATRIX_ROTATION_DEG) + prev_y * cos(MATRIX_ROTATION_DEG);
		matrix = matrix->next;
	}
}