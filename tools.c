/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:59:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/31 15:05:27 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_percent(int start, int end, int curr)
{
	double	place;
	double	dist;

	place = curr - start;
	dist = end - start;
	if (dist == 0)
		return (1.0);
	return (place/dist);
}

//TODO: fix z axis centering

void	center_origo(t_scene *draw)
{
	t_map *map;

	map = draw->map;
	while (map)
	{
		map->data->x -= draw->max_x / 2;
		map->data->y -= draw->max_y / 2;
		map->data->z -= (draw->max_z - draw->min_z) / 2;
		map = map->next;
	}
	scene_find_minmax(draw);
}

void	scene_find_minmax (t_scene *draw)
{
	t_map *map;
 	map = draw->map;


 	if (map)
	{
		draw->max_x = INT_MIN;
		draw->max_y = INT_MIN;
		draw->max_z = INT_MIN;
		draw->min_z = INT_MAX;
		while (map)
		{
			map->data->x > draw->max_x ? draw->max_x = map->data->x : 0;
			map->data->y > draw->max_y ? draw->max_y = map->data->y : 0;
			map->data->z > draw->max_z ? draw->max_z = map->data->z : 0;
			map->data->z < draw->min_z ? draw->min_z = map->data->z : 0;
			map = map->next;
		}
	}
}

void		ft_error(int error_code)
{
	error_code == 0 ? ft_putendl("Malloc error, exiting.\n") : 0;
	error_code == 1 ? ft_putendl("Error creating new window, exiting.\n") : 0;
	error_code == 2 ? ft_putendl("Read error, exiting.\n") : 0;
	error_code == 3 ? ft_putendl("Error initializing MLX, exiting.\n") : 0;
	exit(1);
}
