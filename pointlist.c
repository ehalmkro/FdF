/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esko <esko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:29:54 by esko              #+#    #+#             */
/*   Updated: 2019/12/19 14:50:48 by esko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point     *point_node_new(int x, int y, int z)
{
    t_point *ret;

    ret = malloc(sizeof(t_point));
    ret->x = (int)malloc(sizeof(int));
    ret->y = (int)malloc(sizeof(int));
    ret->z = (int)malloc(sizeof(int));
    ret->next = malloc(sizeof(t_point*));
    ret->x = x;
    ret->y = y;
    ret->z = z;
    ret->next = NULL;
    return(ret);
}

void        point_node_pushback(t_point **start, t_point *new)
{
    while ((*start)->next)
        *start = (*start)->next;
    (*start)->next = new;

}
