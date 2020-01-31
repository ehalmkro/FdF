#include "fdf.h"
#include "math.h"

// TODO: Norminette fix wu

static void swap_float(float *a , float *b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}

// TODO: ONE FUNCTIONING WU PLZ

/*
static void	draw_endpoint_wu(t_point *point, t_line *line, t_scene *draw)
{
	int		xpxl;
	int		ypxl;
	float	yend;
	float	xgap;
	t_point draw_point;

	xpxl = round(point->x);
	yend = point->y + line->gradient * (xpxl - point->x);
	ypxl = floor(yend);
	xgap = rfpart_(point->x + 0.5);
	draw_point.x = line->steep ? ypxl : xpxl;
	draw_point.y = line->steep ? xpxl : ypxl;
	put_pixel(draw_point.x, draw_point.y,  decrease_brightness(0xFFFFFF, rfpart_(yend) * xgap), draw);
	line->steep == 1 ? (draw_point.x)++ : (draw_point.y++);
	put_pixel(draw_point.x, draw_point.y, decrease_brightness(0xFFFFFF, fpart_(yend) * xgap), draw);
}

static void	draw_fill_wu(t_point *start, t_point *end, t_line *line, t_scene *draw)
{
	t_point		draw_point;
	int			xpxl;

	xpxl = line->x_start;
	while (++xpxl <= line->x_end)
	{
		draw_point.x = xpxl;
		draw_point.y = floor(line->y_intersection);
	//	line->steep == 1 ? swap_float(&draw_point.x, &draw_point.y) : 0;
		put_pixel(draw_point.x, draw_point.y,  decrease_brightness(0xFFFFFF, rfpart_(line->y_intersection)), draw);
		line->steep == 1 ? (draw_point.x)++ : (draw_point.y++);
		put_pixel(draw_point.x, draw_point.y,  decrease_brightness(0xFFFFFF, rfpart_(line->y_intersection)), draw);
		line->y_intersection += line->gradient;
	}

}

void 		draw_line_wu(t_point start, t_point end, t_scene *draw)
{
	t_line line;

	line.steep = (fabs(end.y - start.y) > fabs(end.x - start.x)) ? 1 : 0;
	if (line.steep)
	{
		swap_float(&start.x, &start.y);
		swap_float(&end.x, &end.y);
	}
	if (end.x < start.x)
	{
		swap_float(&start.x, &end.x);
		swap_float(&start.y, &end.y);
	}
	line.delta.x = end.x - start.x;
	line.delta.y = start.x - start.y;
	line.gradient = line.delta.y / line.delta.x;
	line.delta.x == 0.0 ? line.gradient = 1.0 : 0;
	line.y_intersection = start.y + line.gradient * (line.x_start - start.x + 1);
	draw_endpoint_wu(&start, &line, draw);
	line.x_start = start.x;
	line.x_end = end.x;
	draw_endpoint_wu(&end, &line, draw);
	draw_fill_wu(&start, &end, &line, draw);
}
*/


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
		put_pixel(current->y, current->x,  decrease_brightness(set_color(end, start, *delta, *current, *draw), 1.0), draw);
		put_pixel(current->y + 1, current->x, decrease_brightness(set_color(end, start, *delta, *current, *draw), fpart_(yend) * xgap), draw);
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
		put_pixel(current_2->y, current_2->x,  decrease_brightness(set_color(end, start, *delta, *current, *draw), 1.0), draw);
		put_pixel(current_2->y + 1, current_2->x, decrease_brightness(set_color(end, start, *delta, *current, *draw), fpart_(yend) * xgap), draw);
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
			put_pixel(ipart_(intery), current->x, decrease_brightness(set_color(end, start, *delta, *current, *draw), rfpart_(intery)), draw);
			put_pixel(ipart_(intery) + 1, current->x, decrease_brightness(set_color(end, start, *delta, *current, *draw), fpart_(intery)), draw);
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
