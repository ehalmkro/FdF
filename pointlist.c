/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esko <esko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:29:54 by esko              #+#    #+#             */
/*   Updated: 2020/01/15 21:18:40 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		map_add_next(t_map **start)
{
	t_map *curr;
	t_map *forward;

	curr = *start;
	forward = (*start)->down;

		while (curr->right != NULL)
			curr = curr->right;
		curr->right = forward;

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
	ret->right = NULL;
	ret->next = NULL;
	return (ret);
}

void        map_push_right(t_map **start, t_map *new)
{
    t_map *curr;

    curr = *start;
    while (curr->right)
        curr = curr->right;
    curr->right = new;
//	printf("DATA\nX %f\nY %f\n", new->data->x, new->data->y);
}
