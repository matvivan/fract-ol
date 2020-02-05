/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:25:02 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/21 18:19:50 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (s)
	{
		new = ft_strnew(ft_strlen((char *)s));
		if (new)
		{
			while (s[i] != '\0')
			{
				*(new + i) = f(i, s[i]);
				i++;
			}
			return (new);
		}
	}
	return (NULL);
}
