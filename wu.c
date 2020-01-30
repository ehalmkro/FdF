#include "fdf.h"
#include "math.h"

// TODO: Norminette fix wu

void swap_double(double* a , double *b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

void 	draw_line_wu(t_point start, t_point end, t_scene *draw)
{
	t_point *delta;
	t_point *current;
	t_point *current_2;
	draw->steep = fabs(end.y - start.y) > fabs(end.x - start.x) ? 1 : 0;

	if (draw->steep)
	{
		swap_double(&start.x, &start.y);
		swap_double(&end.x, &end.y);
	}
	if (end.x < start.x)
	{
		swap_double(&start.x, &end.x);
		swap_double(&start.y, &end.y);
	}

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