/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:40:59 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/06 09:32:51 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FdF_H
# define FdF_H

# include "mlx.h"
//# include "libft.h"

#include <stdio.h> //

typedef struct		s_coords
{
	int				x;
	int				y;
    int             color;
}					t_coords;

typedef struct		s_win
{
    int             x;
    int             y;
}                   t_win;

typedef struct		s_env
{
	void			*mlx;
    struct s_win    *win;
    struct s_coords *coords;
}                   t_env;

#endif
