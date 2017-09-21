/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:40:59 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/21 09:27:57 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FdF_H
# define FdF_H

# include "mlx.h"
//# include "X.h" //a ajouter dans include
# include "libft.h"

# include <stdio.h> //

# define BLANK		0x00FFFFFF
# define HAUTEUR	400
# define LARGEUR	400

/*enum e_screen
{
	LARGEUR;
	LONGUEUR;
};*/

typedef struct		s_coords
{
	int				x;
	int				y;
	unsigned int	color;
}					t_coords;

typedef struct		s_line
{
	t_coords		p1;
	t_coords		p2;
	int 			dx;
	int 			dy;
	int				m;
	
	int				sx;
	int				sy;
	int				err;

}					t_line;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				l;
	int				h;
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
t_coords 	set_pixel(int x, int y, unsigned int color);
void		draw_line(t_env, t_coords p1, t_coords p2);
int			manage_key(int keycode, t_env *env);
//int		manage_mouse();
//int		manage_expose();

#endif
