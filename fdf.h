/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:03 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/20 11:09:54 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct				s_point
{
	float					x;
	float					y;
	float					z;
	int 					color;
}							t_point;

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
	void					*mlx;
	void					*win;
	float 					max_x;
	float 					max_y;
	float 					max_z;
	float 					min_z;
	float 					padding_x;
	float 					padding_y;
	float 					padding_z;
}							t_draw;

int				read_input(char *str, t_map **start);




t_point			*point_node_new(float x, float y, float z);
void			*draw_window(t_map **start, t_draw **draw);
void			find_minmax(t_map **start, t_draw **draw);
double 			get_percent(int start, int end, int curr);

void			append_map(t_map **start, t_draw **draw);

void      		map_push_right(t_map **start, t_map *new);
t_map			*map_add_node(t_point *data);

void			draw_line(t_point *start, t_point *end, void *mlx, void *win);
void			draw_matrix(t_map *start, void *mlx, void *win);

int				set_color(t_point *start, t_point *end);


#endif
