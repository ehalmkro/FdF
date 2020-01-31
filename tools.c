/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:59:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/31 19:21:45 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float get_percent(int start, int end, int curr)
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
		map->dt->x -= draw->max_x / 2;
		map->dt->y -= draw->max_y / 2;
		map->dt->z -= (draw->max_z - draw->min_z) / 2;
		map = map->nxt;
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
			map->dt->x > draw->max_x ? draw->max_x = map->dt->x : 0;
			map->dt->y > draw->max_y ? draw->max_y = map->dt->y : 0;
			map->dt->z > draw->max_z ? draw->max_z = map->dt->z : 0;
			map->dt->z < draw->min_z ? draw->min_z = map->dt->z : 0;
			map = map->nxt;
		}
	}
}

void		ft_error(int error_code)
{
	error_code == 0 ? ft_putendl("Malloc error, exiting...") : 0;
	error_code == 1 ? ft_putendl("Error creating new window, exiting...") : 0;
	error_code == 2 ? ft_putendl("Read error, exiting...") : 0;
	error_code == 3 ? ft_putendl("Error initializing MLX, exiting...") : 0;
	error_code == 4 ? ft_putendl("Invalid map, exiting...") : 0;
	exit(1);
}
