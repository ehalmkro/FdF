/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:22:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/07 18:43:30 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void			put_pixel(float x, float y, int color, t_scene *draw)
{
	mlx_pixel_put(draw->mlx, draw->win, x + draw->padding_x,\
	y + draw->padding_y, color);
}

void			draw_line_bresenham(t_point start, t_point end, t_scene *draw)
{
	t_point	*delta;
	t_point	*current;
	float	pixelcount;
	t_map	*start_end;

	current = new_node(start.x, start.y, 0, draw);
	delta = new_node(end.x - start.x, end.y - start.y, 0, draw);
	pixelcount = sqrt((delta->x * delta->x) + (delta->y * delta->y));
	delta->x /= pixelcount;
	delta->y /= pixelcount;
	start_end = map_add_node(&start);
	start_end->nxt = map_add_node(&end);
	while (pixelcount > 0)
	{
		put_pixel(current->x, current->y, set_grd(start_end, *delta, \
		*current, *draw), draw);
		current->x += delta->x;
		current->y += delta->y;
		pixelcount--;
	}
	free(start_end);
	free(start_end->nxt);
	free(current);
	free(delta);
}

/*
** Does the isometric transformation vertex by vertex before drawing using
** temporary t_points to not leak memory
*/

static t_point	*transform_isometric(t_point *data, t_scene *draw)
{
	t_point		*ret;
	double		prev_x;
	double		prev_y;

	prev_x = data->x;
	prev_y = data->y;
	ret = new_node((prev_x - prev_y) * cos(0.523599), -(data->z) + \
	(prev_x + prev_y) * sin(0.523599), data->z, draw);
	ret->height = data->height;
	return (ret);
}

static void		draw_isometric(t_map *start, t_scene *draw)
{
	t_point *begin;
	t_point *end;

	if (start->rt)
	{
		begin = transform_isometric(start->dt, draw);
		end = transform_isometric(start->rt->dt, draw);
		draw->draw_algorithm(*begin, *end, draw);
		free(begin);
		free(end);
	}
	if (start->dn)
	{
		begin = transform_isometric(start->dt, draw);
		end = transform_isometric(start->dn->dt, draw);
		draw->draw_algorithm(*begin, *end, draw);
		free(begin);
		free(end);
	}
	if (start->nxt)
		draw_isometric(start->nxt, draw);
	begin = transform_isometric(start->dt, draw);
	draw->draw_algorithm(*begin, *begin, draw);
	free(begin);
}

void			draw_matrix(t_map *start, t_scene *draw)
{
	if (draw->projection == ISOMETRIC)
		draw_isometric(start, draw);
	else
	{
		if (start->rt)
			draw->draw_algorithm((*start->dt), (*start->rt->dt), draw);
		if (start->dn)
			draw->draw_algorithm((*start->dt), (*start->dn->dt), draw);
		if (start->nxt)
			draw_matrix(start->nxt, draw);
		draw->draw_algorithm((*start->dt), (*start->dt), draw);
	}
}
