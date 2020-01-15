/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/15 21:18:40 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		append_row(t_map ****start, t_map *new_row)
{
	t_map *curr;
	static int rowcount = 1;
//	int columncount = 1;

//	printf("ROW COUNT %d\n", rowcount++);
	curr = ***start;
	while (curr->down != NULL)
	{
		curr = curr->down;
//		ft_putendl("jesus aren't we going down");
	}
	if (rowcount > 1)
	{
		while (curr->right != NULL) {
			//		printf("COLUMN COUNT %d\n", columncount++);
			curr->down = new_row;
			curr = curr->right;
			new_row = new_row->right;
		}
	}
	curr->down = NULL;
}

static void     write_line(char *line, t_map ***start, int y)
{
    size_t	x;
	t_map	*curr;
	static int first;

	first = 0;
	curr = **start;
    x = 0;
    while (*line)
    {
        map_push_right(&curr, map_add_node(point_node_new(x++, y, ft_atoi(line))));
        while ((ft_isdigit(*line) == 1 || *line == '-') && *line)
            line++;
        while (ft_isdigit(*line) == 0 && *line != '-' && *line)
            line++;
    }
    append_row(&start, curr);
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

	start = malloc(sizeof(t_map));
	start->data = NULL;
	start->right = NULL;
	start->down = NULL;
	start->next = NULL;

    if (argc != 2)
        ft_putendl("usage: fdf source_file");
    else
	{
		if (read_input(argv[1], &start) == -1)
		{
			perror("Error: ");
			exit(1);
		}
		map_add_next(&start);
    	if ((mlx = mlx_init()) == NULL)
    	{
    		perror("Error: ");
    		exit(1);
    	}

	/*
	 * find_minmax(&start);
	 * draw_window(mlx, &start);
	 *
	 * */
     }

     /*
     * FOR LEAK TESTING
     *	while(1);
     */

	return (0);
}
