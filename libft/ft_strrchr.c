/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:33:11 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/18 15:44:07 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			ptr = (char*)s;
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (ptr);
}
