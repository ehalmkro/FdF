/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:05:47 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/31 19:37:43 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int 	decrease_brightness(int color, float brightness)
{
	int *rgb;
	if (brightness >= 1.0)
		return (color);
	rgb = split_color(color);
	rgb[0] *= brightness;
	rgb[1] *= brightness;
	rgb[2] *= brightness;
	free(rgb);
	return((0 << 24) + (rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}


int		get_color_point(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		set_color(t_point start, t_point end, t_point delta, t_point current, t_scene draw)
{
	int		r;
	int		g;
	int		b;
	double	percentage;
	int 	color[2];

	start.height == HI ? color[0] = draw.color[2] : 0;
	start.height == ZERO ? color[0] = draw.color[1] : 0;
	start.height == LO ? color[0] = draw.color[0] : 0;
	end.height == LO ? color[1] = draw.color[2] : 0;
	end.height == ZERO ? color[1] = draw.color[1] : 0;
	end.height == LO ? color[1] = draw.color[0] : 0;
	if (delta.x > delta.y)
		percentage = get_percent(start.x, end.x, current.x);
	else
		percentage = get_percent(start.y, end.y, current.y);
	r = get_color_point((color[0] >> 16) & 0xFF, (color[1] >> 16) & 0xFF, percentage);
	g = get_color_point((color[0] >> 8) & 0xFF, (color[1] >> 8) & 0xFF, percentage);
	b = get_color_point(color[0] & 0xFF, color[1] & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}
