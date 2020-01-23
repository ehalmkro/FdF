/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:47:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/23 15:23:29 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	modify_z(t_draw **draw)
{
	t_map *map;

	map = (*draw)->map;
	while (map)
	{
		if ((*draw)->padding_z == 1)
		{
			if (map->data->z != 0)
				map->data->z += Z_INCREASE;
		}
		if ((*draw)->padding_z == -1)
		{
			if (map->data->z != 0)
				map->data->z -= Z_INCREASE;
		}
		map = map->next;
	}
	(*draw)->padding_z = 0;

}

void	center_map(t_draw **draw)
{
	t_map *map;
	double increment_x;
	double increment_y;

	map = (*draw)->map;
	increment_x = WINDOW_WIDTH/3 - map->data->x;
	increment_y = WINDOW_HEIGHT/3 - map->data->y;
	while (map)
	{
		map->data->x += increment_x;
		map->data->y += increment_y;
		map = map->next;
	}
}

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
		map->data->z *= (*draw)->zoom;
		map = map->next;
	}
}

void	rotate_z(t_draw *draw)
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


void transform_isometric(t_draw **draw)
{
	t_map *map;
	double previous_x;
	double previous_y;

	map = (*draw)->map;
	while (map)
	{
		previous_x = map->data->x;
		previous_y = map->data->y;
		map->data->x = (previous_x - previous_y) * cos (0.523599);
		map->data->y = -(map->data->z) + (previous_x + previous_y) * sin (0.523599);
		map = map->next;
	}
}

void	matrix_transformations(void (*transformation)(t_point start, t_point end, t_draw *draw)
{

}