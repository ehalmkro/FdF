/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:05:47 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/21 16:01:04 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int 	decrease_brightness(int color, float brightness)
{
	printf("FLOAT VALUE %f\n", brightness);
	int *rgb;
	rgb = split_color(color);
	rgb[0] *= brightness;
	rgb[1] *= brightness;
	rgb[2] *= brightness;
	printf("then r %i g %i b%i\n", rgb[0], rgb[1], rgb[2]);
	return((0 << 24) | (rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
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