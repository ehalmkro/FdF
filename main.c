/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/20 13:22:51 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		draw->zoom = 25;
		draw->padding_x = 200;
		draw->padding_y = 200;
		if (read_input(argv[1], &start) == -1)
		{
			perror("Error: ");
			exit(1);
		}
		find_minmax(&start, &draw);
		append_map(&start, &draw);
		if ((draw->mlx = mlx_init()) == NULL)
		{
			perror("Error: ");
			exit(1);
		}
		if ((draw->win = mlx_new_window(draw->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF 0.01 // ehalmkro // 2020")) == NULL)
		{
			perror ("Error: ");
			exit (1);
		}

		draw_window(&draw);
		zoom_matrix (&start, &draw);
		draw_matrix(start, draw);
		event_loop(&start, &draw);
		mlx_loop(draw->mlx);
	}

//	LEAK TEST
//	while(1);

	return (0);
}
