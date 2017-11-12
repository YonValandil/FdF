/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:40:59 by jjourne           #+#    #+#             */
/*   Updated: 2017/10/13 06:30:49 by yon              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FdF_H
# define FdF_H

# include </usr/local/include/mlx.h>
# include "libft.h"
# include <math.h>
# include "get_next_line.h"
# include <stdio.h> //

# define BLANK			0x00FFFFFF
# define BLUE			0x000000FF
# define GREEN			0x0000FF00
# define RED			0x00FF0000
# define HAUTEUR		600
# define LARGEUR		910
# define HAUTEUR_IMG	600
# define LARGEUR_IMG	910

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
# endif

typedef struct		s_coords
{
	int				x;
	int				y;
	unsigned int	color;
}					t_coords;

typedef struct		s_line
{
	int 			dx;
	int 			dy;
	int				incr_x;
	int				incr_y;
	int				err;
	t_coords		p1;
	t_coords		p2;

}					t_line;

typedef struct		s_img
{
	int				l;
	int				h;
	int				bpp;
	int				size_line;
	int				endian;
	void			*ptr;
	char			*data;
}                   t_img;

typedef struct		s_win
{
    int             l;
    int             h;
	void			*ptr;
	char			*title;
}                   t_win;

typedef struct		s_env
{
	void			*mlx;
	size_t			nbr_line;
	size_t			nbr_col;
	int				height;
	int				scalex;
	int				scaley;
	int				posx;
	int				posy;
	struct s_img	img;
    struct s_win	win;
	struct s_list	*map;
}                   t_env;

void 		exit_error(const char *s);
size_t		arrlen(void **arr);
void		arrdel(void ***arr);
void		set_env(t_env *env);
void 		set_img(t_env *env);
void 		set_string(t_env *env);
int			parse(t_env *env, char *buff);
void		projection(t_env *env);
void		put_pixel_img(t_env *env, t_coords p);
t_coords 	set_pixel(int x, int y, int color);
void		draw_line(t_env *env, t_coords p0, t_coords p1, t_coords z);
void 		draw_map_iso(t_env *env, t_coords p0, t_coords p1, t_coords z);
int			controller(int keycode, void *param);
void 		height(int keycode, t_env *env);
void 		scale(int keycode, t_env *env);
void 		translate(int keycode, t_env *env);
void 		rotate(int keycode, t_env *env);
void 		reset(t_env *env);

#endif
