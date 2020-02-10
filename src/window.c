/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/10 13:57:08 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		draw_image_background(t_scene *draw)
{
	int x;
	int y;
	int pixel;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			pixel = y * 4 * WINDOW_WIDTH + 4 * x;
			draw->image_buffer[pixel + 0] = (char)0x32;
			draw->image_buffer[pixel + 1] = (char)0x2D;
			draw->image_buffer[pixel + 2] = (char)0x32;
			draw->image_buffer[pixel + 3] = (char)0x00;
			x++;
		}
		y++;
	}
}

static void		draw_menu(t_scene *draw)
{
	if (draw->display_ctrls == 1)
	{
		mlx_string_put(draw->mlx, draw->win, 20, 60, draw->color[3], "Help:");
		mlx_string_put(draw->mlx, draw->win, 20, 80, draw->color[3] + 5,
	"Rotate by clicking and dragging MOUSE1 and/or MOUSE2");
		mlx_string_put(draw->mlx, draw->win, 20, 120, draw->color[3] + 15,
	"Move with ARROW keys");
		mlx_string_put(draw->mlx, draw->win, 20, 100, draw->color[3] + 30,
	"Zoom with MOUSE SCROLL");
		mlx_string_put(draw->mlx, draw->win, 20, 140, draw->color[3] + 45,
	"0 - Change projection");
		mlx_string_put(draw->mlx, draw->win, 20, 160, draw->color[3] + 60,
	"9 - Change line algorithm");
		mlx_string_put(draw->mlx, draw->win, 20, 180, draw->color[3] + 75,
	"> - Change color palette");
		mlx_string_put(draw->mlx, draw->win, 20, 200, draw->color[3] + 80,
	"D - Line algorithm demo lines");
		mlx_string_put(draw->mlx, draw->win, 20, 220, draw->color[3] + 80,
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
	draw_image_background(draw);
	mlx_put_image_to_window(draw->mlx, draw->win, draw->image, 0, 0);
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
