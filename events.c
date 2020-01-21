/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:31:33 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/21 16:19:13 by ehalmkro         ###   ########.fr       */
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
	if (keycode > 123 && keycode < 127)
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
	if (keycode == MAIN_PAD_MORE)
		rotate_2d(draw);
	if (keycode == MAIN_PAD_0)
		printf("cool %x\t", get_color_rgb(50, 50, 50));
	render(&(draw->map), &draw);
	return (0);
}

void			render(t_map **start, t_draw **draw)
{
	mlx_clear_window ((*draw)->mlx, (*draw)->win);
	draw_window(draw);
	draw_matrix(*start, *draw);
}
