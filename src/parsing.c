#include "FdF.h"

int		parse_grid(t_env *env, char **grid, int *tmp)
{
	int			i;

	i = -1;
	while (grid[++i])
		tmp[i] = ft_atoi(grid[env->nbr_col - 1 - i]);
	return (0);
}

int		parse(t_env *env, char *buff)
{
    char        *line;
    char        **grid;
	int			fd;
	int			*tmp;

    if((fd = open(buff, O_RDONLY)) <= 0)
		exit_error("open file error");
    while (get_next_line(fd, &line) > 0)
    {
		grid = ft_strsplit(line, ' ');
		ft_strdel(&line);
		env->nbr_col = arrlen((void**)grid);
		env->nbr_line++;
	    if(!(tmp = ft_memalloc(sizeof(int) * env->nbr_col)))
			exit_error("memalloc error");
		if (parse_grid(env, grid, tmp) < 0)
			return (-1);
		ft_lstadd_end(&(env)->map, ft_lstnew(tmp, env->nbr_col * sizeof(int)));
		ft_memdel((void*)&tmp);
		arrdel((void***)&grid);
    }
	close(fd);
	return (0);
}
