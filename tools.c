/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:59:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/21 15:16:01 by ehalmkro         ###   ########.fr       */
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



void	scene_find_minmax (t_map **start, t_draw **draw)
{
	t_map *list_curr;
	t_draw *draw_curr;

	list_curr = *start;
	draw_curr = *draw;
	draw_curr->max_x = INT_MIN;
	draw_curr->max_y = INT_MIN;
	draw_curr->max_z = INT_MIN;
	draw_curr->min_z = INT_MAX;
	while (list_curr)
	{
		if (list_curr->data->x > draw_curr->max_x)
			draw_curr->max_x = list_curr->data->x;
		if (list_curr->data->y > draw_curr->max_y)
			draw_curr->max_y = list_curr->data->y;
		if (list_curr->data->z > draw_curr->max_z)
			draw_curr->max_z = list_curr->data->z;
		if (list_curr->data->z < draw_curr->min_z)
			draw_curr->min_z = list_curr->data->z;
		list_curr = list_curr->next;
	}
}
