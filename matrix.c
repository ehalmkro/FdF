/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:47:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/28 12:52:24 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	switch_color(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg)
{
	int *rgb;
	(void)prev_x;
	(void)prev_y;
	(void)prev_z;
	(void)deg;
	compound_calc(draw);
	if (draw->calc % 5333 == 0)
		{
		rgb = split_color(draw->color[0]);
		draw->color[0] = combine_color(rgb[0] + 1, rgb[1] + 1, rgb[2] + 1);
		rgb = split_color(draw->color[1]);
		draw->color[1] = combine_color(rgb[0] + 1, rgb[1] + 1, rgb[2] + 1);
		rgb = split_color(draw->color[2]);
		draw->color[2] = combine_color(rgb[0] + 1, rgb[1] + 1, rgb[2] + 1);
		}
}


// TODO: FIX Z INCREASE
void	modify_z(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg)
{
	(void)prev_x;
	(void)prev_y;
	(void)deg;
	(void)prev_z;
	(draw->padding_z == 1 && data->z != 0) ? data->z += Z_INCREASE : 0;
	(draw->padding_z == -1 && data->z != 0) ? data->z -= Z_INCREASE : 0;

}

void	zoom_matrix(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg)
{
	(void)prev_x;
	(void)prev_y;
	(void)prev_z;
	(void)deg;
	if (draw->zoom > 0)
	{
		printf ("X: %f Y: %f Z: %f\n", data->x, data->y, data->z);
		data->x *= draw->zoom;
		data->y *= draw->zoom;
		data->z *= draw->zoom;
	}
}

void	rotate_z(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg)
{
	(void)prev_z;
	(void)draw;
	data->x = prev_x * cos (deg) - prev_y * sin (deg);
	data->y = prev_x * sin (deg) + prev_y * cos (deg);
}

void	rotate_x(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg)
{
	(void)prev_x;
	(void)draw;
	data->y = prev_y * cos(deg) + prev_z * sin(deg);
	data->z = (-prev_y) * sin(deg) + prev_z * cos(deg);
}

void	rotate_y(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg)
{
	(void)prev_y;
	(void)draw;
	data->x = prev_x * cos(deg) + prev_z * sin(deg);
	data->z = (-prev_x) * sin(deg) + prev_z * cos(deg);
}

// OLD VERSION USING MATRIX_TRANSFORMATION AS PARENT
/*void transform_isometric(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg)
{
	(void)draw;
	(void)deg;
	(void)prev_z;
	data->x = (prev_x - prev_y) * cos (0.523599);
	data->y = -(data->z) + (prev_x + prev_y) * sin (0.523599);
}*/

t_point *transform_isometric(t_point *data, t_scene *draw)
{
	t_point *ret;
	float prev_x;
	float prev_y;

	prev_x = data->x;
	prev_y = data->y;
	ret = point_node_new((prev_x - prev_y) * cos (0.523599), -(data->z) + (prev_x + prev_y) * sin (0.523599), data->z, draw);
	ret->height = data->height;
	return (ret);
}

void	matrix_transformation(t_scene *draw, void (*transformation)(t_point *data, double prev_x,\
		double prev_y, double prev_z, t_scene *draw, double deg), double deg)
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
		transformation(map->data, prev_x, prev_y, prev_z, draw, deg);
		map = map->next;
	}
	scene_find_minmax(draw);
}