/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:31:33 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/23 14:58:06 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"

int		close_window(void *param)
{
	(void)param;
	exit(0);
}

int		keypress(int keycode, void *param)
{
	t_draw *draw = param;
	if (keycode == MAIN_PAD_ESC)
		exit(0);
	if (keycode >= 123 && keycode < 127)
	{
		if (keycode == ARROW_UP)
			draw->padding_y = -1;
		if (keycode == ARROW_LEFT)
			draw->padding_x = -1;
		if (keycode == ARROW_DOWN)
			draw->padding_y = 1;
		if (keycode == ARROW_RIGHT)
			draw->padding_x = 1;
		move_matrix_pos(&draw);
	}
	if (keycode == MAIN_PAD_5)
	{
		draw->padding_z = 1;
		printf("yo");
		modify_z(&draw);
	}
	if (keycode == NUM_PAD_PLUS)
	{
		draw->zoom = ZOOM_COEFF_POS;
		zoom_matrix(&draw);
	}
	if (keycode == NUM_PAD_MINUS)
	{
		draw->zoom = ZOOM_COEFF_NEG;
		zoom_matrix(&draw);
	}
	if (keycode == NUM_PAD_MINUS)
	{
		draw->zoom = ZOOM_COEFF_NEG;
		zoom_matrix(&draw);
	}
	if (keycode == MAIN_PAD_9)
	{
		if (draw->draw_algorithm != &draw_line_wu)
			draw->draw_algorithm = &draw_line_wu;
		else
			draw->draw_algorithm = &draw_line_bresenham;
	}
	if (keycode == MAIN_PAD_MORE)
	{
		rotate_z(draw);
		center_map (&draw);
	}
	if (keycode == MAIN_PAD_0)
		transform_isometric (&draw);
	render(&(draw->map), &draw);
	return (0);
}

void			render(t_map **start, t_draw **draw)
{
	mlx_clear_window ((*draw)->mlx, (*draw)->win);
	draw_window(draw);
	t_point *point;
	t_point *point2;

/*	point = malloc(sizeof(t_point));
	point2 = malloc(sizeof(t_point));
	point = point_node_new(10, 0, 0);
	point2 = point_node_new(1000, 10000, 0);
	point->color = 0xFFFFFF;
	point2->color = 0xFFFFFF;
	draw_line_gupta_sproull(*point, *point2, *draw);*/

	draw_matrix(*start, *draw);
}
