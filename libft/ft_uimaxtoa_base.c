/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 04:06:56 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/07 04:30:18 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*sizemallocstr(char *str, uintmax_t n, unsigned int divider, unsigned int base)
{
	while (n >= base)
	{
		n /= base;
		divider++;
	}
	str = ft_strnew(divider);
	if (str == NULL)
		return (NULL);
	return (str);
}

char			*ft_uimaxtoa_base(uintmax_t n, unsigned int base)
{
    char    		*str;
	unsigned int	divider;
	unsigned int	i;

	if (!n)
		return (ft_strdup("0"));
	divider = 1;
	str = NULL;
	str = sizemallocstr(str, n, divider, base);
	if (str == NULL)
		return (NULL);
	i = 0;
	while ((n / divider) >= base)
		divider *= base;
	while (divider > 0)
	{
		str[i] = ((n / divider) % base) + '0';
		divider /= base;
		++i;
	}
	str[i] = '\0';
    return(str);
}
