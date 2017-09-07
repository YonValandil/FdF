/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:08:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/07 07:19:30 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int    manage_key(int keycode, t_env *env)
{
    printf("keycode -> %d\ncoords -> %d", keycode, env->win.l);
    return (0);
}

int    main(void)
{
    t_env   env;

    env.win.l = 400;
    env.win.h = 400;
    env.win.title = "mlx 42";

    env.mlx = mlx_init();
    env.win.ptr = mlx_new_window(env.mlx, env.win.l, env.win.h, env.win.title);

    int y = 50;
    while (y++ < 150)
    {
        int x = 50;
        while (x++ < 150)
            mlx_pixel_put(env.mlx, env.win.ptr, x, y, 0x00FFFFFF);
    }

    mlx_key_hook(env.win.ptr, manage_key, &env);
    mlx_loop(env.mlx);
    return (0);
}
