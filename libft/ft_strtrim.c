/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:53:44 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/26 19:12:28 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		n;

	new = NULL;
	if (s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		n = ft_strlen(s) - 1;
		if (n > 0)
			while (s[n] == ' ' || s[n] == '\t' || s[n] == '\n')
				n--;
		new = ft_strsub(s, 0, n + 1);
	}
	return (new);
}
