/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:42:12 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/18 22:38:04 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *begin;

	begin = dst;
	while ((size_t)(dst - begin) < len)
		if (*src != '\0')
			*dst++ = *src++;
		else
			*dst++ = '\0';
	return (begin);
}
