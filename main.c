/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:49 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/12/17 17:05:23 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_read(char *str, char **ret)
{
	int		fd;
	char	*line;
	int		**ret;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
/*	TODO:
**	READ INPUT LINE BY LINE AND CHECK THE INPUT: SHOULD ONLY CONTAIN NUMBERS AND EVERYLINE SHOULD HAVE THE SAME
**	LENGTH. AFTER VALIDATING THE INPUT FORM AN INTEGER ARRAY OUT OF IT (WITH ATOI)
*/

	while ((get_next_line(fd, line)) == 1)
    {

	}

}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_read(argv[1]) == -1)
			perror("Error: ")
	}
}
