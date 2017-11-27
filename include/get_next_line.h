/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 03:10:44 by jjourne           #+#    #+#             */
/*   Updated: 2017/11/27 05:41:52 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/fcntl.h>

# define BUFF_SIZE 512

typedef struct			s_fd_list
{
	int					fd;
	size_t				i;
	void				*content;
	struct s_fd_list	*next;
}						t_fd_list;

t_fd_list				*fd_search(int fd, t_fd_list **curr);
int						make_line(t_fd_list *curr, char **line);
void					*ft_memjoin(void const *s1, void const *s2,
							size_t n1, size_t n2);
int						get_next_line(const int fd, char **line);
int						last_check(t_fd_list *curr, char **line);

#endif
