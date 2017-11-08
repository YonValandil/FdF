#include "libft.h"

void ft_lstadd_end(t_list **alst, t_list *new)
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
