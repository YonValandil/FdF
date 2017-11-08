#include "FdF.h"

void	put_pixel_img(t_env *env, t_coords p)
{
	int		r;
	int		g;
	int		b;

	r = (p.color & 0xFF0000) >> 16;
	g = (p.color & 0xFF00) >> 8;
	b = (p.color & 0xFF);
	if (p.y >= 0 && p.x >= 0 && p.y < HAUTEUR_IMG && p.x < LARGEUR_IMG)
	{
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x) + 2] = r;
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x) + 1] = g;
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x)] = b;
	}
}

void 		set_img(t_env *env)
{
    env->img.ptr = mlx_new_image(env->mlx, env->img.l, env->img.h);
    env->img.data = mlx_get_data_addr(env->img.ptr, &env->img.bpp,
    	&env->img.size_line, &env->img.endian);
	mlx_clear_window(env->mlx, env->win.ptr);
	projection(env);
    mlx_put_image_to_window(env->mlx, env->win.ptr, env->img.ptr, 0, 0);
	mlx_string_put(env->mlx, env->win.ptr, 20, 20, GREEN, "press ESC: QUIT");
	mlx_string_put(env->mlx, env->win.ptr, 20, 40, GREEN, "press SPACE: RESET");
	mlx_string_put(env->mlx, env->win.ptr, 220, 20, GREEN, "press Z: ZOOM UP");
	mlx_string_put(env->mlx, env->win.ptr, 220, 40, GREEN, "press S: ZOOM DOWN");
	mlx_string_put(env->mlx, env->win.ptr, 420, 20, GREEN, "press A: UP_Z");
	mlx_string_put(env->mlx, env->win.ptr, 420, 40, GREEN, "press Q: DOWN_Z");
	mlx_string_put(env->mlx, env->win.ptr, 620, 20, GREEN, "USE: ARROWS for MOVE");
	mlx_destroy_image(env->mlx, env->img.ptr);
}

void	   set_env(t_env *env)
{
    env->win.l = LARGEUR;
    env->win.h = HAUTEUR;
    env->win.title = ft_strdup("mlx 42 FdF");

    env->img.l = LARGEUR_IMG;
    env->img.h = HAUTEUR_IMG;

	env->map = NULL;
	env->nbr_line = 0;
	env->height = 5;
	env->scalex = 30;
	env->scaley = 15;
	env->posx = (LARGEUR_IMG / 2) + 125;
	env->posy = 100;
}
