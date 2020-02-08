/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:08:41 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/08 16:14:24 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		write_line(char *line, t_scene *draw, int y)
{
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (line[i])
	{
		if (y == 0 && x == 0)
		{
			draw->map->dt = new_node((float)x++, (float)y, \
			(float)ft_atoi(line), draw);
			draw->vertex_count++;
		}
		else
		{
			map_push_next(&draw->map, map_add_node(new_node((float)x++, \
			(float)y, (float)ft_atoi(&line[i]), draw)));
			draw->vertex_count++;
		}
		while (line[i] != ' ' && line[i])
			i++;
		while (line[i] == ' ' && line[i])
			i++;
	}
	draw->vertex_count % x == 0 ? 0 : ft_error(4);
}

int				read_input(char *str, t_scene *draw)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while ((get_next_line(fd, &line)) == 1)
	{
		write_line(line, draw, y);
		y++;
		free(line);
	}
	draw->vertex_count % y == 0 ? 0 : ft_error(4);
	y > 2 ? 0 : ft_error(4);
	return (0);
}
