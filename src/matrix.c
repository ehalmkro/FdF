/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:47:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/08 14:48:52 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/fdf.h"

void	zoom_matrix(t_point *data, t_point vertex, t_scene *draw, float deg)
{
	(void)vertex;
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

void	rot_z(t_point *data, t_point vertex, t_scene *draw, float deg)
{
	(void)draw;
	data->x = vertex.x * cosf(deg) - vertex.y * sinf(deg);
	data->y = vertex.x * sinf(deg) + vertex.y * cosf(deg);
}

void	rot_x(t_point *data, t_point vertex, t_scene *draw, float deg)
{
	(void)draw;
	data->y = vertex.y * cosf(deg) + vertex.z * sinf(deg);
	data->z = (-vertex.y) * sinf(deg) + vertex.z * cosf(deg);
}

void	rot_y(t_point *data, t_point vertex, t_scene *draw, float deg)
{
	(void)draw;
	data->x = vertex.x * cosf(deg) + vertex.z * sinf(deg);
	data->z = (-vertex.x) * sinf(deg) + vertex.z * cosf(deg);
}

void	matrix_transformation(t_scene *draw, void (*transformation)\
(t_point *data, t_point vertex, t_scene *draw, float deg), float deg)
{
	t_map	*map;
	t_point	*vertex;

	map = draw->map;
	while (map)
	{
		vertex = new_node(map->dt->x, map->dt->y, map->dt->z, draw);
		transformation(map->dt, *vertex, draw, deg);
		map = map->nxt;
		free(vertex);
	}
	free(map);
	scene_find_minmax(draw);
}
