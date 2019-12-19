/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/12/19 15:42:33 by esko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void    write_line(char *line, t_point **start, int y)
{
    int x;
    t_point *curr;

    curr = *start;
    x = 0;
    while (curr->next)
        curr = curr->next;
    while (*line)
    {
        curr = point_node_new(x, y, ft_atoi(line));
        while ((ft_isdigit(*line) == 1 || *line == '-') && *line)
            line++;
        while (ft_isdigit(*line) == 0 && *line != '-' && *line)
            line++;
        x++;
        curr = curr->next;
    }
}

static int	read_input(char *str)
{
	int		fd;
	int     y;
	char	*line;
	t_point *start;

    start = point_node_new(0, 0, 0);
    y = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while ((get_next_line(fd, &line)) == 1)
    {
	    write_line(line, &start, y);
        y++;
        free(line);
	}
    while (start->next)
    {
        printf("XYZ\n");
        printf("%d, %d, %d\n", start->x, start->y, start->z);
        start = start->next;
    }
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (read_input(argv[1]) == -1)
			perror("Error: ");
//		while(1);
	}
	return (0);
}
