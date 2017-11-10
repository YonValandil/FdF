#include "FdF.h"

void height(int keycode, t_env *env)
{
	if (keycode == UP_Z)
		env->height += 1;
	if (keycode == DOWN_Z)
		env->height -= 1;
}

void rotate(int keycode, t_env *env)
{
	if (keycode == R_UP)
		env->scaley += 2;
	if (keycode == R_DOWN)
		env->scaley -= 2;
	if (keycode == R_LEFT)
		env->scalex +=2;
	if (keycode == R_RIGHT)
		env->scalex -=2;
}

void scale(int keycode, t_env *env)
{
	if (keycode == ZOOM_IN)
	{
		env->scalex += 2;
		env->scaley += 1;
	}
	if (keycode == ZOOM_OUT)
	{
		env->scalex -= 2;
		env->scaley -= 1;
	}
}

void translate(int keycode, t_env *env)
{
	if (keycode == UP)
		env->posy -= 7;
	if (keycode == DOWN)
		env->posy += 7;
	if (keycode == LEFT)
		env->posx -=7;
	if (keycode == RIGHT)
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
