/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/08 14:48:52 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		draw_menu(t_scene *draw)
{
	if (draw->display_ctrls == 1)
	{
		mlx_string_put(draw->mlx, draw->win, 20, 60, draw->color[3], "Help:");
		mlx_string_put(draw->mlx, draw->win, 20, 80, draw->color[3], \
	"Rotate by clicking and dragging MOUSE1 and/or MOUSE2");
		mlx_string_put(draw->mlx, draw->win, 20, 100, draw->color[3], \
	"Move with ARROW keys");
		mlx_string_put(draw->mlx, draw->win, 20, 140, draw->color[3], \
	"0 - Change projection");
		mlx_string_put(draw->mlx, draw->win, 20, 160, draw->color[3], \
	"9 - Change projection");
		mlx_string_put(draw->mlx, draw->win, 20, 180, draw->color[3], \
	"> - Change color palette");
		mlx_string_put(draw->mlx, draw->win, 20, 200, draw->color[3], \
	"D - Line algorithm demo lines");
		mlx_string_put(draw->mlx, draw->win, 20, 220, draw->color[3], \
	"C - Hide instructions");
	}
	else
		mlx_string_put(draw->mlx, draw->win, 20, 60, draw->color[3], \
		"Press C to see instructions");
}

void			draw_window(t_scene *draw)
{
	char *linedraw;

	mlx_clear_window(draw->mlx, draw->win);
	mlx_string_put(draw->mlx, draw->win, 780, 60, draw->color[3], \
	"Line draw algorithm:");
	linedraw = draw->draw_algorithm == &draw_line_bresenham ? \
	ft_strdup("Jack Bresenham (1965)") : ft_strdup("Xiaolin Wu (1991)");
	mlx_string_put(draw->mlx, draw->win, 780, 80, draw->color[2], linedraw);
	mlx_string_put(draw->mlx, draw->win, 780, 100, draw->color[3], \
	"Projection type:");
	free(linedraw);
	linedraw = draw->projection == PARALLEL ? ft_strdup("Parallel") : \
	ft_strdup("Isometric");
	free(linedraw);
	mlx_string_put(draw->mlx, draw->win, 780, 120, draw->color[2], linedraw);
	draw_menu(draw);
	text_carousel(draw);
}
