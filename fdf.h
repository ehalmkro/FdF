/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:03 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/02/07 19:55:06 by ehalmkro         ###   ########.fr       */
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
# define Z_INCREASE	1.15
# define Z_DECREASE	0.9

# define BROWN 0x5b180c
# define PEACH 0xe65d3e
# define PINK 0xf1a26d
# define LEMON 0xfeda4b
# define LIGHTYELLOW 0xfefba8

typedef enum
{
	ISOMETRIC,
	PARALLEL
}	t_proj;

typedef enum
{
	HI,
	LO,
	ZERO,
}	t_height;

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
	t_height			height;
}						t_point;

typedef struct			s_map
{
	t_point				*dt;
	struct s_map		*rt;
	struct s_map		*dn;
	struct s_map		*nxt;
}						t_map;

typedef struct			s_mouse
{
	int					x;
	int					prev_x;
	int					y;
	int					prev_y;
	int					button_press;
}						t_mouse;

typedef struct			s_line {
	t_point				*delta;
	int					steep;
	float				gradient;
	int					x_end;
	int					y_end;
	float				y_isct;
	float				x_gap;
}						t_line;

typedef struct			s_scene
{
	t_map				*map;
	t_mouse				*mouse;
	t_proj				projection;
	void				*mlx;
	void				*win;
	int					c_dir[3][3];
	int					color[4];
	int					carousel;
	float				zoom;
	float				max_x;
	float				max_y;
	float				max_z;
	float				min_z;
	float				padding_x;
	float				padding_y;
	void				(*draw_algorithm)(t_point start, t_point end, \
						struct s_scene *draw);
	int					debug;
	size_t				vertex_count;
	long				prev_time[2];

}						t_scene;

int						read_input(char *str, t_scene *draw);

void					draw_window(t_scene *draw);
void					scene_find_minmax (t_scene *draw);
float					get_percent(int start, int end, int curr);
void					center_origo(t_scene *draw);

void					map_push_next(t_map **start, t_map *new);
t_point					*new_node(float x, float y, float z, t_scene *draw);
t_map					*map_add_node(void *data);
void					append_map(t_scene *draw);

void					draw_line_bresenham(t_point start, t_point end, \
						t_scene *draw);
void					draw_line_wu(t_point start, t_point end, t_scene *draw);
void					draw_matrix(t_map *start, t_scene *draw);
void					put_pixel(float x, float y, int color, t_scene *draw);
void					event_handler(t_scene *draw);
void					render(t_scene *draw);

void					swap_height(t_height *a, t_height *b);
void					endpoint_swap(t_point *start, t_point *end, \
						t_line *line);
float					decimal_part(float x);
float					offset_part(float x);

int						mouse_press(int button, int x, int y, void *param);
int						mouse_release(int button, int x, int y, void *param);
int						mouse_move(int x, int y, void *param);
int						close_window(void *param);
int						keypress(int keycode, void *param);

int						set_grd(t_map *start_end, t_point delta, \
						t_point current, t_scene draw);
int						*split_color(int color);
int						set_light(int color, float brightness);
int						combine_color(int r, int g, int b);
void					switch_color(t_scene *draw);
void					change_palette(t_scene *draw);
void					init_c_dir(t_scene *draw);

void					matrix_transformation(t_scene *draw, \
void					(*transformation)(t_point *data, t_point vertex, \
						t_scene *draw, float deg), float deg);
void					rot_x(t_point *data, t_point vertex, t_scene *draw, \
						float deg);
void					rot_y(t_point *data, t_point vertex, t_scene *draw, \
						float deg);
void					rot_z(t_point *data, t_point vertex, t_scene *draw, \
						float deg);
void					zoom_matrix(t_point *data, t_point vertex, \
						t_scene *draw, float deg);

void					text_carousel(t_scene *draw);
void					debug_lines(t_scene *draw);
int						window_idle(void *param);
int						timer(t_scene *draw, size_t ticks, int index);

void					ft_error(int error_code);
#endif
