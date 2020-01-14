/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/14 11:26:26 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void     write_line(char *line, t_point **start, int y)
{
    int x;

    x = 0;
    if (y == 0)
    {
        *start = point_node_new(0, 0, ft_atoi(line));
        while ((ft_isdigit(*line) == 1 || *line == '-') && *line)
            line++;
        while (ft_isdigit(*line) == 0 && *line != '-' && *line)
            line++;
    }
    while (*line)
    {
        point_node_pushback(start, point_node_new(x++, y, ft_atoi(line)));
        while ((ft_isdigit(*line) == 1 || *line == '-') && *line)
            line++;
        while (ft_isdigit(*line) == 0 && *line != '-' && *line)
            line++;
    }
}

static int	read_input(char *str, t_point **start)
{
	int	fd;
	int     y;
	char	*line;

	y = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while ((get_next_line(fd, &line)) == 1)
    	{
		write_line(line, start, y);
        	y++;
        	free(line);
	}

/*
 * LIST DEBUGGING
	t_point *debug;
	debug = *start;
    while (debug->next)
    {
        printf("XYZ\n");
        printf("%d, %d, %d\n", debug->x, debug->y, debug->z);
        debug = debug->next;
    }
        printf("%d, %d, %d\n", debug->x, debug->y, debug->z);
*/

	return (0);
}

int		main(int argc, char **argv)
{	
	void	*mlx;
	t_point *start;
    
    if (argc != 2)
        ft_putendl("usage: fdf source_file");
    else
	{
		if (read_input(argv[1], &start) == -1)
		{
			perror("Error: ");
			exit(1);
		}
    	if ((mlx = mlx_init()) == NULL)
    	{
    		perror("Error: ");
    		exit(1);
    	}
    	find_minmax(&start);
    	draw_window(mlx, &start);
     }

     /*
     * FOR LEAK TESTING
     *	while(1);
     */

	return (0);
}
