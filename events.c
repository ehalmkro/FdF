/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:31:33 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/06 20:17:44 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"

int			close_window(void *param)
{
	(void)param;
	exit(0);
}

int			keypress(int keycode, void *param)
{
	t_scene *draw;

	draw = param;
	keycode == ESC ? exit(0) : 0;
	keycode == ARROW_UP ? draw->padding_y -= DEFAULT_INCREMENT : 0;
	keycode == ARROW_DOWN ? draw->padding_y += DEFAULT_INCREMENT : 0;
	keycode == ARROW_LEFT ? draw->padding_x -= DEFAULT_INCREMENT : 0;
	keycode == ARROW_RIGHT ? draw->padding_x += DEFAULT_INCREMENT : 0;
	keycode == GREATER_THAN ? change_palette(draw) : 0;
	keycode == PLUS ? matrix_transformation(draw, zoom_matrix, 1) : 0;
	keycode == MINUS ? matrix_transformation(draw, zoom_matrix, -1) : 0;
	if (keycode == D)
		draw->debug = draw->debug == 0 ? 1 : 0;
	if (keycode == NUMBER_ROW_9)
		draw->draw_algorithm = draw->draw_algorithm == &draw_line_wu ? \
		&draw_line_bresenham : &draw_line_wu;
	if (keycode == NUMBER_ROW_0)
	{
		if (draw->projection == PARALLEL)
			draw->projection = ISOMETRIC;
		else
			draw->projection = PARALLEL;
	}
	return (0);
}

int			window_idle(void *param)
{
	t_scene *draw;

	draw = param;
	if (draw->mouse->button_press == 0)
	{
		matrix_transformation(draw, &rot_x, 0.00009);
		matrix_transformation(draw, &rot_y, 0.00009);
		matrix_transformation(draw, &rot_z, 0.00009);
	}
	render(draw);
	return (0);
}

void		event_handler(t_scene *draw)
{
	mlx_hook(draw->win, 17, 0, &close_window, draw);
	mlx_hook(draw->win, 3, 0, &keypress, draw);
	mlx_hook(draw->win, 4, 0, &mouse_press, draw);
	mlx_hook(draw->win, 5, 0, &mouse_release, draw);
	mlx_hook(draw->win, 6, 0, &mouse_move, draw);
	mlx_loop_hook(draw->mlx, &window_idle, draw);
	mlx_loop(draw->mlx);
}

void		render(t_scene *draw)
{
	mlx_clear_window(draw->mlx, draw->win);
	if (timer(draw, 30000, 0) == 0)
		draw->carousel == 9 ? draw->carousel = 0 : draw->carousel++;
	if (timer(draw, 30000, 1) == 0)
		switch_color(draw);
	draw_window(draw);
	draw->debug == 1 ? debug_lines(draw) : draw_matrix(draw->map, draw);
}
