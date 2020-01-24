/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/24 11:55:49 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_scene **draw)
{
	if (((*draw)->win = mlx_new_window((*draw)->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF 0.01 // ehalmkro // 2020")) == NULL)
	{
		perror ("Error: ");
		exit (1);
	}
	(*draw)->zoom = 15;
	(*draw)->padding_x = 200;
	(*draw)->padding_y = 200;
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
		append_map(&start, &draw);
		if ((draw->mlx = mlx_init()) == NULL)
		{
			perror("Error: ");
			exit(1);
		}

		init_window(&draw);
		draw_window(&draw);
		matrix_transformation(draw, &zoom_matrix);
		matrix_transformation(draw, &center_map);
		draw->draw_algorithm = &draw_line_bresenham;
		render(&start, &draw);
		mlx_hook(draw->win, 17, 0, &close_window, draw);
		mlx_hook(draw->win, 3, 0, &keypress, draw);
		mlx_loop(draw->mlx);
	}

//	LEAK TEST
//	while(1);

	return (0);
}
