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

int			controller(int keycode, void *param)
{
	t_env *env;

	env = (t_env*)param;
    printf("keycode = %d\n\n", keycode);

	if (keycode == ESCAPE_M || keycode == ESCAPE_L)
	{
    	mlx_destroy_image(env->mlx, env->win.ptr);
    	exit(0);
	}
	if (keycode == UP_M || keycode == UP_L || keycode == DOWN_M ||
		keycode == DOWN_L || keycode == LEFT_M || keycode == LEFT_L ||
		keycode == RIGHT_M || keycode == RIGHT_L)
		translate(keycode, env);
	if (keycode == ZOOM_IN_M || keycode == ZOOM_IN_L ||
		keycode == ZOOM_OUT_M || keycode == ZOOM_OUT_L)
		scale(keycode, env);
	if (keycode == UP_Z_M || keycode == UP_Z_L ||
		keycode == DOWN_Z_M || keycode == DOWN_Z_L)
		height(keycode, env);
	if (keycode == RESET_M || keycode == RESET_L)
		reset(env);
	set_img(env);
	return (0);
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
    mlx_loop(env.mlx);
    return (0);
}
