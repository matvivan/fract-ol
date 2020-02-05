/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:10:31 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/21 18:16:45 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*begin;
	char	*new;

	if (s)
	{
		new = ft_strnew(ft_strlen((char *)s));
		begin = new;
		if (new)
		{
			while (*s != '\0')
				*new++ = f(*s++);
			return (begin);
		}
	}
	return (NULL);
}
