/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:15:03 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/18 13:58:58 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		ndlen;

	i = 0;
	ndlen = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && (i - 1 + ndlen) < len)
	{
		if (!ft_strncmp(haystack + i, needle, ndlen))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
