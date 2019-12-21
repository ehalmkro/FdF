/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esko <esko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:29:54 by esko              #+#    #+#             */
/*   Updated: 2019/12/20 19:51:36 by esko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point     *point_node_new(int x, int y, int z)
{
    t_point *ret;

    ret = (t_point*)malloc(sizeof(t_point));
    ret->x = x;
    ret->y = y;
    ret->z = z;
    ret->next = NULL;
    return(ret);
}

void        point_node_pushback(t_point **start, t_point *new)
{
    t_point *current;

    current = *start;
    while (current->next)
        current = current->next;
    current->next = new;
}
