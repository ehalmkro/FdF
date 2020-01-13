/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:03 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/13 16:55:57 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "minilibx/mlx.h"

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

typedef struct		s_point
{
    int             x;
    int             y;
    int             z;
    struct s_point	*next;
}				t_point;

t_point		*point_node_new(int x, int y, int z);
void		point_node_pushback(t_point **start, t_point *back);
void		draw_window(void *mlx, t_point **start);

#endif
