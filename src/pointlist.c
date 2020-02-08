/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esko <esko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:29:54 by esko              #+#    #+#             */
/*   Updated: 2020/02/08 14:48:52 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_map	*get_next_y(t_map *start, float y)
{
	t_map	*ret;

	ret = start;
	while (ret->dt->y == y && ret)
		ret = ret->nxt;
	return (ret);
}

void			append_map(t_scene *draw)
{
	t_map	*c;
	t_map	*f;
	t_point	*point;

	c = draw->map;
	point = new_node(0, 0, 0, draw);
	while (point->y < draw->max_y - 1)
	{
		point->y = c->dt->y;
		f = get_next_y(c, point->y);
		while (point->x < draw->max_x)
		{
			point->x = c->dt->x;
			c->dn = f;
			if (point->y == c->nxt->dt->y)
			{
				c->rt = c->nxt;
				f->rt = f->nxt && f->nxt->dt->y == f->dt->y ? f->nxt : f->rt;
				f = f->nxt;
			}
			c = c->nxt;
		}
		point->x = 0;
	}
	free(point);
}

t_point			*new_node(float x, float y, float z, t_scene *draw)
{
	t_point		*ret;

	(void)draw;
	(ret = (t_point*)malloc(sizeof(t_point))) == NULL ? ft_error(0) : 0;
	ret->x = x;
	ret->y = y;
	ret->z = z;
	if (z == 0)
		ret->height = ZERO;
	else if (z > 0)
		ret->height = HI;
	else if (z < 0)
		ret->height = LO;
	return (ret);
}

t_map			*map_add_node(void *data)
{
	t_map		*ret;

	(ret = (t_map*)malloc(sizeof(t_map))) == NULL ? ft_error(0) : 0;
	ret->dt = data;
	ret->dn = NULL;
	ret->nxt = NULL;
	ret->rt = NULL;
	return (ret);
}

void			map_push_next(t_map **start, t_map *new)
{
	t_map		*curr;

	curr = *start;
	while (curr->nxt)
		curr = curr->nxt;
	curr->nxt = new;
}
