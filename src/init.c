/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:58:52 by jjourne           #+#    #+#             */
/*   Updated: 2017/11/25 10:04:52 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int		controller(int keycode, void *param)
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

void	put_pixel_img(t_env *env, t_coords p)
{
	int r;
	int g;
	int b;

	r = (p.color & 0xFF0000) >> 16;
	g = (p.color & 0xFF00) >> 8;
	b = (p.color & 0xFF);
	if (p.y >= 0 && p.x >= 0 && p.y < HEIGHT_IMG && p.x < WIDTH_IMG)
	{
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x) + 2] = r;
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x) + 1] = g;
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x)] = b;
	}
}

void	set_string(t_env *env)
{
	mlx_string_put(env->mlx, env->win.ptr, 20, 20, GREEN,
		"press ESC: QUIT");
	mlx_string_put(env->mlx, env->win.ptr, 20, 40, GREEN,
		"press SPACE: RESET");
	mlx_string_put(env->mlx, env->win.ptr, 220, 20, GREEN,
		"press T: ZOOM UP");
	mlx_string_put(env->mlx, env->win.ptr, 220, 40, GREEN,
		"press G: ZOOM DOWN");
	mlx_string_put(env->mlx, env->win.ptr, 420, 20, GREEN,
		"press Y: UP_Z");
	mlx_string_put(env->mlx, env->win.ptr, 420, 40, GREEN,
		"press H: DOWN_Z");
	mlx_string_put(env->mlx, env->win.ptr, 620, 20, GREEN,
		"USE: ARROWS for MOVE");
}

void	set_img(t_env *env)
{
	env->img.ptr = mlx_new_image(env->mlx, env->img.l, env->img.h);
	env->img.data = mlx_get_data_addr(env->img.ptr, &env->img.bpp,
		&env->img.size_line, &env->img.endian);
	mlx_clear_window(env->mlx, env->win.ptr);
	projection(env);
	mlx_put_image_to_window(env->mlx, env->win.ptr, env->img.ptr, 0, 0);
	set_string(env);
	mlx_destroy_image(env->mlx, env->img.ptr);
}

void	set_env(t_env *env)
{
	env->win.l = WIDTH;
	env->win.h = HEIGHT;
	env->win.title = ft_strdup("mlx 42 FdF");
	env->img.l = WIDTH_IMG;
	env->img.h = HEIGHT_IMG;
	env->map = NULL;
	env->nbr_line = 0;
	env->nbr_col = 0;
	env->height = 5;
	env->scalex = 30;
	env->scaley = 15;
	env->posx = (WIDTH_IMG / 2) + 125;
	env->posy = 100;
}
