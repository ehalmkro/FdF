/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:03 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/12/19 13:22:35 by esko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include "Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_point
{
    int             x;
    int             y;
    int             z;
    struct s_point	*next;
}				t_point;

t_point     *point_node_new(int x, int y, int z);
void        point_node_pushback(t_point **start, t_point *back);

#endif
