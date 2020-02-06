/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:31:14 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/06 19:32:34 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

#define ipart_(X) ((int)(X))
#define round_(X) ((int)(((double)(X))+0.5))
#define fpart_(X) (((double)(X))-(double)ipart_(X))
#define rfpart_(X) (1.0-fpart_(X))


// TODO: Norminette fix wu

static void swap_float(float *a , float *b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}

static void	endpoint_swap(t_point *start, t_point *end, t_scene *draw)
{
	if (draw->steep)
	{
		swap_float(&start->x, &start->y);
		swap_float(&end->x, &end->y);
	}
	if (end->x < start->x)
	{
		swap_float(&start->x, &end->x);
		swap_float(&start->y, &end->y);
	}
}
void 		draw_line_wu(t_point start, t_point end, t_scene *draw)
{
	t_point *delta;
	t_point *current;
	t_point *current_2;

	draw->steep = fabs(end.y - start.y) > fabs(end.x - start.x) ? 1 : 0;
	if (draw->steep == 1 || start.x > end.x)
		endpoint_swap(&start, &end, draw);
	delta = point_node_new(end.x - start.x,end.y - start.y, 0, draw);
	double gradient = delta->y/delta->x;
	if (delta->x == 0.0)
		gradient = 1.0;
	int xend = round(start.x);
	int yend = start.y + gradient * (xend - start.x);
	double xgap = rfpart_(start.x + 0.5);
	current = point_node_new(xend, ipart_(yend), 0, draw);
	if (draw->steep == 1)
	{
		put_pixel(current->y, current->x,  decrease_brightness(set_color(start, end, *delta, *current, *draw), 1.0), draw);
		put_pixel(current->y + 1, current->x, decrease_brightness(set_color(start, end, *delta, *current, *draw), fpart_(yend) * xgap), draw);
	}
	else
	{
		put_pixel(current->x, current->y, decrease_brightness(set_color(start, end, *delta, *current, *draw), 1.0), draw);
		put_pixel(current->x, current->y + 1, decrease_brightness(set_color(start, end, *delta, *current, *draw), fpart_(yend) * xgap), draw);
	}
	double intery = yend + gradient;
	xend = round(end.x);
	yend = end.y + gradient * (xend - end.x);
	xgap = fpart_(end.x + 0.5);
	current_2 = point_node_new(xend, ipart_(yend), 0, draw);
	if (draw->steep == 1)
	{
		put_pixel(current_2->y, current_2->x,  decrease_brightness(set_color(start, end, *delta, *current, *draw), 1.0), draw);
		put_pixel(current_2->y + 1, current_2->x, decrease_brightness(set_color(start, end, *delta, *current, *draw), fpart_(yend) * xgap), draw);
	}
	else
	{
		put_pixel(current_2->x, current_2->y, decrease_brightness(set_color(start, end, *delta, *current, *draw), 1.0), draw);
		put_pixel(current_2->x, current_2->y + 1, decrease_brightness(set_color(start, end, *delta, *current, *draw), fpart_(yend) * xgap), draw);
	}
	if (draw->steep == 1)
	{
		while (current->x < current_2->x)
		{
			put_pixel(ipart_(intery), current->x, decrease_brightness(set_color(start, end, *delta, *current, *draw), rfpart_(intery)), draw);
			put_pixel(ipart_(intery) + 1, current->x, decrease_brightness(set_color(start, end, *delta, *current, *draw), fpart_(intery)), draw);
			intery += gradient;
			current->x++;
		}
	}
	else
	{
		while (current->x < current_2->x)
		{
			put_pixel(current->x, ipart_(intery), decrease_brightness(set_color(start, end, *delta, *current, *draw), rfpart_(intery)), draw);
			put_pixel(current->x, ipart_(intery) + 1, decrease_brightness(set_color(start, end, *delta, *current, *draw), fpart_(intery)), draw);
			intery += gradient;
			current->x++;
		}
	}
	free(delta);
	free(current);
	free(current_2);
}
