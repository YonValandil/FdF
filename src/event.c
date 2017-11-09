#include "FdF.h"

void height(int keycode, t_env *env)
{
	if (keycode == UP_Z_M || keycode == UP_Z_L)
		env->height += 1;
	if (keycode == DOWN_Z_M || keycode == DOWN_Z_L)
		env->height -= 1;
}

void rotate(int keycode, t_env *env)
{
	if (keycode == R_UP_M || keycode == R_UP_L)
		env->scaley += 2;
	if (keycode == R_DOWN_M || keycode == R_DOWN_L)
		env->scaley -= 2;
	if (keycode == R_LEFT_M || keycode == R_LEFT_L)
		env->scalex +=2;
	if (keycode == R_RIGHT_M || keycode == R_RIGHT_L)
		env->scalex -=2;
}

void scale(int keycode, t_env *env)
{
	if (keycode == ZOOM_IN_M || keycode == ZOOM_IN_L)
	{
		env->scalex += 2;
		env->scaley += 1;
	}
	if (keycode == ZOOM_OUT_M|| keycode == ZOOM_OUT_L)
	{
		env->scalex -= 2;
		env->scaley -= 1;
	}
}

void translate(int keycode, t_env *env)
{
	if (keycode == UP_M || keycode == UP_L)
		env->posy -= 7;
	if (keycode == DOWN_M || keycode == DOWN_L)
		env->posy += 7;
	if (keycode == LEFT_M || keycode == LEFT_L)
		env->posx -=7;
	if (keycode == RIGHT_M || keycode == RIGHT_L)
		env->posx +=7;
}

void reset(t_env *env)
{
	env->height = 5;
	env->scalex = 30;
	env->scaley = 15;
	env->posx = (LARGEUR_IMG / 2) + 125;
	env->posy = 100;
}
