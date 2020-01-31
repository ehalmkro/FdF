/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:22:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/31 15:04:48 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	put_pixel(float x, float y, int color, t_scene *draw)
{
	mlx_pixel_put(draw->mlx, draw->win, x + draw->padding_x, y + draw->padding_y, color);
}
//		BRESENHAM LINE ALGORITHM

void draw_line_bresenham(t_point start, t_point end, t_scene *draw)
{
	t_point *delta;
	t_point *current;
	double pixelcount;

	current = point_node_new(start.x, start.y, 0, draw);
	delta = point_node_new(end.x - start.x,  end.y - start.y, 0, draw);
	pixelcount = sqrt((delta->x * delta->x) + (delta->y * delta->y));
	delta->x /= pixelcount;
	delta->y /= pixelcount;
	while (pixelcount > 0)
	{
		put_pixel(current->x, current->y, set_color(start, end, *delta, *current, *draw), draw);
		current->x += delta->x;
		current->y += delta->y;
		pixelcount--;
	}
	free(current);
	free(delta);
}

/*
 * Does the isometric transformation vertex by vertex with temporary t_points to not leak memory
 */

static void 	draw_isometric(t_map *start, t_scene *draw)
{
	t_point *begin;
	t_point *end;
	if (start->right)
	{
		begin = transform_isometric(start->data, draw);
		end = transform_isometric(start->right->data, draw);
		draw->draw_algorithm(*begin, *end, draw);
		free(begin);
		free(end);
	}
	if (start->down)
	{
		begin = transform_isometric(start->data, draw);
		end = transform_isometric (start->down->data, draw);
		draw->draw_algorithm(*begin, *end, draw);
		free(begin);
		free(end);
	}
	if (start->next)
		draw_isometric(start->next, draw);
	begin = transform_isometric(start->data, draw);
	draw->draw_algorithm(*begin ,*begin, draw);
	free(begin);
}

void	draw_matrix(t_map *start, t_scene *draw)
{
	if (draw->projection == ISOMETRIC)
		draw_isometric (start, draw);
	else
	{
		if (start->right)
			draw->draw_algorithm ((*start->data), (*start->right->data), draw);
		if (start->down)
			draw->draw_algorithm ((*start->data), (*start->down->data), draw);
		if (start->next)
			draw_matrix (start->next, draw);
		draw->draw_algorithm ((*start->data), (*start->data), draw);
	}
}