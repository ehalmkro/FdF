/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:03 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/01/27 15:32:17 by ehalmkro         ###   ########.fr       */
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
# define DEFAULT_COLOR GREEN
# define HEIGHT_COLOR MAGENTA

#define ipart_(X) ((int)(X))
#define round_(X) ((int)(((double)(X))+0.5))
#define fpart_(X) (((double)(X))-(double)ipart_(X))
#define rfpart_(X) (1.0-fpart_(X))

typedef enum
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

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

typedef struct				s_mouse
{
	int						x;
	int 					prev_x;
	int						y;
	int 					prev_y;
	int 					button_press;
}							t_mouse;

typedef struct				s_scene
{
	t_map					*map;
	t_mouse 				*mouse;
	int 					projection;
	void					*mlx;
	void					*win;
	float 					zoom;
	float 					max_x;
	float 					max_y;
	float 					max_z;
	float 					min_z;
	float 					padding_x;
	float 					padding_y;
	float 					padding_z;
	int 					window_text_color;
	void					(*draw_algorithm)(t_point start, t_point end, struct s_scene *draw);
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
void 			draw_line_wu_alternate(t_point start, t_point end, t_scene *draw);

void			draw_matrix(t_map *start, t_scene *draw);

int				set_color(t_point *data, t_scene *draw);
void			render(t_map **start, t_scene **draw);

int				close_window(void *param);
int				keypress(int keycode, void *param);



int 			get_gradient(int start_color, int end_color, double percentage);
int 			get_color_rgb(int r, int g, int b);

int 			*split_color(int color);
int 			decrease_brightness(int color, double brightness);


void			center_map(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg);
t_point 		*transform_isometric(t_point *data);
void			rotate_z(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg);
void			rotate_x(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg);
void			rotate_y(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg);
void			move_matrix_pos(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg);
void			zoom_matrix(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg);
void			modify_z(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw, double deg);
void 			correct_axis(t_point *start, t_point *end, t_scene *draw);

void			put_pixel(double x, double y, int color, t_scene *draw);

int				mouse_move(int x, int y, void *param);


void			color_z(t_point *data, double prev_x, double prev_y, double prev_z, t_scene *draw);

int				weighted_average(int first, int second, double percentage);

void			matrix_transformation(t_scene *draw, void (*transformation)(t_point *data, double prev_x, double prev_y,\
				double prev_z, t_scene *draw, double deg), double deg);

int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);


#endif
