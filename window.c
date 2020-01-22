/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/22 18:19:12 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*draw_window(t_draw **draw)
{
	t_draw *draw_curr;

	draw_curr = *draw;

	mlx_clear_window(draw_curr->mlx, draw_curr->win);
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 20, MAGENTA, "X max");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 40, BLUE, "Y max");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 60, YELLOW,  "Z max");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 80, GREEN, "Line algorithm:");
	if ((*draw)->draw_algorithm == &draw_line_bresenham)
		mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 100, 0xFFFF00, "Bresenham");
	else
		mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 100, 0xFFFF00, "Xiaolin Wu");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 20, draw_curr->window_text_color, ft_itoa((int)draw_curr->max_x + 1));
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 40, draw_curr->window_text_color, ft_itoa((int)draw_curr->max_y + 1));
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 60, draw_curr->window_text_color, ft_itoa((int)draw_curr->max_z + 1));
}
