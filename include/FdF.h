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

# define HAUTEUR		700
# define LARGEUR		950
# define HAUTEUR_IMG	700
# define LARGEUR_IMG	950

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
	struct s_img	img;
    struct s_win	win;
	struct s_list	*map;
}                   t_env;

int			abs(int x);
size_t		ft_arrlen(void **arr);
void		ft_lstadd_end(t_list **alist, t_list *new);
void		set_env(t_env *env);
void 		set_img(t_env *env);
int			parse(t_env *env, char *buff);
void		projection(t_env *env);//
void		put_pixel_img(t_env *env, t_coords p);
t_coords 	set_pixel(int x, int y, unsigned int color);
void		draw_line(t_env *env, t_coords p1, t_coords p2);
void 		draw_map_iso(t_env *env, t_coords p1, t_coords p2, t_coords z);
int			controller(void *param, int keycode);
void 		refresh_img(t_env *env);
int			manage_key(int keycode, t_env *env);
int			manage_mouse(int button, int x, int y, t_env *env);

#endif
