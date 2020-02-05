/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:28:12 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/27 19:53:59 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *buffer;

	buffer = (char *)malloc(len * sizeof(char));
	if (buffer && dst != src)
	{
		ft_memcpy(buffer, src, len);
		ft_memcpy(dst, buffer, len);
		free(buffer);
	}
	return (dst);
}
