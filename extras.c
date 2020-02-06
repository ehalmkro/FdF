/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:41:00 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/06 19:06:54 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** time.h used for bonus timer
*/

#include <time.h>

int		timer(t_scene *draw, size_t ticks, int index)
{
	if (((clock()) - draw->prev_time[index]) < ticks)
		return (1);
	draw->prev_time[index] = clock();
	return (0);
}

void	switch_color(t_scene *draw)
{
	size_t	i;
	size_t	j;
	int		*rgb;

	i = 0;
	while (i < 3)
	{
		rgb = split_color(draw->color[i]);
		j = 0;
		while (j < 3)
		{
			if (rgb[j] + draw->c_dir[i][j] < 255 && \
			rgb[j] + draw->c_dir[i][j] > 0)
				rgb[j] += draw->c_dir[i][j];
			else
			{
				draw->c_dir[i][j] *= -1;
				rgb[j] = rgb[j] == 0 ? rgb[j]++ : rgb[j] + draw->c_dir[i][j];
			}
			j++;
		}
		draw->color[i] = combine_color(rgb[0], rgb[1], rgb[2]);
		free(rgb);
		i++;
	}
}

void	change_palette(t_scene *draw)
{
	int		*rgb;
	char	random;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		rgb = split_color(draw->color[i]);
		while (j < 3)
		{
			random = rgb[j] * 25 + ((rgb[j] * 33) % 3) * 20;
			rgb[j++] = (int)random;
		}
		draw->color[i] = combine_color(rgb[0], rgb[1], rgb[2]);
		free(rgb);
		i++;
	}
}

void	text_carousel(t_scene *draw)
{
	draw->carousel == 0 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH\
	/ 2.5, 40, draw->color[3], "*** F D F ***") : 0;
	draw->carousel == 1 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH\
	/ 2.5, 40, draw->color[3], "** F D F *** ") : 0;
	draw->carousel == 2 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH\
	/ 2.5, 40, draw->color[3], "* F D F ***  ") : 0;
	draw->carousel == 3 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH\
	/ 2.5, 40, draw->color[3], " F D F *** F ") : 0;
	draw->carousel == 4 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH\
	/ 2.5, 40, draw->color[3], "F D F *** F D") : 0;
	draw->carousel == 5 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH\
	/ 2.5, 40, draw->color[3], " D F *** F D ") : 0;
	draw->carousel == 6 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH\
	/ 2.5, 40, draw->color[3], "D F *** F D F") : 0;
	draw->carousel == 7 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH\
	/ 2.5, 40, draw->color[3], " F *** F D F ") : 0;
	draw->carousel == 8 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH\
	/ 2.5, 40, draw->color[3], "F *** F D F *") : 0;
	draw->carousel == 9 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH\
	/ 2.5, 40, draw->color[3], " *** F D F **") : 0;
}

void	debug_lines(t_scene *draw)
{
	int		i;
	float	x;
	float	y;
	t_point *line;
	t_point *line2;

	x = -200;
	y = -200;
	i = 0;
	line = point_node_new(x, y, 10, draw);
	line2 = point_node_new(fabs(x * 5), fabs(y * 5), 10, draw);
	line->height = LO;
	line2->height = HI;
	while (i < 50)
	{
		draw->draw_algorithm(*line, *line2, draw);
		line2->x += 50;
		i++;
	}
	free(line);
	free(line2);
}
