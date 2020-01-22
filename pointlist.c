/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esko <esko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:29:54 by esko              #+#    #+#             */
/*   Updated: 2020/01/20 11:10:32 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map *get_next_y(t_map *start, float y)
{
	t_map *ret;

	ret = start;
	while (ret->data->y == y && ret)
		ret = ret->next;
	return(ret);
}

void	append_map(t_map **start, t_draw **draw)
{
	t_map *tapehead;
	t_map *forward;
	double y;
	double x;
	tapehead = *start;

	x = 0;
	y = 0;
	while (y < (*draw)->max_y - 1)
	{
		y = tapehead->data->y;
		forward = get_next_y (tapehead, y);
		while (x < (*draw)->max_x)
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
	(*draw)->map = *start;
}

t_point     *point_node_new(float x, float y, float z)
{
    t_point *ret;

    ret = (t_point*)malloc(sizeof(t_point));
    ret->x = x;
    ret->y = y;
    ret->z = z;
    return(ret);
}

t_map		*map_add_node(t_point *data)
{
	t_map *ret;

	ret = (t_map*)malloc(sizeof(t_map));
	ret->data = (t_point*)malloc(sizeof(t_point));
	ret->data = data;
	ret->down = NULL;
	ret->next = NULL;
	ret->right = NULL;
	return (ret);
}

void        map_push_right(t_map **start, t_map *new)
{
    t_map *curr;

    curr = *start;
    while (curr->next)
        curr = curr->next;
    curr->next = new;
}
