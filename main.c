/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/21 16:11:52 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_draw **draw)
{
	if (((*draw)->win = mlx_new_window((*draw)->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF 0.01 // ehalmkro // 2020")) == NULL)
	{
		perror ("Error: ");
		exit (1);
	}
	(*draw)->zoom = 15;
	(*draw)->padding_x = 200;
	(*draw)->padding_y = 200;
}

int		main(int argc, char **argv)
{
	t_map			*start;
	t_draw			*draw;

	if (argc != 2)
		ft_putendl("usage: fdf source_file");
	else
	{
		start = map_add_node(NULL);
		draw = malloc(sizeof(t_draw));
		if (read_input(argv[1], &start) == -1)
		{
			perror("Error: ");
			exit(1);
		}
		scene_find_minmax (&start, &draw);
		append_map(&start, &draw);
		if ((draw->mlx = mlx_init()) == NULL)
		{
			perror("Error: ");
			exit(1);
		}

		init_window(&draw);
		draw_window(&draw);
		zoom_matrix(&draw);
		move_matrix_pos(&draw);
		render(&start, &draw);
		mlx_hook(draw->win, 17, 0, &close_window, draw);
		mlx_hook(draw->win, 3, 0, &keypress, draw);
		mlx_loop(draw->mlx);
	}

//	LEAK TEST
//	while(1);

	return (0);
}
