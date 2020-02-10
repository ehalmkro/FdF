/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:37:14 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/08 14:48:52 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/keycodes.h"

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
		matrix_transformation(draw, &rot_x, (x - draw->mouse->prev_x) * 0.001);
		matrix_transformation(draw, &rot_y, (y - draw->mouse->prev_y) * 0.001);
	}
	if (draw->mouse->button_press == 4 || draw->mouse->button_press == 5)
		matrix_transformation(draw, &rot_z, (y - draw->mouse->prev_y) * 0.005);
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_scene *draw;

	(void)x;
	(void)y;
	draw = param;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		button == SCROLL_UP ? draw->zoom = ZOOM_COEFF_POS : 0;
		button == SCROLL_DOWN ? draw->zoom = ZOOM_COEFF_NEG : 0;
		matrix_transformation(draw, &zoom_matrix, 0);
	}
	if (button == MOUSE1)
		draw->mouse->button_press += 1;
	if (button == MOUSE2)
		draw->mouse->button_press += 4;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_scene *draw;

	(void)x;
	(void)y;
	draw = param;
	if (button == MOUSE1)
		draw->mouse->button_press -= 1;
	if (button == MOUSE2)
		draw->mouse->button_press -= 4;
	return (0);
}
