/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:17:42 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/28 11:29:44 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	gap;

	ft_strncpy(dst, dst, dstsize);
	if (ft_strlen(dst) < dstsize)
	{
		gap = dstsize - ft_strlen(dst) - 1;
		ft_strncat(dst, src, gap);
		if (ft_strlen(src) > gap)
			return (ft_strlen(dst) + ft_strlen(src) - gap);
		else
			return (ft_strlen(dst));
	}
	else
		return (dstsize + ft_strlen(src));
}
