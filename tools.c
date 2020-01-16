/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:59:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/16 15:29:06 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
double get_percent(int start, int end, int curr)
{
	double	place;
	double	dist;

	place = curr - start;
	dist = end - start;
	if (dist == 0)
		return (1.0);
	return (place/dist);
}
*/
void	init_minmax(t_max *map)
{
	map->max_x = INT_MIN;
	map->max_y = INT_MIN;
	map->max_z = INT_MIN;
	map->min_z = INT_MAX;
}

t_max	find_minmax(t_map **start)
{
	t_map *curr;
	t_max	map;

	init_minmax(&map);
	curr = *start;
	while (curr)
	{
		if (curr->data->x > map.max_x)
			map.max_x = curr->data->x;
		if (curr->data->y > map.max_y)
			map.max_y = curr->data->y;
		if (curr->data->z > map.max_z)
			map.max_z = curr->data->z;
		if (curr->data->z < map.min_z)
			map.min_z = curr->data->z;
		curr = curr->next;
	}
	return (map);
}
