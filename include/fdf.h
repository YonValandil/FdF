/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:40:59 by jjourne           #+#    #+#             */
/*   Updated: 2017/12/10 19:42:41 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include </usr/local/include/mlx.h>
# include "libft.h"
# include <math.h>
# include "get_next_line.h"

# define BLANK			0x00FFFFFF
# define BLUE			0x000000FF
# define GREEN			0x0000FF00
# define RED			0x00FF0000
# define RANGE_MAP		10000
# define RANGE_HEIGHT	20000
# define HEIGHT			600
# define WIDTH			910
# define HEIGHT_IMG		600
# define WIDTH_IMG		910

# if defined(linux) || defined(__linux) || defined(__linux__)
#  define UP			65362
#  define DOWN			65364
#  define LEFT			65361
#  define RIGHT			65363
#  define R_UP			122
#  define R_DOWN		115
#  define R_LEFT		113
#  define R_RIGHT		100
#  define ZOOM_IN		116
#  define ZOOM_OUT		103
#  define UP_Z			121
#  define DOWN_Z		104
#  define ESCAPE		65307
#  define RESET			32
# elif defined(__APPLE__)
#  define UP			126
#  define DOWN			125
#  define LEFT			123
#  define RIGHT			124
#  define R_UP			13
#  define R_DOWN		1
#  define R_LEFT		0
#  define R_RIGHT		2
#  define ZOOM_IN		17
#  define ZOOM_OUT		5
#  define UP_Z			16
#  define DOWN_Z		4
#  define ESCAPE		53
#  define RESET			49
# endif

typedef struct			s_coords
{
	int					x;
	int					y;
	unsigned int		color;
}						t_coords;

typedef struct			s_line
{
	int					dx;
	int					dy;
	int					incr_x;
	int					incr_y;
	int					err;
	t_coords			p1;
	t_coords			p2;

}						t_line;

typedef struct			s_img
{
	int					l;
	int					h;
	int					bpp;
	int					size_line;
	int					endian;
	void				*ptr;
	char				*data;
}						t_img;

typedef struct			s_win
{
	int					l;
	int					h;
	void				*ptr;
	char				*title;
}						t_win;

typedef struct			s_env
{
	void				*mlx;
	size_t				nbr_line;
	size_t				nbr_col;
	int					height;
	int					scalex;
	int					scaley;
	int					posx;
	int					posy;
	size_t				check;
	size_t				check2;
	struct s_img		img;
	struct s_win		win;
	struct s_list		*map;
}						t_env;

void					exit_error(const char *s);
void					del_map(void *map, size_t size);
size_t					arrlen(void **arr);
void					arrdel(void ***arr);
void					set_env(t_env *env);
void					set_img(t_env *env);
void					set_string(t_env *env);
void					parse(t_env *env, char *buff);
void					parse_grid(t_env *env, char **grid, int *tmp);
void					projection(t_env *env);
void					projection_content(t_env *env, t_list *curr,
	size_t i, size_t j);
void					put_pixel_img(t_env *env, t_coords p);
t_coords				set_pixel(int x, int y, int color);
void					draw_line(t_env *env, t_coords p0, t_coords p1);
void					draw_map_iso(t_env *env, t_coords p0,
	t_coords p1, t_coords z);
int						controller(int keycode, void *param);
void					height(int keycode, t_env *env);
void					scale(int keycode, t_env *env);
void					translate(int keycode, t_env *env);
void					rotate(int keycode, t_env *env);
void					reset(t_env *env);
void					free_parse(char **grid, int *tmp);
void					ret_value(int ret);
void					check_nbr_line(t_env *env);

#endif
