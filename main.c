/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:08:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/06 11:14:20 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int    my_key_funct(int keycode/*, void *param*/) // struct mlx dans param
{
    printf("keycode -> %d\n", keycode);
    return (0);
}

int    main(void)
{
    t_env   env;

    env.mlx = mlx_init();
    env.win = mlx_new_window(env.mlx, 400, 400, "mlx 42");

    int y = 50;
    while (y++ < 150)
    {
        int x = 50;
        while (x++ < 150)
            mlx_pixel_put(env.mlx, env.win, x, y, 0x00FFFFFF);
    }

    mlx_key_hook(env.win, my_key_funct, 0); //struct mlx au lieu de 0
    mlx_loop(env.mlx);
    return (0);
}
