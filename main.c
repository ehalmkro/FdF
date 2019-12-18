/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/12/18 19:07:35 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int count_elem(char *str)
{
	int count;

	count = 0;
	while (*str && *str != '\n')
	{
		while (*str != ' ')
			str++;
		if (*str == '\n' || !(*str))
			return(count);
		count++;
		str++;
	}
	return (count);
}

static int	**write_arr(char *str, int **tab, size_t line_count)
{
	int i;
	int j;

	i = 0;
    j = 0;

    /* TODO:
     * FIX THE FUCKING INT ARRAY ALLOCATION
     */

	tab = (int**)malloc(sizeof(int*) * line_count);
	printf("MORO");
    {
		while (*str)
		{
			tab[i][j] = (int)malloc(sizeof(int) * count_elem(str));
			while (*str != '\n')
			{
				if (*str == ' ')
					str++;
				tab[i][j] = ft_atoi(str);
				while (*str != ' ')
					str++;
				j++;
			}
			j = 0;
			i++;
		}
	}
	return (tab);
}

static int	read_input(char *str, int **tab)
{
	int		fd;
	size_t	line_count;
	char	*line;
	char    *ret;
	char    *tmp;

	tab = NULL;
	ret = ft_strnew(0);
    line_count = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while ((get_next_line(fd, &line)) == 1)
    {
        line_count++;
        tmp = ft_strjoin(ret, line);
        free(ret);
        free(line);
        ret = tmp;
	}
	printf("line count yo %zu\n", line_count);
	tab = write_arr(ret, tab, line_count);
	free(tmp);
	return (0);
}

int		main(int argc, char **argv)
{
    int **tab;

    tab = NULL;
	if (argc == 2)
	{
		if (read_input(argv[1], tab) == -1)
			perror("Error: ");
//		while(1);
	}
	return (0);
}
