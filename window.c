/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:55:59 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/05 20:04:01 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void			draw_string(char *str, t_scene *draw)
{
	char	**arr;
	size_t	i;
	int 	y;

	y = 20;
	i = 0;
	arr = ft_strsplit(str, '\n');
	while (arr[i])
	{
		mlx_string_put(draw->mlx, draw->win, 20, y, draw->color[3], arr[i++]);
		y += 20;
	}
	free(arr);
}
*/


void			draw_window(t_scene *draw)
{

	mlx_clear_window(draw->mlx, draw->win);
	mlx_string_put(draw->mlx, draw->win, 790, 20, draw->color[3], "Line draw algorithm:");
	if (draw->draw_algorithm == &draw_line_bresenham)
		mlx_string_put(draw->mlx, draw->win, 750, 40, draw->color[3], "Jack Elton Bresenham (1965)");
	else if (draw->draw_algorithm == &draw_line_wu)
		mlx_string_put(draw->mlx, draw->win, 810, 40, draw->color[3], "Xiaolin Wu (1991)");
	text_carousel(draw);


}
