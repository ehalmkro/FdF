#include "fdf.h"
#include "math.h"

void swap(double* a , double *b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

void 	draw_line_wu_alternate(t_point start, t_point end, t_scene *draw)
{
//	correct_axis (&start, &end, draw);
	draw->steep = fabs(end.y - start.y) > fabs(end.x - start.x) ? 1 : 0;
	if (draw->steep)
	{
		swap(&start.x, &start.y);
		swap(&end.x, &end.y);
	}
	if (end.x < start.x)
	{
		swap(&start.x, &end.x);
		swap(&start.y, &end.y);
	}

	double dx = end.x - start.x;
	double dy = end.y - start.y;
	double gradient = dy/dx;
	if (dx == 0.0)
		gradient = 1.0;
	int xend = round(start.x);
	int yend = start.y + gradient * (xend - start.x);
	double xgap = rfpart_(start.x + 0.5);
	int xpxl1 = xend;
	int ypxl1 = ipart_(yend);
	if (draw->steep == 1)
	{
		put_pixel(ypxl1, xpxl1,  decrease_brightness(start.color, rfpart_(yend) * xgap), draw);
		printf("%f\n", rfpart_((yend) * xgap));
		put_pixel(ypxl1 + 1, xpxl1, decrease_brightness(start.color, fpart_(yend) * xgap), draw);
	}
	else
	{
		put_pixel(xpxl1, ypxl1, decrease_brightness(start.color, rfpart_(yend) * xgap), draw);
		put_pixel(xpxl1, ypxl1 + 1, decrease_brightness(start.color, fpart_(yend) * xgap), draw);
	}
	double intery = yend + gradient;
	xend = round(end.x);
	yend = end.y + gradient * (xend - end.x);
	xgap = fpart_(end.x + 0.5);
	int xpxl2 = xend;
	int ypxl2 = ipart_(yend);
	if (draw->steep == 1)
	{
		put_pixel(ypxl2, xpxl2,  decrease_brightness(start.color, rfpart_(yend) * xgap), draw);
		put_pixel(ypxl2 + 1, xpxl2, decrease_brightness(start.color, fpart_(yend) * xgap), draw);
	}
	else
	{
		put_pixel(xpxl2, ypxl2, decrease_brightness(start.color, rfpart_(yend) * xgap), draw);
		put_pixel(xpxl2, ypxl2 + 1, decrease_brightness(start.color, fpart_(yend) * xgap), draw);
	}
	if (draw->steep == 1)
	{
		int x = xpxl1 + 1;
		while (x < xpxl2)
		{
			put_pixel(ipart_(intery), x, decrease_brightness(start.color, rfpart_(intery)), draw);
			put_pixel(ipart_(intery) + 1, x, decrease_brightness(start.color, fpart_(intery)), draw);
			intery += gradient;
			x++;
		}
	}
	else
	{
		int x = xpxl1 + 1;
		while (x < xpxl2)
		{
			put_pixel(x, ipart_(intery), decrease_brightness(start.color, rfpart_(intery)), draw);
			put_pixel(x, ipart_(intery) + 1, decrease_brightness(start.color, fpart_(intery)), draw);
			intery += gradient;
			x++;
		}
	}

}