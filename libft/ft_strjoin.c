/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:04:11 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/26 21:01:29 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (s1 && s2)
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (new)
		{
			ft_strcat(new, s1);
			ft_strcat(new, s2);
			return (new);
		}
	}
	return (NULL);
}
