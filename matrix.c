/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:47:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/06 17:51:02 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	switch_color(t_scene *draw)
{
	size_t i;
	size_t j;
	int *rgb;

	i = 0;

	while (i < 3)
	{
		rgb = split_color(draw->color[i]);
		j = 0;
		while (j < 3)
		{
			if (rgb[j] + draw->c_dir[i][j] < 255 && rgb[j] + draw->c_dir[i][j] > 0)
				rgb[j] += draw->c_dir[i][j];
			else
			{
				draw->c_dir[i][j] *= -1;
				rgb[j] = rgb[j] == 0 ? rgb[j]++ : rgb[j] + draw->c_dir[i][j];
			}
			j++;
		}
		draw->color[i] = combine_color(rgb[0], rgb[1], rgb[2]);
		free(rgb);
		i++;
	}
}

void	zoom_matrix(t_point *data, float prev_x, float prev_y, float prev_z, t_scene *draw, float deg)
{
	(void)prev_x;
	(void)prev_y;
	(void)prev_z;
	if (deg == 0)
	{
		data->x *= draw->zoom;
		data->y *= draw->zoom;
		data->z *= draw->zoom;
	}
	else if (deg == 1 || deg == -1)
	{
		deg == -1 ? data->x *= ZOOM_COEFF_NEG : 0;
		deg == -1 ? data->y *= ZOOM_COEFF_NEG : 0;
		deg == -1 ? data->z *= ZOOM_COEFF_NEG : 0;
		deg == 1 ? data->x *= ZOOM_COEFF_POS : 0;
		deg == 1 ? data->y *= ZOOM_COEFF_POS : 0;
		deg == 1 ? data->z *= ZOOM_COEFF_POS : 0;
	}
}

void	rotate_z(t_point *data, float prev_x, float prev_y, float prev_z, t_scene *draw, float deg)
{
	(void)prev_z;
	(void)draw;
	data->x = prev_x * cos (deg) - prev_y * sin (deg);
	data->y = prev_x * sin (deg) + prev_y * cos (deg);
}

void	rotate_x(t_point *data, float prev_x, float prev_y, float prev_z, t_scene *draw, float deg)
{
	(void)prev_x;
	(void)draw;
	data->y = prev_y * cos(deg) + prev_z * sin(deg);
	data->z = (-prev_y) * sin(deg) + prev_z * cos(deg);
}

void	rotate_y(t_point *data, float prev_x, float prev_y, float prev_z, t_scene *draw, float deg)
{
	(void)prev_y;
	(void)draw;
	data->x = prev_x * cos(deg) + prev_z * sin(deg);
	data->z = (-prev_x) * sin(deg) + prev_z * cos(deg);
}


t_point *transform_isometric(t_point *data, t_scene *draw)
{
	t_point *ret;
	double prev_x;
	double prev_y;

	prev_x = data->x;
	prev_y = data->y;
	ret = point_node_new((prev_x - prev_y) * cos (0.523599), -(data->z) + (prev_x + prev_y) * sin (0.523599), data->z, draw);
	ret->height = data->height;
	return (ret);
}

void	matrix_transformation(t_scene *draw, void (*transformation)(t_point *data, float prev_x,\
		float prev_y, float prev_z, t_scene *draw, float deg), float deg)
{
	t_map *map;
	double prev_x;
	double prev_y;
	double prev_z;
	map = draw->map;
	while (map)
	{
		prev_x = map->dt->x;
		prev_y = map->dt->y;
		prev_z = map->dt->z;
		transformation(map->dt, prev_x, prev_y, prev_z, draw, deg);
		map = map->nxt;
	}
	free(map);
	scene_find_minmax(draw);
}