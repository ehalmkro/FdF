/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:59:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/14 15:27:08 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	init_minmax(t_max *map)
{
	map->max_x = INT_MIN;
	map->max_y = INT_MIN;
	map->max_z = INT_MIN;
	map->min_z = INT_MAX;
}

t_max	find_minmax(t_point **start)
{
	t_point *curr;
	t_max	map;

	init_minmax(&map);
	curr = *start;
	while (curr)
	{
		if (curr->x > map.max_x)
			map.max_x = curr->x;
		if (curr->y > map.max_y)
			map.max_y = curr->y;
		if (curr->z > map.max_z)
			map.max_z = curr->z;
		if (curr->z < map.min_z)
			map.min_z = curr->z;
		curr = curr->next;
	}
	printf("MAXIMUM VALUES:\nx = %d\ny = %d\nz = %d\n", map.max_x, map.max_y, map.max_z);
	printf("MINIMUM VALUE:\nz = %d\n", map.min_z);

	double percentage;
	percentage = get_percent(0, 10, 5);
	printf("PERCENTAGE CHECK %f\n", percentage);
	return (map);
}