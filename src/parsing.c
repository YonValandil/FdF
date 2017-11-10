#include "FdF.h"

int		ft_error(char *s, int err)
{
	ft_putendl(s);
	return (err);
}

int		parse_grid(t_env *env, char **grid, t_list *list)
{
	// t_list		*list;
    int         *tmp;
	int			i;

	env->nbr_line = ft_arrlen((void**)grid);
	printf("\narrlen parse = %zu\n", env->nbr_line);

    if(!(tmp = ft_memalloc(sizeof(int) * env->nbr_line)))
		return (ft_error("memalloc error", -1));
	i = 0;
	// list = NULL;
	while (grid[i])
	{
		tmp[i] = ft_atoi(grid[env->nbr_line - 1 - i]);
		printf("\ntmp[%d] = %d", i, tmp[i]);
		++i;
	}
	env->map = list;
	ft_lstadd_end(&list, ft_lstnew(tmp, env->nbr_line * sizeof(int)));
	ft_memdel((void*)&tmp);
	return (0);
}

int		parse(t_env *env, char *buff)
{
    char        *line;
    char        **grid;
	int			fd;
	int			tmpaff;
	t_list		*list;

	tmpaff = 0;
	list = NULL;
    if((fd = open(buff, O_RDONLY)) <= 0)
		return (ft_error("open file error", -1));
    while (get_next_line(fd, &line) > 0)
    {
		grid = ft_strsplit(line, ' ');
		ft_strdel(&line);
		if (parse_grid(env, grid, list) < 0)
			return (ft_error("parse error", -1));
		tmpaff++;
		printf("\n---------------------- %d\n", tmpaff);
    }
	close(fd);
	return (0);
}
