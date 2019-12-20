/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/12/20 20:18:27 by esko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void     write_line(char *line, t_point **start, int y)
{
    int x;
    t_point *curr;
/* LEAKS A LOT BECAUSE OF THE MOVING POINTER
 * TODO: FIX LEAKING POINTER
 */
    x = 0;
    if (y == 0)
    {
        *start = point_node_new(x++, 0, ft_atoi(line));
        while ((ft_isdigit(*line) == 1 || *line == '-') && *line)
            line++;
        while (ft_isdigit(*line) == 0 && *line != '-' && *line)
            line++;
    }
    curr = *start;
    while (curr->next)
        curr = curr->next;
    while (*line)
    {
        curr->next = point_node_new(x, y, ft_atoi(line));
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
    printf("XYZ\n%d, %d, %d", start->x, start->y, start->z);
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
