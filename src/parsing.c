/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:59:05 by jjourne           #+#    #+#             */
/*   Updated: 2017/11/27 06:00:17 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void 	free_parse(char **grid, int *tmp)
{
		ft_memdel((void*)&tmp);
		arrdel((void***)&grid);
}

void 	ret_value(int ret)
{
	if (ret == -1)
		exit_error("error open file");
}

void 	check_nbr_line(t_env *env)
{
		env->nbr_line++;
		if (env->nbr_line > RANGE_MAP)
			exit_error("too much lines");
}

void	parse_grid(t_env *env, char **grid, int *tmp)
{
	int i;

	i = -1;
	while (grid[++i])
	{
		tmp[i] = ft_atoi(grid[env->nbr_col - 1 - i]);
		if (tmp[i] > RANGE_HEIGHT)
			tmp[i] = RANGE_HEIGHT;
		if (tmp[i] < -RANGE_HEIGHT)
			tmp[i] = -RANGE_HEIGHT;
	}
}

void	parse(t_env *env, char *buff)
{
	char	*line;
	char	**grid;
	int		fd;
	int		*tmp;
	int 	ret;

	if ((fd = open(buff, O_RDONLY)) < 0)
		exit_error("open file error");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		check_nbr_line(env);
		grid = ft_strsplit(line, ' ');
		ft_strdel(&line);
		env->nbr_col = arrlen((void**)grid);
		if (env->nbr_col > RANGE_MAP)
			exit_error("too much columns");
		if (!(tmp = ft_memalloc(sizeof(int) * env->nbr_col)))
			exit_error("memalloc error");
		parse_grid(env, grid, tmp);
		ft_lstadd_end(&(env)->map, ft_lstnew(tmp, env->nbr_col * sizeof(int)));
		free_parse(grid, tmp);
	}
	ret_value(ret);
	close(fd);
}
