/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:08:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/10/01 22:25:51 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int         manage_key(int keycode, t_env *env)
{
    printf("keycode = %d\ntitle window = %s\n", keycode, env->win.title);
    return (0);
}

int       manage_mouse(int button, int  x, int y, t_env *env)
{
    printf("\nbutton : %d\ncoords: %d;%d\ntitle : %s\n",
        button, x, y, env->win.title);
    return(0);
}

int    destroy(t_env *env)
{
    mlx_destroy_image(env->mlx, env->win.ptr);
    exit(0);
}

int         ft_abs(int x)
{
    if(x < 0)
        x = -1 * x;
    return (x);
}

void	   set_env(t_env *env)
{
    env->win.l = LARGEUR;
    env->win.h = HAUTEUR;
    env->win.title = ft_strdup("mlx 42 FdF");

    env->img.l = LARGEUR_IMG;
    env->img.h = HAUTEUR_IMG;
}

t_coords    set_pixel(int x, int y, unsigned int color)
{
    t_coords p;

    p.x = x;
    p.y = y;
    p.color = color;

    return (p);
}

/*void	  draw_line(t_env env, t_coords p1, t_coords p2)
{
    t_line line;
    int incr_x;
    int incr_y;
    int err_tmp;

    line.dx = ft_abs(p2.x - p1.x);
    line.dy = ft_abs(p2.y - p1.y);
    incr_x = (p1.x < p2.x) ? 1 : -1;
    incr_y = (p1.y < p2.y) ? 1 : -1;
    line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;

    while(p1.x != p2.x && p1.y != p2.y){
		put_pixel_img(&env, set_pixel(p1.x, p1.y, p1.color));
        err_tmp = line.err;
        if (err_tmp > -line.dx)
        {
            line.err -= line.dy;
            p1.x += incr_x;
        }
        if (err_tmp < line.dy)
        {
            line.err += line.dx;
            p1.y += incr_y;
        }
    }
}*/

void draw_line(t_env env, t_coords p0, t_coords p1)
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
		put_pixel_img(&env, set_pixel(p0.x, p0.y, p0.color));
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

void	projection(t_env env, t_list *map)
{
	int 		cte;
	int			i;
	int 		line;
	t_coords	p;
	t_coords	p2;
	t_coords	p3;
	t_list		*curr;

	cte = 23;
	i = 0;
	line = (HAUTEUR_IMG / 100) + 3;
	curr = map;
	while (curr)
	{
		p.x = (LARGEUR_IMG / 8);
		while (i < 20) //have to use arrlen
		{
			//curr->next->content[i]
			//X = (((int*)(curr->content))[i] * cos(M_PI/6) - ((int*)(curr->content))[i] * sin(M_PI/3)) + c;
			//Y = (((int*)(curr->content))[i] * sin(M_PI/6) + ((int*)(curr->content))[i] * cos(M_PI/3)) + c;

			p.x +=  cte;
			p.y = line * cte;
			p.color = GREEN;

			p2.x = p.x + cte;
			p2.y = p.y;
			p2.color = p.color;

			p3.x = p.x;
			p3.y = p.y + cte;
			p3.color = p.color;

			draw_line(env, p, p2);
			draw_line(env, p, p3);
			++i;
		}
		++line;
		i = 0;
		curr = curr->next;
	}
}

size_t  ft_arrlen(char **arr)
{
    size_t  i;
    i = 0;

    while (arr[i])
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

t_list	*parse(char *buff) //verif a faire pour map non valide
{
	t_list		*list;
    char        *line;
    char        **grid;
    int         *tmp;
    size_t		len;
	int			fd;
	int			i;
	int			tmpaff;

	list = NULL;
	tmpaff = 0;
    fd = open(buff, O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
		grid = ft_strsplit(line, ' ');
			len = ft_arrlen((char**)grid);
            tmp = ft_memalloc(sizeof(int) * len);
			i = 0;
			while (grid[i])
			{
				tmp[i] = ft_atoi(grid[i]);
				printf("\ntmp[%d] = %d", i, tmp[i]);
				++i;
			}
			tmpaff++;
			printf("\n-------------------------%d", tmpaff);
			ft_lstadd_end(&list, ft_lstnew(tmp, len * sizeof(int)));
			ft_memdel((void*)&tmp);
        ft_strdel(&line);
    }
	close(fd);
	return (list); //a verifier pour une map full vide
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

void		printMap(t_list *map)
{
		t_list		*curr;
		size_t		i;
		int			tmp;
		size_t		len;

		i = 0;
		tmp = 0;
		curr = map;
		len = ft_arrlen(((char**)&(curr->content)));
		printf("\nprintmap begin\n");
		printf("\nprintmap len = %zu\n", len);
		while (curr != NULL)
		{
			printf("\ntest passage boucle curr : nb %d\n", tmp);
			while (i < len) //recup la taille de arrlen
			{
				printf("i = %zu, val[%d]\n", i, ((int*)(curr->content))[i]);
				i++;
			}
			i = 0;
			tmp++;
			curr = curr->next;
		}
}

int         main(int argc, char *argv[])
{
    t_env       env;
	t_list		*map;

    if(argc != 2)
    {
        return (0);
        write(1, "usage: ./FdF File", 17);
    }

    set_env(&env);

    env.mlx = mlx_init();
    env.win.ptr = mlx_new_window(env.mlx, env.win.l, env.win.h, env.win.title);

    if((map = parse(argv[1])))
    {
        write(1, "map invalide", 12);
        //return (0);
    }

	printMap(map);

    env.img.ptr = mlx_new_image(env.mlx, env.img.l, env.img.h);
    env.img.data = mlx_get_data_addr(env.img.ptr, &env.img.bpp,
    &env.img.size_line, &env.img.endian);

	draw_line(env, set_pixel(0, 0, RED), set_pixel(400, 400, BLANK));
	draw_line(env, set_pixel(201, 0, RED), set_pixel(200, 400, BLANK)); //probleme avec vertical
	draw_line(env, set_pixel(20, 201, RED), set_pixel(200, 200, BLANK)); //probleme avec horizontal

	projection(env, map);

    mlx_put_image_to_window(env.mlx, env.win.ptr, env.img.ptr, 0, 0);

	mlx_hook(env.win.ptr, 17, 0L, destroy, &env);
	//mlx_hook(env.win.ptr, , , &env);
	mlx_key_hook(env.win.ptr, manage_key, &env);
    mlx_mouse_hook(env.win.ptr, manage_mouse, &env);
    mlx_loop(env.mlx);
    return (0);
}
