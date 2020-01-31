/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/31 19:10:38 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_window(t_scene *draw)
{
	scene_find_minmax(draw);
	draw->color[0] = LEMON;
	draw->color[1] = PEACH;
	draw->color[2] = BROWN;
	draw->color[3] = LEMON;
	draw->vertex_count = 0;
	(draw->mouse = malloc(sizeof(t_mouse))) == NULL ? ft_error(0) : 0;
	draw->mouse->button_press = 0;
	draw->zoom = 1;
	while (draw->max_x * draw->zoom < WINDOW_WIDTH / 2)
		draw->zoom++;
	draw->projection = PARALLEL;
	draw->padding_x = WINDOW_WIDTH / 2 - draw->max_x / 2;
	draw->padding_y = WINDOW_HEIGHT / 2 - draw->max_y / 2;
	draw->draw_algorithm = &draw_line_bresenham;
	append_map(draw);
	center_origo(draw);
	matrix_transformation(draw, &zoom_matrix, 0);
}

static t_scene	*init_scene(void)
{
	t_map	*start;
	t_scene *draw;

	(start = malloc(sizeof(t_map))) == NULL ? ft_error(0) : 0;
	start->nxt = NULL;
	(draw = malloc(sizeof(t_scene))) == NULL ? ft_error(0) : 0;
	draw->map = start;
	(draw->mlx = mlx_init()) == NULL ? ft_error(3) : 0;
	(draw->win = mlx_new_window(draw->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,\
	"FdF 1.0 // ehalmkro // 2020")) == NULL ? ft_error(1) : 0;
	return (draw);
}

int				main(int argc, char **argv)
{
	t_scene	*draw;

	if (argc != 2)
		ft_putendl("usage: fdf source_file");
	else
	{
		draw = init_scene();
		(read_input(argv[1], draw)) == -1 ? ft_error(2) : 0;
		init_window(draw);
		draw_window(draw);
		event_handler(draw);
	}
	return (0);
}
