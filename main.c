/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:08:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/08 09:50:54 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int    manage_key(int keycode, t_env *env)
{
    printf("keycode= %d\ncoords x= %d/ncoordsy= %d\n",
        keycode, env->win.l, env->win.h);
    return (0);
}

/*int     manage_mouse(int button, int  x, int y, t_env *env)
{
    return(0);
}*/

/*int     manage_expose(t_env *env)
{
    return (0);
}*/

void	test_droite(int x1, int y1, int x2, int y2, t_env env)
{
    int     x;

    x = x1;
    while (x <= x2)
    {
        mlx_pixel_put(env.mlx, env.win.ptr, x, y1 + ((y2 - y1) * (x - x1) / (x2 - x1)), BLANK);
        x++;
    }
}
int     main(void)
{
    t_env   env;

    env.win.l = 400;
    env.win.h = 400;
    env.win.title = ft_strdup("mlx 42");

    env.mlx = mlx_init();
    env.win.ptr = mlx_new_window(env.mlx, env.win.l, env.win.h, env.win.title);
    //(unsigned int) =  mlx_get_color_value(env.mlx, env.color);

    //creer une image:
    //env.img.ptr =  mlx_new_image(env.mlx, env.img.l, env.img.h);
    //la remplir:
    //env.img.data = mlx_get_data_addr(env.img.ptr, int *bit_per_pixels, int *size_line, int *endian);
    //l'afficher:
    //mlx_put_image_to_window(env.mlx, env.win.ptr, env.img.ptr, env.coords.x, env.coords.y);

    test_droite(150, 150, 200, 200, env);
    test_droite(200, 200, 220, 150, env);
    test_droite(((((200 + 150) / (200 + 160)) * (200 + 220)) - 20),
                          ((((200 + 150) / (200 + 160)) * (200 + 150)) - 200), 160, 160, env);

    ft_putnbr((((200 + 150) / (200 + 160)) * (200 + 150)) - 200);

    //mlx management event
    mlx_key_hook(env.win.ptr, manage_key, &env);
    //mlx_mouse_hook(env.win.ptr, manage_mouse, &env);
    //mlx_expose_hook(env.win.ptr, manage_expose, &env);

    //mlx execution
    mlx_loop(env.mlx);
    return (0);
}
