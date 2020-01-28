/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:08:41 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/28 13:43:52 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//	TODO: FIX INPUT READ: MOVING POINTER CAUSING LEAKS


static void		write_line(char *line, t_scene *draw, int y)
{
	t_map *curr;
	int x;
	int i;

	x = 0;
	i = 0;
	curr = draw->map;
	while (line[i])
	{
		if (y == 0 && curr->data == NULL)
			curr->data = point_node_new((float)x++, (float)y, (float)ft_atoi(line), draw);
		else
			map_push_right(&curr, map_add_node(point_node_new((float)x++, (float)y, (float)ft_atoi(&line[i]), draw)));
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