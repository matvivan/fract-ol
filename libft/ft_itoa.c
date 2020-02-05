/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:47:55 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/26 17:01:51 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	range(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		++i;
	while (++i && n / 10)
		n /= 10;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*new;
	int		r;

	r = range(n);
	new = ft_strnew(r);
	if (!new)
		return (NULL);
	if (!n)
		new[0] = '0';
	while (n)
	{
		if (n < 0)
		{
			new[--r] = '0' - (n % 10);
			if (!(n / 10))
				new[--r] = '-';
		}
		else
			new[--r] = '0' + (n % 10);
		n = n / 10;
	}
	return (new);
}
