/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:40:20 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/22 19:32:19 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

char		*ft_strdup(const char *s1)
{
	char	*copy;

	copy = ft_strnew(ft_strlen(s1));
	if (copy)
	{
		ft_strcpy(copy, s1);
		return (copy);
	}
	errno = ENOMEM;
	return (NULL);
}
