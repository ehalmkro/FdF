/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/17 18:37:56 by ehalmkro         ###   ########.fr       */
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
	float x;
	tapehead = *start;

	x = 0;
	y = 0;
	while (y < minmax.max_y - 1)
	{
		y = tapehead->data->y;
		forward = get_next_y (tapehead, y);
		while (x < minmax.max_x)
		{
			x = tapehead->data->x;
			tapehead->down = forward;
			if (y == tapehead->next->data->y)
			{
				tapehead->right = tapehead->next;
				if (forward->next && forward->next->data->y == forward->data->y)
					forward->right = forward->next;
				forward = forward->next;
			}
			tapehead = tapehead->next;
		}
		x = 0;
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

void	draw_matrix(t_map *start, void *mlx, void *win)
{
		if (start->right)
			draw_line(start->data, start->right->data, mlx, win);
		if (start->down)
			draw_line(start->data, start->down->data, mlx, win);
		if (start->next)
			draw_matrix(start->next, mlx, win);
}

int		main(int argc, char **argv)
{
	void			*mlx;
	t_map			*start;
	void 			*win;
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
		win = draw_window(mlx, &start);
		draw_matrix (start, mlx, win);
		mlx_string_put(mlx, win, 20, 20, 0x00FF00, "X");
		mlx_string_put(mlx, win, 20, 60, 0x00FF00, "Y");
		mlx_string_put(mlx, win, 40, 20, 0x00FF00, ft_itoa((int)maxvalues.max_x));
		mlx_string_put(mlx, win, 40, 60, 0x00FF00, ft_itoa((int)maxvalues.max_y));
		mlx_loop(mlx);
	}

	 /*
	 * FOR LEAK TESTING
	 *	while(1);
	*/
	return (0);
}
