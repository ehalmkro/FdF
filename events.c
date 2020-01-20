/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:31:33 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/20 13:40:46 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"

static int		close_window(void *param)
{
	(void)param;
	exit(0);
}

static int		keypress(int keycode, void *param)
{
	t_draw *draw = param;
	if (keycode == MAIN_PAD_ESC)
		exit(0);
	if (keycode == ARROW_UP)
	{
		draw->padding_y -= 5;
		printf("PADDING Y = %f", draw->padding_y);
	}

	return (0);


}

void			event_loop(t_map **start, t_draw **draw)
{
	t_map *list_curr;
	t_draw *draw_curr;

	list_curr = *start;
	draw_curr = *draw;

	mlx_hook(draw_curr->win, 17, 0, &close_window, draw_curr);
	mlx_hook(draw_curr->win, 3, 0, &keypress, draw_curr);
	draw_window(draw);
	draw_matrix(*start, *draw);

}
