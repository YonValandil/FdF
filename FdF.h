/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:40:59 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/08 09:11:42 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FdF_H
# define FdF_H

# include "mlx.h"
# include "libft.h"

# include <stdio.h> //
# define BLANK 0x00FFFFFF

typedef struct		s_coords
{
	int				x;
	int				y;
}					t_coords;

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
    unsigned int	color;
	void			*mlx;
    struct s_coords coords;
	struct s_img	img;
    struct s_win	win;
}                   t_env;

int		manage_key();
//int		manage_mouse();
//int		manage_expose();

#endif
