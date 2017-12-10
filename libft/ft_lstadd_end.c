/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:50:44 by jjourne           #+#    #+#             */
/*   Updated: 2017/12/10 19:50:54 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	else
		exit(EXIT_SUCCESS);
}
