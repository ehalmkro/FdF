/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:31:33 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/24 19:50:36 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"

int		close_window(void *param)
{
	(void)param;
	exit(0);
}

int		keypress(int keycode, void *param)
{
	t_scene *draw = param;
	if (keycode == MAIN_PAD_ESC)
		exit(0);
	if (keycode >= 123 && keycode < 127)
	{
		if (keycode == ARROW_UP)
			draw->padding_y -= DEFAULT_INCREMENT;
		if (keycode == ARROW_LEFT)
			draw->padding_x -= DEFAULT_INCREMENT;
		if (keycode == ARROW_DOWN)
			draw->padding_y += DEFAULT_INCREMENT;
		if (keycode == ARROW_RIGHT)
			draw->padding_x += DEFAULT_INCREMENT;
	}
	if (keycode == MAIN_PAD_5)
	{
		draw->padding_z = 1;
		printf("yo");
		matrix_transformation(draw, &modify_z);
		draw->padding_z = 0;
	}
	if (keycode == NUM_PAD_PLUS)
	{
		draw->zoom = ZOOM_COEFF_POS;
		matrix_transformation(draw, zoom_matrix);
	}
	if (keycode == NUM_PAD_MINUS)
	{
		draw->zoom = ZOOM_COEFF_NEG;
		matrix_transformation(draw, zoom_matrix);
	}
	if (keycode == NUM_PAD_MINUS)
	{
		draw->zoom = ZOOM_COEFF_NEG;
		matrix_transformation(draw, zoom_matrix);
	}
	if (keycode == MAIN_PAD_9)
	{
		if (draw->draw_algorithm != &draw_line_wu_alternate)
			draw->draw_algorithm = &draw_line_wu_alternate;
		else
			draw->draw_algorithm = &draw_line_wu;
/*		else
			draw->draw_algorithm = &draw_line_gupta_sproull;*/
	}
	if (keycode == MAIN_PAD_MORE)
	{
		matrix_transformation(draw, rotate_z);
		//matrix_transformation(draw, center_map);
	}
	if (keycode == MAIN_PAD_LESS)
		matrix_transformation(draw, rotate_y);
	if (keycode == MAIN_PAD_0)
		matrix_transformation(draw, transform_isometric);
	render(&(draw->map), &draw);
	return (0);
}

void			render(t_map **start, t_scene **draw)
{
	mlx_clear_window ((*draw)->mlx, (*draw)->win);
	draw_window(draw);
	//printf("X = %f, Y = %f Z = %f\n", (*draw)->map->data->x, (*draw)->map->data->y, (*draw)->map->data->z);
	//printf("NEXT\nX = %f, Y = %f Z = %f\n", (*draw)->map->next->data->x, (*draw)->map->next->data->y, (*draw)->map->next->data->z);

	/*t_point *point;
	t_point *point2;
	point = malloc(sizeof(t_point));
	point2 = malloc(sizeof(t_point));
	point = point_node_new(10, 0, 0);
	point2 = point_node_new(50, 1000, 0);
	point->color = 0xFFFFFF;
	point2->color = 0xFFFFFF;
	draw_line_gupta_sproull(*point, *point2, *draw);
	point = point_node_new(20, 0, 0);
	point2 = point_node_new(60, 1000, 0);
	draw_line_bresenham(*point, *point2, *draw);*/
	draw_matrix(*start, *draw);
}
