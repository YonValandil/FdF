/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:40:59 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/24 04:40:48 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FdF_H
# define FdF_H

# include "mlx.h"
//# include "X.h" //a ajouter dans include
# include "libft.h"

# include <stdio.h> //

# define BLANK			0x00FFFFFF
# define HAUTEUR		400
# define LARGEUR		400
# define HAUTEUR_IMG	400
# define LARGEUR_IMG	400

/*enum e_screen
{
	LARGEUR;
	LONGUEUR;
};*/

typedef struct		s_coords
{
	int				x;
	int				y;
	int				z;
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
	struct s_img	img;
    struct s_win	win;
}                   t_env;

int			abs(int x);
void		set_env(t_env *env);
int			parse(t_env env, char *buff);
t_coords 	set_pixel(int x, int y, unsigned int color);
void		draw_line(t_env, t_coords p1, t_coords p2);
int			manage_key(int keycode, t_env *env);
int			manage_mouse(int button, int x, int y, t_env *env);

#endif
