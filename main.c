/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/27 15:46:09 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO: add default colors to struct to make changing them easier

void	init_window(t_scene **draw)
{
	if (((*draw)->win = mlx_new_window((*draw)->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF 0.01 // ehalmkro // 2020")) == NULL)
	{
		perror ("Error: ");
		exit (1);
	}

	(*draw)->mouse = malloc(sizeof(t_mouse));
	(*draw)->mouse->button_press = 0;
	(*draw)->zoom = 15;
	(*draw)->projection = 0;
	(*draw)->padding_x = 400;
	(*draw)->padding_y = 400;
	(*draw)->window_text_color = 0xFFFFFF;
}

int		main(int argc, char **argv)
{
	t_map			*start;
	t_scene			*draw;

	if (argc != 2)
		ft_putendl("usage: fdf source_file");
	else
	{
		start = map_add_node(NULL);
		draw = malloc(sizeof(t_scene));
		if (read_input(argv[1], &start) == -1)
		{
			perror("Error: ");
			exit(1);
		}
		draw->map = start;
		scene_find_minmax(draw);
		center_origo(draw);
		scene_find_minmax(draw);
		append_map(&start, &draw);
		if ((draw->mlx = mlx_init()) == NULL)
		{
			perror("Error: ");
			exit(1);
		}

		init_window(&draw);
		draw_window(&draw);
		matrix_transformation(draw, &zoom_matrix, 0);
		draw->draw_algorithm = &draw_line_bresenham;
		render(&start, &draw);
		mlx_hook(draw->win, 17, 0, &close_window, draw);
		mlx_hook(draw->win, 3, 0, &keypress, draw);
		mlx_hook(draw->win, 4, 0, &mouse_press, draw);
		mlx_hook(draw->win, 5, 0, &mouse_release, draw);
		mlx_hook(draw->win, 6, 0, &mouse_move, draw);


		mlx_loop(draw->mlx);
	}

//	LEAK TEST
//	while(1);

	return (0);
}
