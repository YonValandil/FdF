#include "FdF.h"

int			color(t_env *env, t_coords p0, t_coords p1, t_coords z)
{
	int val;

	val = p1.y - p0.y * env->height;
	val = 0x0000FF - ft_abs((z.x * env->height));
	return (val);
}

t_coords    set_pixel(int x, int y, int color)
{
    t_coords p;

    p.x = x;
    p.y = y;
    p.color = color;

    return (p);
}

void 		draw_line(t_env *env, t_coords p0, t_coords p1, t_coords z)
{
	t_line	line;
    int		err_tmp;

	line.dx = ft_abs(p1.x - p0.x);
	line.incr_x = p0.x < p1.x ? 1 : -1;
	line.dy = ft_abs(p1.y - p0.y);
	line.incr_y = p0.y < p1.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while(1)
	{
		put_pixel_img(env, set_pixel(p0.x, p0.y, color(env, p0, p1, z)));
    	if (p0.x==p1.x && p0.y==p1.y)
			break;
    	err_tmp = line.err;
    	if (err_tmp >- line.dx)
		{
			line.err -= line.dy;
			p0.x += line.incr_x;
		}
    	if (err_tmp < line.dy)
		{
			line.err += line.dx;
			p0.y += line.incr_y;
		}
	}
}

void	draw_map_iso(t_env *env, t_coords p0, t_coords p1, t_coords z)
{
	t_coords	a;
	t_coords	b;

	a.x = (p0.x - p0.y) * env->scalex + env->posx;
	a.y = (p0.y + p0.x) * env->scaley + env->posy;
	a.color = p1.color;
	b.x = (p1.x - p1.y) * env->scalex + env->posx;
	b.y = (p1.y + p1.x) * env->scaley + env->posy;
	b.color = p1.color;

	a.y -= z.x * env->height;
	b.y -= z.y * env->height;

	draw_line(env, a, b, z);
}

void	projection(t_env *env)
{
	size_t		i;
	size_t		j;
	t_coords	z;
	t_list		*curr;

	i = -1;
	curr = env->map;
	while (curr)
	{
		++i;
		j = -1;
		while (++j < env->nbr_col)
		{
			if (curr->next != NULL)
			{
				z = set_pixel(((int*)(curr->content))[j],
					((int*)(curr->next->content))[j], 0);
				draw_map_iso(env, set_pixel(i, j, 0),set_pixel(i + 1, j, 0), z);
			}
			if (j < env->nbr_col - 1)
			{
				z = set_pixel(((int*)(curr->content))[j],
					((int*)(curr->content))[j + 1], 0);
				draw_map_iso(env, set_pixel(i, j, 0),set_pixel(i, j + 1, 0), z);
			}
		}
		curr = curr->next;
	}
}
