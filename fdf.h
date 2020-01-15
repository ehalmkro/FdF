/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:03 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/15 12:49:05 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct				s_point
{
	int						x;
	int						y;
	int						z;
}							t_point;

typedef struct				s_max
{
	int 					max_x;
	int 					max_y;
	int 					max_z;
	int 					min_z;
}							t_max;

typedef struct				s_map
{
	t_point					data;
	struct t_map			*right;
	struct t_map			*down;
}							t_map;

typedef struct				s_draw
{
	int 					zoom;
}							t_draw;





t_point		point_node_new(int x, int y, int z);
void		point_node_pushback(t_point **start, t_point *back);
void		draw_window(void *mlx, t_point **start);
t_max		find_minmax(t_point **start);
double 		get_percent(int start, int end, int curr);

#endif
