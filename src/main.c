/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:08:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/10/02 06:37:43 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*int		manage_mouse(int button, int  x, int y, t_env *env)
{
    printf("\nbutton : %d\ncoords: %d;%d\ntitle : %s\n",
        button, x, y, env->win.title);
    return(0);
}*/

void 		refresh_img(t_env *env)
{
	//mlx_destroy_image(env->mlx, env->img.ptr);
	//env->img.ptr = mlx_new_image(env->mlx, env->img.l, env->img.h);
	//env->img.data = mlx_get_data_addr(env->img.ptr, &env->img.bpp,
	//		&env->img.size_line, &env->img.endian);

	set_img(env);
}

int			destroy(t_env *env)
{
    mlx_destroy_image(env->mlx, env->win.ptr);
    exit(0);
}

int			controller(void *param, int keycode)
{
	t_env *env;

	env = param;
	//refresh_img(env);
    printf("keycode = %d\n\n", keycode);

	if (keycode == 65307)
	{
		destroy(env);
	}
	if (keycode == 65362)
	{
		printf("\nfleche du haut\n");
	}
	refresh_img(env);
	//projection(env);
	return (0);
}

int         ft_abs(int x)
{
    if(x < 0)
        x = -1 * x;
    return (x);
}

void draw_line(t_env *env, t_coords p0, t_coords p1)
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

void	draw_map_iso(t_env *env, t_coords p1, t_coords p2, t_coords z)
{
	int			decX;
	int			decY;
	t_coords	a;
	t_coords	b;

	decX = (LARGEUR_IMG / 2) + 140;
	decY = 100;

	a.x = (p1.x - p1.y) * 32 + decX/* * env.scale*/;
	a.y = (p1.y + p1.x) * 16 + decY/* * env.scale*/;
	a.color = p1.color;
	b.x = (p2.x - p2.y) * 32 + decX/* * env.scale*/;
	b.y = (p2.y + p2.x) * 16 + decY/* * env.scale*/;
	b.color = p2.color;

	a.y -= z.x * 5;
	b.y -= z.y * 5;


	draw_line(env, a, b);
}

size_t  ft_arrlen(void **arr)
{
    size_t  i;
    i = 0;

    while ((unsigned char*)arr[i])
        ++i;
    return (i);
}

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (alst && new)
	{
		if (!*alst)
			*alst = new;
		else
		{
			tmp = *alst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

int		parse(t_env *env, char *buff) //verif a faire pour map non valide
{
	t_list		*list;
    char        *line;
    char        **grid;
    int         *tmp;
	int			fd;
	int			i;
	int			tmpaff;

	list = NULL;
	tmpaff = 0;
    fd = open(buff, O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
		grid = ft_strsplit(line, ' ');
		env->nbr_line = ft_arrlen((void**)grid);
		printf("\narrlen parse = %zu\n", env->nbr_line);

        tmp = ft_memalloc(sizeof(int) * env->nbr_line);
		i = 0;
		while (grid[i])
		{
			tmp[i] = ft_atoi(grid[env->nbr_line - 1 - i]);
			printf("\ntmp[%d] = %d", i, tmp[i]);
			++i;
		}
		tmpaff++;
		printf("\n-------------------------%d", tmpaff);

		env->map = list;
		ft_lstadd_end(&list, ft_lstnew(tmp, env->nbr_line * sizeof(int)));
		ft_memdel((void*)&tmp);
		ft_strdel(&line);
    }
	close(fd);
	return (1); //a verifier pour une map full vide
}

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

void		printMap_console(t_env *env)
{
		t_list		*curr;
		size_t		i;
		int			tmp;

		i = 0;
		tmp = 0;
		curr = env->map;
		printf("\nprintmap begin\n");
		printf("\nprintmap len = %zu\n", env->nbr_line);
		while (curr != NULL)
		{
			printf("\ntest passage boucle curr : nb %d\n", tmp);
			while (i < env->nbr_line)
			{
				printf("i = %zu, val[%d]\n", i, ((int*)(curr->content))[i]);
				i++;
			}
			i = 0;
			tmp++;
			curr = curr->next;
		}
}

t_coords    set_pixel(int x, int y, unsigned int color)
{
    t_coords p;

    p.x = x;
    p.y = y;
    p.color = color;

    return (p);
}

void 		set_img(t_env *env)
{
    env->img.ptr = mlx_new_image(env->mlx, env->img.l, env->img.h);
    env->img.data = mlx_get_data_addr(env->img.ptr, &env->img.bpp,
    	&env->img.size_line, &env->img.endian);
	projection(env);
    mlx_put_image_to_window(env->mlx, env->win.ptr, env->img.ptr, 0, 0);

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
}

int         main(int argc, char *argv[])
{
    t_env       env;

    if(argc != 2)
    {
        return (0);
        write(1, "usage: ./FdF File", 17);
    }

    set_env(&env);
    env.mlx = mlx_init();
    env.win.ptr = mlx_new_window(env.mlx, env.win.l, env.win.h, env.win.title);

    if((parse(&env, argv[1])))
    {
        write(1, "map invalide", 12);
        //return (0);
    }

	printMap_console(&env);
	set_img(&env);

	mlx_hook(env.win.ptr, 2, 3, controller, &env);
	//mlx_hook(env.win.ptr, 17, 0L, destroy, &env);
    //mlx_mouse_hook(env.win.ptr, manage_mouse, &env);
    mlx_loop(env.mlx);
    return (0);
}
