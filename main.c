/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/12/18 18:09:44 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int count_elem(char *str)
{
	int count;

	cunt = 0;
	while (*str && *str != '\n')
	{
		if (*str != ' ')


	}

}


static int	**write_arr(char *str, int **tab, size_t line_count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	tab[i] = (int*)malloc(sizeof(int*) * line_count);
	tab[i][j] = (int)malloc(sizeof(int) * elem_count);


}
static int	read_input(char *str, int **tab)
{
	int		fd;
	size_t	line_number;
	char	*line;
	char    *ret;
	char    *tmp;

	ret = ft_strnew(0);
    line_number = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while ((get_next_line(fd, &line)) == 1)
    {
        line_number++;
        tmp = ft_strjoin(ret, line);
        free(ret);
        free(line);
        ret = tmp;
	}
	tab =
	free(tmp);
	return (0);
}

int		main(int argc, char **argv)
{
    int **tab;

	if (argc == 2)
	{
		if (ft_read(argv[1], &tab) == -1)
			perror("Error: ");
//		while(1);
	}
	return (0);
}
