/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:03 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/24 14:07:51 by ehalmkro         ###   ########.fr       */
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
# define DEFAULT_INCREMENT 5
# define ZOOM_COEFF_POS 1.15
# define ZOOM_COEFF_NEG 0.9
# define MATRIX_ROTATION_DEG 0.05
# define Z_INCREASE	5
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define MAGENTA 0xFF00FF
# define DEFAULT_COLOR BLUE
# define HEIGHT_COLOR BLUE

#define ipart_(X) ((int)(X))
#define round_(X) ((int)(((double)(X))+0.5))
#define fpart_(X) (((double)(X))-(double)ipart_(X))
#define rfpart_(X) (1.0-fpart_(X))

typedef struct				s_point
{
	double					x;
	double					y;
	double					z;
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
	t_map					*map;
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
	int 					window_text_color;
	void					(*draw_algorithm)(t_point start, t_point end, struct s_draw *draw);
	double 					slope;
	int 					steep;
}							t_scene;


int				read_input(char *str, t_map **start);




t_point			*point_node_new(float x, float y, float z);
void			*draw_window(t_scene **draw);
void			scene_find_minmax (t_scene *draw);
double 			get_percent(int start, int end, int curr);

void			append_map(t_map **start, t_scene **draw);


void      		map_push_right(t_map **start, t_map *new);
t_map			*map_add_node(t_point *data);

void			draw_line_wu(t_point start, t_point end, t_scene *draw);
void 			draw_line_bresenham(t_point start, t_point end, t_scene *draw);
void			draw_line_gupta_sproull(t_point start, t_point end, t_scene *draw);

void			draw_matrix(t_map *start, t_scene *draw);

int				set_color(t_point *data, t_scene *draw);
void			render(t_map **start, t_scene **draw);

int				close_window(void *param);
int				keypress(int keycode, void *param);



int 			get_gradient(int start_color, int end_color, double percentage);
int 			get_color_rgb(int r, int g, int b);

int 			*split_color(int color);
int 			decrease_brightness(int color, double brightness);


void			center_map(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw);
void 			transform_isometric(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw);
void			rotate_z(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw);
void			move_matrix_pos(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw);
void			zoom_matrix(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw);
void			modify_z(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw);

void			color_z(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw);

int				weighted_average(int first, int second, double percentage);

void			matrix_transformation(t_scene *draw, void (*transformation)(t_point *data, double prev_x, double prev_y,\
				double prev_z, t_scene *draw));

#endif
