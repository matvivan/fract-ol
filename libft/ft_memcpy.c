/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:12:59 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/19 16:24:07 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)dst;
	if (n != 0 && dst != src)
		while (n--)
			*d++ = *(unsigned char *)src++;
	return (dst);
}
