/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:47:20 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/20 19:21:54 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	rotate_2d(t_draw *draw)
{
	t_map *matrix;
	double prev_y;
	double prev_x;

	matrix = draw->map;
	while (matrix)
	{
		prev_y = matrix->data->y;
		prev_x = matrix->data->x;
		matrix->data->x = prev_x * cos(MATRIX_ROTATION_DEG) - prev_y * sin(MATRIX_ROTATION_DEG);
		matrix->data->y = prev_x * sin(MATRIX_ROTATION_DEG) + prev_y * cos(MATRIX_ROTATION_DEG);
		matrix = matrix->next;
	}
}