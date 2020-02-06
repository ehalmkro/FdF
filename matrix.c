/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:47:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/06 19:23:12 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

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
	data->x = vertex.x * cos(deg) - vertex.y * sin(deg);
	data->y = vertex.x * sin(deg) + vertex.y * cos(deg);
}

void	rot_x(t_point *data, t_point vertex, t_scene *draw, float deg)
{
	data->y = vertex.y * cos(deg) + vertex.z * sin(deg);
	data->z = (-vertex.y) * sin(deg) + vertex.z * cos(deg);
}

void	rot_y(t_point *data, t_point vertex, t_scene *draw, float deg)
{
	data->x = vertex.x * cos(deg) + vertex.z * sin(deg);
	data->z = (-vertex.x) * sin(deg) + vertex.z * cos(deg);
}

void	matrix_transformation(t_scene *draw, void (*transformation)\
(t_point *data, t_point vertex, t_scene *draw, float deg), float deg)
{
	t_map	*map;
	t_point	*vertex;

	map = draw->map;
	while (map)
	{
		vertex = point_node_new(map->dt->x, map->dt->y, map->dt->z, draw);
		transformation(map->dt, *vertex, draw, deg);
		map = map->nxt;
		free(vertex);
	}
	free(map);
	scene_find_minmax(draw);
}
