/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:03 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/16 15:29:38 by ehalmkro         ###   ########.fr       */
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
	float					x;
	float					y;
	float					z;
}							t_point;

typedef struct				s_max
{
	float 					max_x;
	float 					max_y;
	float 					max_z;
	float 					min_z;
}							t_max;

typedef struct				s_map
{
	t_point					*data;
	struct s_map			*right;
	struct s_map			*down;
	struct s_map			*next;
}							t_map;

typedef struct				s_draw
{
	float 					zoom;
}							t_draw;





t_point			*point_node_new(float x, float y, float z);
void			point_node_pushback(t_point **start, t_point *back);
void			draw_window(void *mlx, t_map **start);
t_max			find_minmax(t_map **start);
double 			get_percent(int start, int end, int curr);


void      		map_push_right(t_map **start, t_map *new);
t_map			*map_add_node(t_point *data);

void			map_add_next(t_map **start);

#endif
