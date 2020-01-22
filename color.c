/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:05:47 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/22 18:24:33 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int 	*split_color(int color)
{
	int *ret;
	ret = malloc(sizeof(int*) * 3);
	ret[0] = color & 255;
	color >>= 8;
	ret[1] = color & 255;
	ret[2] = color >> 8;
	return (ret);
}

int 	decrease_brightness(int color, double brightness)
{
	int *rgb;
	rgb = split_color(color);
	rgb[0] *= brightness;
	rgb[1] *= brightness;
	rgb[2] *= brightness;
	return((0 << 24) + (rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}

// TODO: RGB COLOR GRADIENTS

int 	get_color_rgb(int r, int g, int b)
{
		return((0 << 24) | (r << 16) | (g << 8) | b);
}

int		set_color(t_point *start, t_point *end)
{
	if (start->z == 0 && end->z == 0)
		return(0xffffff);
	return(0xffff00);
}