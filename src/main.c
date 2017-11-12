/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:08:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/11/12 19:56:02 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void 		exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

size_t		arrlen(void **arr)
{
    size_t  i;
    i = 0;

    while ((unsigned char*)arr[i])
        ++i;
    return (i);
}

void		arrdel(void ***arr)
{
	void **tmp;

	if(arr && *arr)
	{
		tmp = *arr;
		while (*tmp)
		{
			ft_memdel(tmp);
			++tmp;
		}
		free(*arr);
		*arr = NULL;
	}
}

void 		del_map(void *map, size_t size)
{
	(void)size;
 	ft_memdel((void*)&map);
}

int			controller(int keycode, void *param)
{
	t_env	*env;

	env = (t_env*)param;

	if (keycode == ESCAPE)
	{
		ft_lstdel(&(env)->map, del_map);
    	exit(EXIT_SUCCESS);
	}
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		translate(keycode, env);
	if (keycode == R_UP || keycode == R_DOWN ||
		keycode == R_LEFT || keycode == R_RIGHT)
		rotate(keycode, env);
	if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		scale(keycode, env);
	if (keycode == UP_Z || keycode == DOWN_Z)
		height(keycode, env);
	if (keycode == RESET)
		reset(env);
	set_img(env);
	return (0);
}

int         main(int argc, char *argv[])
{
    t_env       env;

    if(argc != 2)
		exit_error("usage: ./FdF File");
    set_env(&env);
    env.mlx = mlx_init();
    env.win.ptr = mlx_new_window(env.mlx, env.win.l, env.win.h, env.win.title);
    if((parse(&env, argv[1])))
		exit_error("parse error");
	printMap_console(&env);
	set_img(&env);
	mlx_hook(env.win.ptr, 2, 3, controller, &env);
    mlx_loop(env.mlx);
    return (0);
}
