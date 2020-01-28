/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:31:33 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/28 12:30:27 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"

int		mouse_move(int x, int y, void *param)
{
	t_scene *draw;

	draw = param;
	draw->mouse->prev_x = draw->mouse->x;
	draw->mouse->prev_y = draw->mouse->y;
	draw->mouse->x = x;
	draw->mouse->y = y;
	if (draw->mouse->button_press == 1 || draw->mouse->button_press == 5)
	{
		matrix_transformation(draw, &switch_color, 0);
		matrix_transformation (draw, &rotate_x, (x - draw->mouse->prev_x) * 0.001);
		matrix_transformation (draw, &rotate_y, (y - draw->mouse->prev_y) * 0.001);
	}
	if (draw->mouse->button_press == 4 || draw->mouse->button_press == 5)
		matrix_transformation (draw, &rotate_z, (y - draw->mouse->prev_y) * 0.005);
	render (&(draw->map), &draw);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_scene *draw;

	(void)x;
	(void)y;
	draw = param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		button == MOUSE_SCROLL_UP ? draw->zoom = ZOOM_COEFF_POS : 0;
		button == MOUSE_SCROLL_DOWN ? draw->zoom = ZOOM_COEFF_NEG : 0;
		matrix_transformation (draw, &zoom_matrix, 0);
	}
	if (button == MOUSE_LEFT_BUTTON)
		draw->mouse->button_press += 1;
	if (button == MOUSE_RIGHT_BUTTON)
		draw->mouse->button_press += 4;
	render(&(draw->map), &draw);
	return(0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_scene *draw;

	(void)x;
	(void)y;
	draw = param;
	if (button == MOUSE_LEFT_BUTTON)
		draw->mouse->button_press -= 1;
	if (button == MOUSE_RIGHT_BUTTON)
		draw->mouse->button_press -= 4;
	return (0);
}

int		close_window(void *param)
{
	(void)param;
	exit(0);
}

int		keypress(int keycode, void *param)
{
	t_scene *draw = param;
	if (keycode == MAIN_PAD_ESC)
		exit(0);
	if (keycode >= 123 && keycode < 127)
	{
		if (keycode == ARROW_UP)
			draw->padding_y -= DEFAULT_INCREMENT;
		if (keycode == ARROW_LEFT)
			draw->padding_x -= DEFAULT_INCREMENT;
		if (keycode == ARROW_DOWN)
			draw->padding_y += DEFAULT_INCREMENT;
		if (keycode == ARROW_RIGHT)
			draw->padding_x += DEFAULT_INCREMENT;
	}
	if (keycode == MAIN_PAD_6)
		matrix_transformation(draw, &switch_color, 0);
	if (keycode == MAIN_PAD_5)
	{
		draw->padding_z = 1;
		matrix_transformation(draw, &modify_z, 0);
		draw->padding_z = 0;
	}
	if (keycode == NUM_PAD_PLUS)
	{
		draw->zoom = ZOOM_COEFF_POS;
		matrix_transformation(draw, zoom_matrix, 0);
	}
	if (keycode == NUM_PAD_MINUS)
	{
		draw->zoom = ZOOM_COEFF_NEG;
		matrix_transformation(draw, zoom_matrix, 0);
	}
	if (keycode == NUM_PAD_MINUS)
	{
		draw->zoom = ZOOM_COEFF_NEG;
		matrix_transformation(draw, zoom_matrix, 0);
	}
	if (keycode == MAIN_PAD_9)
	{
		if (draw->draw_algorithm != &draw_line_wu_alternate)
			draw->draw_algorithm = &draw_line_wu_alternate;
		else
			draw->draw_algorithm = &draw_line_bresenham;
/*		else
			draw->draw_algorithm = &draw_line_gupta_sproull;*/
	}
	if (keycode == MAIN_PAD_MORE)
	{
		matrix_transformation(draw, rotate_z, MATRIX_ROTATION_DEG);
		//matrix_transformation(draw, center_map);
	}
	if (keycode == MAIN_PAD_LESS)
		matrix_transformation(draw, rotate_y, MATRIX_ROTATION_DEG);
	if (keycode == MAIN_PAD_0)
	{
		if (draw->projection == PARALLEL)
			draw->projection = ISOMETRIC;
		else
			draw->projection = PARALLEL;
		printf("PROJECTION %u\n", draw->projection);
	}
	render(&(draw->map), &draw);
	return (0);
}

void			render(t_map **start, t_scene **draw)
{
	mlx_clear_window ((*draw)->mlx, (*draw)->win);
	draw_window(draw);
	draw_matrix(*start, *draw);
}
