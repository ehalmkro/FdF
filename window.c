/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/30 15:39:47 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	text_carousel(t_scene *draw)
{
	int i;

	i = 10009999;
	draw->carousel == 0 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "*** F D F ***") : 0;
	draw->carousel == 1 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "** F D F *** ") : 0;
	draw->carousel == 2 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "* F D F ***  ") : 0;
	draw->carousel == 3 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], " F D F *** F ") : 0;
	draw->carousel == 4 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "F D F *** F D") : 0;
	draw->carousel == 5 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], " D F *** F D ") : 0;
	draw->carousel == 6 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "D F *** F D F") : 0;
	draw->carousel == 7 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "  F *** F D F") : 0;
	draw->carousel == 8 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "F *** F D F *") : 0;
	draw->carousel == 9 ? mlx_string_put(draw->mlx, draw->win, WINDOW_WIDTH/2.5, 40, draw->color[3], "*** F D F ***") : 0;
	draw->carousel == 9 ? draw->carousel = 0 : draw->carousel++;

}

void			*draw_window(t_scene **draw)
{
	t_scene *draw_curr;
	draw_curr = *draw;


	mlx_clear_window(draw_curr->mlx, draw_curr->win);
	mlx_string_put(draw_curr->mlx, draw_curr->win, 790, 20, draw_curr->color[3], "Line draw algorithm:");
	if ((*draw)->draw_algorithm == &draw_line_bresenham)
		mlx_string_put(draw_curr->mlx, draw_curr->win, 750, 40, draw_curr->color[3], "Jack Elton Bresenham (1965)");
	else if ((*draw)->draw_algorithm == &draw_line_wu_alternate)
		mlx_string_put(draw_curr->mlx, draw_curr->win, 810, 40, draw_curr->color[3], "Xiaolin Wu (1991)");
	text_carousel(*draw);
}
