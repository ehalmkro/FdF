/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/21 16:31:27 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*draw_window(t_draw **draw)
{
	t_draw *draw_curr;

	draw_curr = *draw;

	mlx_clear_window(draw_curr->mlx, draw_curr->win);
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 20, 3289650, "X max");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 40, 3289650, "Y max");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 20, 60, 3289650, "Z max");
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 20, 3289650, ft_itoa((int)draw_curr->max_x + 1));
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 40, 3289650, ft_itoa((int)draw_curr->max_y + 1));
	mlx_string_put(draw_curr->mlx, draw_curr->win, 100, 60, 3289650, ft_itoa((int)draw_curr->max_z + 1));
}
