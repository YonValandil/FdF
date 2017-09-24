/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:08:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/24 09:56:54 by jjourne          ###   ########.fr       */
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
    env->win.title = ft_strdup("mlx 42");

    env->img.l = LARGEUR_IMG;
    env->img.h = HAUTEUR_IMG;
    env->img.bpp = 16;
    env->img.size_line = LARGEUR_IMG;
    env->img.endian = 0;
}

t_coords    set_pixel(int x, int y, unsigned int color)
{
    t_coords p;

    p.x = x;
    p.y = y;
    p.color = color;

    return (p);
}

void	  draw_line(t_env env, t_coords p1, t_coords p2)
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
        mlx_pixel_put(env.mlx, env.win.ptr, p1.x, p1.y, BLANK);
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
}

size_t  ft_arrlen(char **arr)
{
    size_t  i;

    i = 0
    while (arr[i])
        ++i;
    return (i);
}

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	while ()
	{

	}
}

t_list	*parse(t_env env, char *buff) //verif a faire pour map non valide
{
	t_list		*list;
    char        *line;
    char        **grid;
    int         *tmp;
    size_t		len;
	int			i;

	list = NULL;
    fd = open(buff, O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        if ((grid = ft_strsplit(line, ' ')))
        {
			len = ft_arrlen(grid);
            tmp = ft_memmalloc(sizeof(int) * len);
			i = 0;
			while (grid[i])
			{
				tmp[i] = ft_atoi(grid[i]);
				++i;
			}
			ft_lstadd_end(&list, ft_lstnew(tmp, len * sizeof(int)));
			ft_memdel(&tmp);
        }
        ft_strdel(&line);
		close(fd);
    }
	return (list); //a verifier pour une map full vide
}

int         main(int argc, *argv[])
{
    t_env       env;

    if(argc != 2)
    {
        return (0);
        write(1, "usage: ./FdF File", 17)
    }

    set_env(&env);

    env.mlx = mlx_init();
    env.win.ptr = mlx_new_window(env.mlx, env.win.l, env.win.h, env.win.title);
    //(unsigned int) =  mlx_get_color_value(env.mlx, env.color);

    if((parse(argv[1]))
    {
        write(1, "map invalide", 12);
        return (0);
    }

    draw_line(env, set_pixel(0, 0, BLANK), set_pixel(400, 400, BLANK));
    draw_line(env, set_pixel(0, 200, BLANK), set_pixel(340, 0, BLANK));

    //creer une image:
    env.img.ptr = mlx_new_image(env.mlx, env.img.l, env.img.h);
    //la remplir:
    env.img.data = mlx_get_data_addr(env.img.ptr, &env.img.bpp,
    &env.img.size_line, &env.img.endian);
    //l'afficher:
    mlx_put_image_to_window(env.mlx, env.win.ptr, env.img.ptr,
        0, 0);

    //mlx management event
    //mlx_hook(env.win.ptr, event, mask, ptr_fcnt, &event) //need to include X.h
    mlx_key_hook(env.win.ptr, manage_key, &env);
    mlx_mouse_hook(env.win.ptr, manage_mouse, &env);

    //mlx boucle d'execution
    mlx_loop(env.mlx);
    return (0);
}
