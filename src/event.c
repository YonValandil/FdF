#include "FdF.h"

void 		height(int keycode, t_env *env)
{
	if (keycode == UP_Z_M || keycode == UP_Z_L)
	{
		env->height += 1;
		printf("\ndown_z\n");
	}
	if (keycode == DOWN_Z_M || keycode == DOWN_Z_L)
	{
		env->height -= 1;
		printf("\nup_z\n");
	}
}

void 		scale(int keycode, t_env *env)
{
	if (keycode == ZOOM_IN_M || keycode == ZOOM_IN_L)
	{
		env->scalex += 2;
		env->scaley += 1;
		printf("\nzoom up\n");
	}
	if (keycode == ZOOM_OUT_M|| keycode == ZOOM_OUT_L)
	{
		env->scalex -= 2;
		env->scaley -= 1;
		printf("\nzoom down\n");
	}
}

void 		translate(int keycode, t_env *env)
{
	if (keycode == UP_M || keycode == UP_L)
	{
		printf("\nup\n");
		env->posy -= 7;
	}
	if (keycode == DOWN_M || keycode == DOWN_L)
	{
		printf("\ndown\n");
		env->posy += 7;
	}
	if (keycode == LEFT_M || keycode == LEFT_L)
	{
		printf("\nleft\n");
		env->posx -=7;
	}
	if (keycode == RIGHT_M || keycode == RIGHT_L)
	{
		printf("\nright\n");
		env->posx +=7;
	}
}

void 		reset(t_env *env)
{
	printf("\nreset - spacebar\n");
	env->height = 5;
	env->scalex = 30;
	env->scaley = 15;
	env->posx = (LARGEUR_IMG / 2) + 125;
	env->posy = 100;
}
