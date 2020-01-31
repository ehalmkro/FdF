/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:08:41 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/31 15:52:44 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO: dupliocate minmax check remove

static void 	validate_input(t_scene *draw)
{
	t_map *map;

	map = draw->map;
	scene_find_minmax(draw);
	while (map)
	{
		!(map->right) && map->data->x < draw->max_y ? ft_error(4) : 0;

	}


}

static void		write_line(char *line, t_scene *draw, int y)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (line[i])
	{
		if (y == 0 && x == 0)
			draw->map->data = point_node_new((float) x++,(float) y, (float)ft_atoi(line), draw);
		else
			map_push_right(&draw->map, map_add_node(point_node_new((float)x++, (float)y, (float)ft_atoi(&line[i]), draw)));
		while ((ft_isdigit(line[i]) == 1 || line[i] == '-') && line[i])
			i++;
		while (ft_isdigit(line[i]) == 0 && line[i] != '-' && line[i])
			i++;
	}
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
	return (0);
}