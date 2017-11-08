#include "FdF.h"

t_coords    set_pixel(int x, int y, unsigned int color)
{
    t_coords p;

    p.x = x;
    p.y = y;
    p.color = color;

    return (p);
}

void 		draw_line(t_env *env, t_coords p0, t_coords p1)
{
	t_line	line;
    int		incr_x;
    int		incr_y;
    int		err_tmp;

	line.dx = ft_abs(p1.x - p0.x);
	incr_x = p0.x < p1.x ? 1 : -1;
	line.dy = ft_abs(p1.y - p0.y);
	incr_y = p0.y < p1.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;

	while(1)
	{
		put_pixel_img(env, set_pixel(p0.x, p0.y, p0.color));
    	if (p0.x==p1.x && p0.y==p1.y)
			break;
    	err_tmp = line.err;
    	if (err_tmp >- line.dx)
		{
			line.err -= line.dy;
			p0.x += incr_x;
		}
    	if (err_tmp < line.dy)
		{
			line.err += line.dx;
			p0.y += incr_y;
		}
	}
}

void	draw_map_iso(t_env *env, t_coords p1, t_coords p2, t_coords z)
{
	t_coords	a;
	t_coords	b;

	a.x = (p1.x - p1.y) * env->scalex + env->posx;
	a.y = (p1.y + p1.x) * env->scaley + env->posy;
	a.color = p1.color;
	b.x = (p2.x - p2.y) * env->scalex + env->posx;
	b.y = (p2.y + p2.x) * env->scaley + env->posy;
	b.color = p2.color;

	a.y -= z.x * env->height;
	b.y -= z.y * env->height;

	draw_line(env, a, b);
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
		while (++j < env->nbr_line)
		{
			if (curr->next != NULL)
			{
				z = set_pixel(((int*)(curr->content))[j],
					((int*)(curr->next->content))[j], BLUE);
				draw_map_iso(env, set_pixel(i, j, BLUE),
					set_pixel(i + 1, j, BLUE), z);
			}
			if (j < env->nbr_line - 1)
			{
				z = set_pixel(((int*)(curr->content))[j],
					((int*)(curr->content))[j + 1], BLUE);
				draw_map_iso(env, set_pixel(i, j, BLUE),
					set_pixel(i, j + 1, BLUE), z);
			}
		}
		curr = curr->next;
	}
}

/*void	projection(t_env env, t_list *map)
{
	int 		cte;
	int			i;
	int 		line;
	int			decX;
	int			tmpDecX;
	t_coords	p;
	t_coords	p2;
	t_coords	p3;
	t_list		*curr;

	cte = 23;
	decX = 0;
	tmpDecX = 15;
	line = (HAUTEUR_IMG / 100) + 3;
	curr = map;
	while (curr)
	{
		i = 0;
		p.x = (LARGEUR_IMG / 9) + decX;
		while (i <= 19) //have to use arrlen
		{
			//curr->next->content[i]
			//X = (((int*)(curr->content))[i] * cos(M_PI/6) - ((int*)(curr->content))[i] * sin(M_PI/3)) + c;
			//Y = (((int*)(curr->content))[i] * sin(M_PI/6) + ((int*)(curr->content))[i] * cos(M_PI/3)) + c;

			p.x += cte;
			p.y = line * cte;
			p.color = GREEN;

			p2.x = p.x + cte;
			p2.y = p.y - (5 * ((int*)(curr->content))[i]);
			p2.color = p.color;

			p3.x = p.x + tmpDecX;
			p3.y = p.y + cte;
			p3.color = p.color;

			if (i != 19)
				draw_line(env, p, p2);
			if (curr->next !=  NULL)
				draw_line(env, p, p3);
			++i;
		}
		++line;
		decX += 15;
		curr = curr->next;
	}
}*/
