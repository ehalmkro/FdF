/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:05:47 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/27 20:24:45 by ehalmkro         ###   ########.fr       */
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

int		combine_color(int r, int g, int b)
{
	return((0 << 24) + (r << 16) + (g << 8) + b);
}

int 	*get_gradient(int start_color, int end_color)
{
	int *start;
	int *end;
	int *ret;
	int i;
	int j;

	ret = (int*)malloc(sizeof(int) *  6);
	ret[0] = start_color;
	ret[5] = end_color;
	start = split_color(start_color);
	end = split_color(end_color);
	ret[1] = combine_color((int)(start[0] * 0.8 + end[0] * 0.2) / 100, (int)(start[1] * 0.8 + end[1] * 0.2) / 100, \
		(int)(start[2] * 0.8 + end[2] * 0.2) / 100);
	ret[2] = combine_color((int)(start[0] * 0.6 + end[0] * 0.4) / 100, (int)(start[1] * 0.6 + end[1] * 0.4) / 100, \
		(int)(start[2] * 0.6 + end[2] * 0.4) / 100);
	ret[3] = combine_color((int)(start[0] * 0.4 + end[0] * 0.6) / 100, (int)(start[1] * 0.4 + end[1] * 0.6) / 100, \
		(int)(start[2] * 0.4 + end[2] * 0.6) / 100);
	ret[4] = combine_color((int)(start[0] * 0.2 + end[0] * 0.8) / 100, (int)(start[1] * 0.2 + end[1] * 0.8) / 100, \
		(int)(start[2] * 0.2 + end[2] * 0.8) / 100);
	return (ret);
}


int 	decrease_brightness(int color, double brightness)
{
	int *rgb;
	if (brightness >= 1.0)
		return (color);
	rgb = split_color(color);
	rgb[0] *= brightness;
	rgb[1] *= brightness;
	rgb[2] *= brightness;
	return((0 << 24) + (rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}


int		get_color_point(int start, int end, double percentage)
{
	return (((1 - percentage) * start + percentage * end));
}

int		set_color(t_point start, t_point end, t_point delta, t_point current, t_scene draw)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (delta.x > delta.y)
		percentage = get_percent(start.x, end.x, current.x);
	else
		percentage = get_percent(start.y, end.y, current.y);
	r = get_color_point((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
	g = get_color_point((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
	b = get_color_point(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);

}
