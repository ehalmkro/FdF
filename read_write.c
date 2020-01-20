/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:08:41 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/20 11:22:45 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//	TODO: FIX INPUT READ: MOVING POINTER CAUSING LEAKS

static void	write_line(char *line, t_map ***start, int y)
{
	t_map *curr;
	int x;

	x = 0;
	curr = **start;
	while (*line)
	{
		if (y == 0 && curr->data == NULL)
			curr->data = point_node_new((float)x++, (float)y, (float)ft_atoi(line));
		else
			map_push_right(&curr, map_add_node(point_node_new((float)x++, (float)y, (float)ft_atoi(line))));
		while ((ft_isdigit(*line) == 1 || *line == '-') && *line)
			line++;
		while (ft_isdigit(*line) == 0 && *line != '-' && *line)
			line++;
	}
}

int	read_input(char *str, t_map **start)
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