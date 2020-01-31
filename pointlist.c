/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esko <esko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:29:54 by esko              #+#    #+#             */
/*   Updated: 2020/01/31 17:22:15 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static		t_map *get_next_y(t_map *start, float y)
{
	t_map *ret;

	ret = start;
	while (ret->data->y == y && ret)
		ret = ret->next;
	return(ret);
}

void		append_map(t_scene *draw)
{
	t_map *tapehead;
	t_map *forward;
	double y;
	double x;
	tapehead = draw->map;

	x = 0;
	y = 0;
	while (y < draw->max_y - 1)
	{
		y = tapehead->data->y;
		forward = get_next_y (tapehead, y);
		while (x < draw->max_x)
		{
			x = tapehead->data->x;
			tapehead->down = forward;
			if (y == tapehead->next->data->y)
			{
				tapehead->right = tapehead->next;
				if (forward->next && forward->next->data->y == forward->data->y)
					forward->right = forward->next;
				forward = forward->next;
			}
			tapehead = tapehead->next;
		}
		x = 0;
	}
}

t_point 	*point_node_new(float x, float y, float z, t_scene *draw)
{
	t_point *ret;

	ret = (t_point*)malloc(sizeof(t_point));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	if (z == 0)
		ret->height = ZERO;
	else if (z > 0)
		ret->height = HI;
	else if (z < 0)
		ret->height = LO;
	return(ret);
}

t_map		*map_add_node(void *data)
{
	t_map *ret;

	ret = (t_map*)malloc(sizeof(t_map));
	ret->data = data;
	ret->down = NULL;
	ret->next = NULL;
	ret->right = NULL;
	return (ret);
}

void		map_push_right(t_map **start, t_map *new)
{
	t_map *curr;

	curr = *start;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}
