/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/31 10:55:38 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_scene *draw)
{
	draw->win = mlx_new_window(draw->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF 1.0 // ehalmkro // 2020");
	if (draw->win == NULL)
		ft_error(1);
	draw->color[0] = LEMON;
	draw->color[1] = PEACH;
	draw->color[2] = BROWN;
	draw->color[3] = LEMON;
	draw->mouse = malloc(sizeof(t_mouse));
	draw->mouse->button_press = 0;
	draw->zoom = 1;
	while (draw->max_x * draw->zoom < WINDOW_WIDTH / 2)
		draw->zoom++;
	draw->projection = PARALLEL;
	draw->padding_x = WINDOW_WIDTH / 2 - draw->max_x / 2 ;
	draw->padding_y = WINDOW_HEIGHT / 2 - draw->max_y / 2;
	draw->draw_algorithm = &draw_line_bresenham;
	scene_find_minmax(draw);
}

int		main(int argc, char **argv)
{
	t_map *start;
	t_scene *draw;

	if (argc != 2)
		ft_putendl ("usage: fdf source_file");
	else
	{
		start = malloc(sizeof(t_map));
		start->next = NULL;
		draw = malloc (sizeof (t_scene));
		draw->map = start;
		if (read_input (argv[1], draw) == -1)
			ft_error(2);
		if ((draw->mlx = mlx_init ()) == NULL)
			exit (3);
		center_origo(draw);
		init_window(draw);
		append_map(draw);
		draw_window(&draw);
		matrix_transformation(draw, &zoom_matrix, 0);
		mlx_hook(draw->win, 17, 0, &close_window, draw);
		mlx_hook(draw->win, 3, 0, &keypress, draw);
		mlx_hook(draw->win, 4, 0, &mouse_press, draw);
		mlx_hook(draw->win, 5, 0, &mouse_release, draw);
		mlx_hook(draw->win, 6, 0, &mouse_move, draw);
		mlx_loop_hook(draw->mlx, &window_idle, draw);
		mlx_loop(draw->mlx);

	}

//	LEAK TEST
		//while (1);

		return (0);
}
