/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:56:37 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/22 21:33:06 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*begin;

	if (s)
	{
		new = ft_strnew(len);
		if (new)
		{
			begin = new;
			while (len--)
				*new++ = *(start + s++);
			return (begin);
		}
	}
	return (NULL);
}
