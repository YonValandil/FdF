/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:08:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/22 08:37:47 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int         manage_key(int keycode, t_env *env)
{
    printf("keycode = %d\ntitle window = %s\n", keycode, env->win.title);
    return (0);
}

int       manage_mouse(int button, int  x, int y, t_env *env)
{
    printf("\nbutton : %d\ncoords: %d;%d\ntitle : %s\n",
        button, x, y, env->win.title);
    return(0);
}

int         ft_abs(int x)
{
    if(x < 0)
        x = -1 * x;
    return (x);
}

void	   set_env(t_env *env)
{
    env->win.l = LARGEUR;
    env->win.h = HAUTEUR;
    env->win.title = ft_strdup("mlx 42");

    env->img.l = LARGEUR;
    env->img.h = HAUTEUR;
}

t_coords    set_pixel(int x, int y, unsigned int color)
{
    t_coords p;

    p.x = x;
    p.y = y;
    p.color = color;

    return (p);
}

void	  draw_line(t_env env, t_coords p1, t_coords p2)
{
    t_line line;
    int incr_x;
    int incr_y;
    int err_tmp;

    line.dx = ft_abs(p2.x - p1.x);
    line.dy = ft_abs(p2.y - p1.y);
    incr_x = (p1.x < p2.x) ? 1 : -1;
    incr_y = (p1.y < p2.y) ? 1 : -1;
    line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;

    while(p1.x != p2.x && p1.y != p2.y){
        mlx_pixel_put(env.mlx, env.win.ptr, p1.x, p1.y, BLANK);
        err_tmp = line.err;
        if (err_tmp > -line.dx)
        {
            line.err -= line.dy;
            p1.x += incr_x;
        }
        if (err_tmp < line.dy)
        {
            line.err += line.dx;
            p1.y += incr_y;
        }
    }
}

int         main(void)
{
    t_env       env;

    set_env(&env);

    env.mlx = mlx_init();
    env.win.ptr = mlx_new_window(env.mlx, env.win.l, env.win.h, env.win.title);
    //(unsigned int) =  mlx_get_color_value(env.mlx, env.color);

    //creer une image:
    env.img.ptr = mlx_new_image(env.mlx, env.img.l, env.img.h);
    //la remplir:
    env.img.data = mlx_get_data_addr(env.img.ptr, int *bit_per_pixels,
        , int *endian);
    //l'afficher:
    mlx_put_image_to_window(env.mlx, env.win.ptr, env.img.ptr,
        0, 0);

    //test_droite(set_pixel(150, 150, BLANK), set_pixel(200, 200, BLANK), env);
    draw_line(env, set_pixel(0, 0, BLANK), set_pixel(400, 400, BLANK));
    draw_line(env, set_pixel(0, 200, BLANK), set_pixel(340, 0, BLANK));
    draw_line(env, set_pixel(100, 50, BLANK), set_pixel(0, 200, BLANK));
    draw_line(env, set_pixel(10, 10, BLANK), set_pixel(20, 390, BLANK));

    //mlx management event
    //mlx_hook(env.win.ptr, event, mask, ptr_fcnt, &event) //need to include X.h
    mlx_key_hook(env.win.ptr, manage_key, &env);
    mlx_mouse_hook(env.win.ptr, manage_mouse, &env);

    //mlx boucle d'execution
    mlx_loop(env.mlx);
    return (0);
}
