/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:59:21 by jjourne           #+#    #+#             */
/*   Updated: 2017/12/09 16:54:47 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_coords	set_pixel(int x, int y, int color)
{
	t_coords p;

	p.x = x;
	p.y = y;
	p.color = color;
	return (p);
}

void		draw_line(t_env *env, t_coords p0, t_coords p1)
{
	t_line	line;
	int		err_tmp;

	line.dx = ft_abs(p1.x - p0.x);
	line.incr_x = p0.x < p1.x ? 1 : -1;
	line.dy = ft_abs(p1.y - p0.y);
	line.incr_y = p0.y < p1.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (1)
	{
		put_pixel_img(env, set_pixel(p0.x, p0.y, p0.color));
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		err_tmp = line.err;
		if (err_tmp > -line.dx)
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

void		draw_map_iso(t_env *env, t_coords p0, t_coords p1, t_coords z)
{
	t_coords a;
	t_coords b;

	a.x = (p0.x - p0.y) * env->scalex + env->posx;
	a.y = (p0.y + p0.x) * env->scaley + env->posy;
	a.color = p0.color;
	b.x = (p1.x - p1.y) * env->scalex + env->posx;
	b.y = (p1.y + p1.x) * env->scaley + env->posy;
	b.color = p0.color;
	a.y -= z.x * env->height;
	b.y -= z.y * env->height;
	draw_line(env, a, b);
}

void		projection_content(t_env *env, t_list *curr, size_t i, size_t j)
{
	t_coords z;

	if (curr->next != NULL)
	{
		z = set_pixel(((int*)(curr->content))[j],
			((int*)(curr->next->content))[j], 0);
		draw_map_iso(env, set_pixel(i, j, BLUE), set_pixel(i + 1, j, 0), z);
	}
	if (j < env->nbr_col - 1)
	{
		z = set_pixel(((int*)(curr->content))[j],
			((int*)(curr->content))[j + 1], 0);
		draw_map_iso(env, set_pixel(i, j, BLUE), set_pixel(i, j + 1, 0), z);
	}
}

void		projection(t_env *env)
{
	size_t i;
	size_t j;
	t_list *curr;

	i = -1;
	curr = env->map;
	while (curr)
	{
		++i;
		j = -1;
		while (++j < env->nbr_col)
			projection_content(env, curr, i, j);
		curr = curr->next;
	}
}
