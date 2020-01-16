/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/16 17:20:35 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map *get_next_y(t_map *start, float y)
{
	t_map *ret;

	ret = start;
	while (ret->data->y == y && ret)
		ret = ret->next;
	return(ret);
}

static void	append_map(t_map **start, t_max minmax)
{
	t_map *tapehead;
	t_map *forward;
	float y;
	tapehead = *start;

	while (y < minmax.max_y - 1)
	{
		y = tapehead->data->y;
		forward = get_next_y(tapehead, y);
		tapehead->down = forward;
		if (y >= tapehead->next->data->y)
			tapehead->right = tapehead->next;
		tapehead = tapehead->next;
	}
}

static void	write_line(char *line, t_map ***start, int y)
{
  t_map *curr;
  int x;

  x = 0;
  curr = **start;
  while (*line)
  {
	if (y == 0 && curr->data == NULL)
		curr->data = point_node_new(x++, y, ft_atoi(line));
	else
		map_push_right(&curr, map_add_node(point_node_new(x++, y, ft_atoi(line))));
	while ((ft_isdigit(*line) == 1 || *line == '-') && *line)
		line++;
	  while (ft_isdigit(*line) == 0 && *line != '-' && *line)
		line++;
  }
}

static int	read_input(char *str, t_map **start)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while ((get_next_line(fd, &line)) == 1)
	{
		write_line(line, &start, y);
		y++;
		free(line);
	}

	return (0);
}

int		main(int argc, char **argv)
{
	void			*mlx;
	t_map			*start;
	t_max			maxvalues;

	start = map_add_node(NULL);
	if (argc != 2)
		ft_putendl("usage: fdf source_file");
	else
	{
		if (read_input(argv[1], &start) == -1)
		{
			perror("Error: ");
			exit(1);
		}
		maxvalues = find_minmax(&start);
		append_map(&start, maxvalues);
		if ((mlx = mlx_init()) == NULL)
		{
			perror("Error: ");
			exit(1);
		}
		draw_window(mlx, &start);
	}

	 /*
	 * FOR LEAK TESTING
	 *	while(1);
	 */

	 	while (start)
	{
		printf ("DATA\nX %f\nY %f\nZ %f\n", start->data->x, start->data->y, start->data->z);
		start = start->down;
	}


	return (0);
}
