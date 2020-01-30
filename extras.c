/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:41:00 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/30 17:11:26 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>

static void		delay(unsigned int number_of_seconds)
{
	unsigned int ret_time;

	ret_time = time(0) + number_of_seconds;
	while (time(0) < ret_time);
}

void 			text_carousel(t_scene *draw)
{
	draw->carousel == 0 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "*** F D F ***") : 0;
	draw->carousel == 1 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "** F D F *** ") : 0;
	draw->carousel == 2 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "* F D F ***  ") : 0;
	draw->carousel == 3 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], " F D F *** F ") : 0;
	draw->carousel == 4 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "F D F *** F D") : 0;
	draw->carousel == 5 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], " D F *** F D ") : 0;
	draw->carousel == 6 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "D F *** F D F") : 0;
	draw->carousel == 7 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], " F *** F D F ") : 0;
	draw->carousel == 8 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "F *** F D F *") : 0;
	draw->carousel == 9 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], " *** F D F **") : 0;
	draw->carousel == 9 ? draw->carousel = 0 : draw->carousel++;
}

void		debug_lines(t_scene *draw)
{
		int i;
		float x;
		float y;

		x = 10;
		y = 10;
		i = 0;
		t_point *line = point_node_new (x, y, 10, draw);
		t_point *line2 = point_node_new (x * 5, y * 5, 10, draw);
		line->height = LO;
		line2->height = LO;
		while (i < 15)
		{
			draw->draw_algorithm(*line, *line2, draw);
			line2->x += 50;
			i++;
		}
		i = 0;
		line2->x = 50;
		while (i < 15)
		{
			draw->draw_algorithm(*line, *line2, draw);
			line2->x -= 50;
			i++;
		}
		free(line);
		free(line2);
}