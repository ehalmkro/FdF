/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:31:14 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/08 14:48:52 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "math.h"

static void		free_wu(t_map *curr_pxl, t_map *start_end, t_line *line)
{
	free(curr_pxl->dt);
	free(curr_pxl->nxt->dt);
	free(curr_pxl->nxt);
	free(curr_pxl);
	free(start_end->nxt);
	free(start_end);
	free(line->delta);
	free(line);
}

static void		loop_wu(t_map *curr_pxl, t_line *line, t_map *start_end, \
t_scene *draw)
{
	int x;
	int y;

	while (curr_pxl->dt->x < curr_pxl->nxt->dt->x)
	{
		x = line->steep == 1 ? (int)(line->y_isct) : curr_pxl->dt->x;
		y = line->steep == 0 ? (int)(line->y_isct) : curr_pxl->dt->x;
		put_pixel(x, y, set_light(set_grd(start_end, *line->delta, \
		*curr_pxl->dt, *draw), offset_part(line->y_isct)), draw);
		line->steep == 1 ? x++ : y++;
		put_pixel(x, y, set_light(set_grd(start_end, *line->delta,\
		*curr_pxl->dt, *draw), decimal_part(line->y_isct)), draw);
		line->y_isct += line->gradient;
		curr_pxl->dt->x++;
	}
}

static void		draw_endpoint_wu(t_map *curr_pxl, t_map *start_end, \
t_line *line, t_scene *draw)
{
	if (line->steep == 1)
	{
		put_pixel(curr_pxl->dt->y, curr_pxl->dt->x,\
		set_light(set_grd(start_end, *line->delta, *curr_pxl->dt, *draw), \
		offset_part(line->y_end) * line->x_gap), draw);
		put_pixel(curr_pxl->dt->y + 1, curr_pxl->dt->x,
		set_light(set_grd(start_end, *line->delta, *curr_pxl->dt, *draw),\
		decimal_part(line->y_end) * line->x_gap), draw);
	}
	else
	{
		put_pixel(curr_pxl->dt->x, curr_pxl->dt->y, set_light(set_grd\
(start_end, *line->delta, *curr_pxl->dt, *draw), offset_part(line->y_end) * \
		line->x_gap), draw);
		put_pixel(curr_pxl->dt->x, curr_pxl->dt->y + 1, set_light(set_grd\
(start_end, *line->delta, *curr_pxl->dt, *draw), offset_part(line->y_end) * \
		line->x_gap), draw);
	}
}

static t_line	*init_wu(t_point *start, t_point *end, t_scene *draw)
{
	t_line *line;

	((line = (t_line*)malloc(sizeof(t_line))) == NULL) ? ft_error(0) : 0;
	line->steep = fabs(end->y - start->y) > fabs(end->x - start->x) ? 1 : 0;
	if (line->steep == 1 || start->x > end->x)
		endpoint_swap(start, end, line);
	line->delta = new_node(end->x - start->x, end->y - start->y, 0, draw);
	line->gradient = line->delta->y / line->delta->x;
	line->delta->x == 0.0 ? line->gradient = 1.0 : 0;
	line->x_end = round(start->x);
	line->y_end = start->y + line->gradient * (line->x_end - start->x);
	line->x_gap = offset_part(start->x + 0.5);
	return (line);
}

void			draw_line_wu(t_point start, t_point end, t_scene *draw)
{
	t_map		*pxl;
	t_map		*start_end;
	t_line		*line;

	line = init_wu(&start, &end, draw);
	start_end = map_add_node(&start);
	start_end->nxt = map_add_node(&end);
	pxl = map_add_node(new_node(line->x_end, (int)(line->y_end), 0, draw));
	draw_endpoint_wu(pxl, start_end, line, draw);
	line->y_isct = line->y_end + line->gradient;
	line->x_end = round(end.x);
	line->y_end = end.y + line->gradient * (line->x_end - end.x);
	line->x_gap = decimal_part(end.x + 0.5);
	pxl->nxt = map_add_node(new_node(line->x_end, (int)(line->y_end), 0, \
	draw));
	draw_endpoint_wu(pxl->nxt, start_end, line, draw);
	loop_wu(pxl, line, start_end, draw);
	free_wu(pxl, start_end, line);
}
