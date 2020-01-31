/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/31 15:04:48 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_window(t_scene *draw)
{
	mlx_clear_window(draw->mlx, draw->win);
	mlx_string_put(draw->mlx, draw->win, 790, 20, draw->color[3], "Line draw algorithm:");
	if (draw->draw_algorithm == &draw_line_bresenham)
		mlx_string_put(draw->mlx, draw->win, 750, 40, draw->color[3], "Jack Elton Bresenham (1965)");
	else if (draw->draw_algorithm == &draw_line_wu)
		mlx_string_put(draw->mlx, draw->win, 810, 40, draw->color[3], "Xiaolin Wu (1991)");
}
