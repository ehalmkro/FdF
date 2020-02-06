/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:31:14 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/06 20:10:30 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

/*
** As the Wu line algorithm is bonus functionality, the macros are considered
** kosher.
*/

#define IPART_(X) ((int)(X))
#define ROUND_(X) ((int)(((double)(X))+0.5))
#define FPART_(X) (((float)(X))-(float)IPART_(X))
#define RFPART_(X) (1.0-FPART_(X))

static void	swap_float(float *a, float *b)
{
	float temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
static void	swap_height(t_height *a, t_height *b)
{
	t_height temp;

	temp = *a;
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
		swap_height(&start->height, &end->height);
	}
}
void 		draw_line_wu(t_point start, t_point end, t_scene *draw)
{
	t_point		*delta;
	t_point		*current;
	t_point		*current_2;

	draw->steep = fabs(end.y - start.y) > fabs(end.x - start.x) ? 1 : 0;
	if (draw->steep == 1 || start.x > end.x)
		endpoint_swap(&start, &end, draw);
	delta = point_node_new(end.x - start.x, end.y - start.y, 0, draw);
	double gradient = delta->y/delta->x;
	if (delta->x == 0.0)
		gradient = 1.0;
	int xend = round(start.x);
	int yend = start.y + gradient * (xend - start.x);
	double xgap = RFPART_(start.x + 0.5);
	current = point_node_new(xend, IPART_(yend), 0, draw);
	if (draw->steep == 1)
	{
		put_pixel(current->y, current->x,  decrease_brightness(set_color(start, end, *delta, *current, *draw), RFPART_(yend) * xgap), draw);
		put_pixel(current->y + 1, current->x, decrease_brightness(set_color(start, end, *delta, *current, *draw), FPART_(yend) * xgap), draw);
	}
	else
	{
		put_pixel(current->x, current->y, decrease_brightness(set_color(start, end, *delta, *current, *draw), RFPART_(yend) * xgap), draw);
		put_pixel(current->x, current->y + 1, decrease_brightness(set_color(start, end, *delta, *current, *draw), FPART_(yend) * xgap), draw);
	}
	double intery = yend + gradient;
	xend = round(end.x);
	yend = end.y + gradient * (xend - end.x);
	xgap = FPART_(end.x + 0.5);
	current_2 = point_node_new(xend, IPART_(yend), 0, draw);
	if (draw->steep == 1)
	{
		put_pixel(current_2->y, current_2->x,  decrease_brightness(set_color(start, end, *delta, *current, *draw), RFPART_(yend) * xgap), draw);
		put_pixel(current_2->y + 1, current_2->x, decrease_brightness(set_color(start, end, *delta, *current, *draw), FPART_(yend) * xgap), draw);
	}
	else
	{
		put_pixel(current_2->x, current_2->y, decrease_brightness(set_color(start, end, *delta, *current, *draw), RFPART_(yend) * xgap), draw);
		put_pixel(current_2->x, current_2->y + 1, decrease_brightness(set_color(start, end, *delta, *current, *draw), FPART_(yend) * xgap), draw);
	}
	if (draw->steep == 1)
	{
		while (current->x < current_2->x)
		{
			put_pixel(IPART_(intery), current->x, decrease_brightness(set_color(start, end, *delta, *current, *draw), RFPART_(intery)), draw);
			put_pixel(IPART_(intery) + 1, current->x, decrease_brightness(set_color(start, end, *delta, *current, *draw), FPART_(intery)), draw);
			intery += gradient;
			current->x++;
		}
	}
	else
	{
		while (current->x < current_2->x)
		{
			put_pixel(current->x, IPART_(intery), decrease_brightness(set_color(start, end, *delta, *current, *draw), RFPART_(intery)), draw);
			put_pixel(current->x, IPART_(intery) + 1, decrease_brightness(set_color(start, end, *delta, *current, *draw), FPART_(intery)), draw);
			intery += gradient;
			current->x++;
		}
	}
	free(delta);
	free(current);
	free(current_2);
}
