/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:48:22 by jjourne           #+#    #+#             */
/*   Updated: 2017/12/10 19:48:24 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char **s1, char **s2)
{
	char	*tmp;

	if (s1 && *s1 && s2 && *s2)
	{
		tmp = ft_strjoin(*s1, *s2);
		ft_strdel(s1);
		ft_strdel(s2);
	}
	else if (s1 && *s1)
	{
		tmp = ft_strdup(*s1);
		ft_strdel(s1);
	}
	else if (s2 && *s2)
	{
		tmp = ft_strdup(*s2);
		ft_strdel(s2);
	}
	else
		tmp = ft_strdup("");
	return (tmp);
}
