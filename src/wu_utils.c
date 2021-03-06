/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:31:34 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/08 14:48:52 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		swap_height(t_height *a, t_height *b)
{
	t_height temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

float		decimal_part(float x)
{
	return (x - (float)((int)x));
}

float		offset_part(float x)
{
	return (1.0 - decimal_part(x));
}

void		endpoint_swap(t_point *start, t_point *end, t_line *line)
{
	if (line->steep)
	{
		ft_fswap(&start->x, &start->y);
		ft_fswap(&end->x, &end->y);
	}
	if (end->x < start->x)
	{
		ft_fswap(&start->x, &end->x);
		ft_fswap(&start->y, &end->y);
		swap_height(&start->height, &end->height);
	}
}
