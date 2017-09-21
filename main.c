/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:08:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/21 09:29:25 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int         manage_key(int keycode, t_env *env)
{
    printf("keycode = %d\ntitle window = %s\n", keycode, env->win.title);
    return (0);
}

/*int       manage_mouse(int button, int  x, int y, t_env *env)
{
    return(0);
}*/

/*int       manage_expose(t_env *env)
{
    return (0);
}*/

void	   test_droite(t_coords p1, t_coords p2, t_env env)
{
    int     x;

    x = p1.x;
    while (x <= p2.x)
    {
        mlx_pixel_put(env.mlx, env.win.ptr, x,
            p1.y + ((p2.y - p1.y) * (x - p1.x) / (p2.x - p1.x)), BLANK);
        x++;
    }
}

int         ft_abs(int x)
{
    if(x < 0)
        x = -1 * x;
    return (x);
}

void	   set_env(t_env *env)
{
    env->win.l = HAUTEUR;
    env->win.h = LARGEUR;
    env->win.title = ft_strdup("mlx 42");
}

t_coords    set_pixel(int x, int y, unsigned int color)
{
    t_coords p;

    p.x = x;
    p.y = y;
    p.color = color;

    return (p);
}

/*void	   draw_line(t_env env, t_coords p1, t_coords p2)
{
    t_line  line;
    float   y;
    int     x;

    line.dx = ft_abs(p2.x - p1.x);
    line.dy = ft_abs(p2.y - p1.y);
    line.m = (line.dy / line.dx) * 2;
    y = 0;
    x = -1;

    printf("\ndx = %d\ndy = %d\nm = %d\n", line.dx, line.dy, line.m);

    while (++x < p2.x)
    {
        y = line.m * x + p1.y + 0.5;
        mlx_pixel_put(env.mlx, env.win.ptr, x, y, BLANK);
        printf("y = %f\n", y);
    }
}*/

void	  draw_line(t_env env, t_coords p1, t_coords p2)
{
    t_line line;
    int sx;
    int sy;
    line.dx = ft_abs(p2.x - p1.x);
    line.dy = ft_abs(p2.y - p1.y);
    sx = p1.x < p2.x ? 1 : -1;
    sy = p1.y < p2.y ? 1 : -1;
    int err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
    int e2;

    while(1){
        mlx_pixel_put(env.mlx, env.win.ptr, p1.x, p1.y, BLANK);
        if (p1.x == p2.x && p1.y == p2.y)
            break;
        e2 = err;
        if (e2 > -line.dx)
        {
            err -= line.dy;
            p1.x += sx;
        }
        if (e2 < line.dy)
        {
            err += line.dx;
            p1.y += sy;
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
    //env.img.ptr =  mlx_new_image(env.mlx, env.img.l, env.img.h);
    //la remplir:
    //env.img.data = mlx_get_data_addr(env.img.ptr, int *bit_per_pixels, int *size_line, int *endian);
    //l'afficher:
    //mlx_put_image_to_window(env.mlx, env.win.ptr, env.img.ptr, env.coords.x, env.coords.y);

    //test_droite(set_pixel(150, 150, BLANK), set_pixel(200, 200, BLANK), env);
    draw_line(env, set_pixel(0, 0, BLANK), set_pixel(400, 400, BLANK));
    draw_line(env, set_pixel(0, 200, BLANK), set_pixel(340, 0, BLANK));
    draw_line(env, set_pixel(100, 50, BLANK), set_pixel(0, 200, BLANK));
    draw_line(env, set_pixel(10, 10, BLANK), set_pixel(20, 390, BLANK));

    //mlx management event
    //mlx_hook(env.win.ptr, event, mask, ptr_fcnt, &event) //need to include X.h
    mlx_key_hook(env.win.ptr, manage_key, &env);
    //mlx_mouse_hook(env.win.ptr, manage_mouse, &env);
    //mlx_expose_hook(env.win.ptr, manage_expose, &env);

    //mlx boucle d'execution
    mlx_loop(env.mlx);
    return (0);
}
