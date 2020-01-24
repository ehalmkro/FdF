/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:47:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/24 11:57:09 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"


void	modify_z(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw)
{
	(void)prev_x;
	(void)prev_y;
	(void)prev_z;
	(draw->padding_z == 1 && data->z != 0) ? data->z += Z_INCREASE : 0;
	(draw->padding_z == -1 && data->z != 0) ? data->z -= Z_INCREASE : 0;
}

void	center_map(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw)
{

	double increment_x;
	double increment_y;

	(void)prev_x;
	(void)prev_y;
	(void)prev_z;
	increment_x = 0;
	increment_y = 0;

	if (draw->max_x / 2 + increment_x < WINDOW_WIDTH/2)
	{
		while ((draw->max_x / 2) + increment_x < WINDOW_WIDTH/2)
			increment_x++;
		data->x += increment_x;
	}
	if (draw->max_y / 2 + increment_y< WINDOW_HEIGHT/2)
	{
		while ((draw->max_y / 2) + increment_y < WINDOW_HEIGHT / 2)
			increment_y++;
		data->y += increment_y;
	}
}

void	move_matrix_pos(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw)
{
	(void)prev_x;
	(void)prev_y;
	(void)prev_z;
	(draw->padding_x == 1) ? data->x += DEFAULT_INCREMENT : 0;
	(draw->padding_x == -1) ? data->x -= DEFAULT_INCREMENT : 0;
	(draw->padding_y == 1) ? data->y += DEFAULT_INCREMENT : 0;
	(draw->padding_y == -1) ? data->y -= DEFAULT_INCREMENT : 0;
	(draw->padding_z == 1) ? data->z += DEFAULT_INCREMENT : 0;
	(draw->padding_z == -1) ? data->z -= DEFAULT_INCREMENT : 0;
}

void	zoom_matrix(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw)
{
	(void)prev_x;
	(void)prev_y;
	(void)prev_z;
	if (draw->zoom > 0)
	{
		printf ("X: %f Y: %f Z: %f\n", data->x, data->y, data->z);
		data->x *= draw->zoom;
		data->y *= draw->zoom;
		data->z *= draw->zoom;
	}
}

void	rotate_z(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw)
{
	(void)prev_z;
	(void)draw;
	data->x = prev_x * cos (MATRIX_ROTATION_DEG) - prev_y * sin (MATRIX_ROTATION_DEG);
	data->y = prev_x * sin (MATRIX_ROTATION_DEG) + prev_y * cos (MATRIX_ROTATION_DEG);
}


void transform_isometric(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw)
{
	(void)draw;
	(void)prev_z;
	data->x = (prev_x - prev_y) * cos (0.523599);
	data->y = -(data->z) + (prev_x + prev_y) * sin (0.523599);
}

void	matrix_transformation(t_scene *draw, void (*transformation)(t_point *data, double prev_x,\
		double prev_y, double prev_z, t_scene *draw))
{
	t_map *map;
	double prev_x;
	double prev_y;
	double prev_z;
	map = draw->map;
	while (map)
	{
		prev_x = map->data->x;
		prev_y = map->data->y;
		prev_z = map->data->z;
		transformation(map->data, prev_x, prev_y, prev_z, draw);
		map = map->next;
	}
	scene_find_minmax(draw);
}