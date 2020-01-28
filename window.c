/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/28 10:43:51 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO: Make function for full string output

static void		set_window_text(char *str, int x, t_scene *draw)
{
	char **words;
	int i;
	int y;
	int padding;

	i = 0;
	y = 20;
	words = ft_strsplit(str, '\n');
	while(words[i])
	{
		mlx_string_put(draw->mlx, draw->win, x, y, draw->color[0], words[i++]);
		y += 20;
	}

}

void			*draw_window(t_scene **draw)
{
	t_scene *draw_curr;

	draw_curr = *draw;

	mlx_clear_window(draw_curr->mlx, draw_curr->win);
	set_window_text("X max:\nY max:\nZ max:\n", 20, *draw);
	if ((*draw)->draw_algorithm == &draw_line_bresenham)
		set_window_text("Line algorithm:\nBresenham", 850, *draw);
	else if ((*draw)->draw_algorithm == &draw_line_wu_alternate)
		set_window_text("Line algorithm:\nXiaolin Wu", 850, *draw);
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 20, draw_curr->color[2], ft_itoa((int)draw_curr->max_x + 1));
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 40, draw_curr->color[2], ft_itoa((int)draw_curr->max_y + 1));
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 60, draw_curr->color[2], ft_itoa((int)draw_curr->max_z + 1));
}
