/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:03:04 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/29 16:03:58 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsplit(char const *s, char c)
{
	t_list	*new;
	int		len;

	new = NULL;
	if (s)
	{
		len = 0;
		while (*s != '\0')
		{
			if (*s != c)
			{
				if (ft_strchr(s, c))
					len = ft_strchr(s, c) - s;
				else
					len = ft_strchr(s, '\0') - s;
				ft_lstaddend(&new, ft_lstnew(ft_strsub(s, 0, len), len));
				s += --len;
			}
			s++;
		}
	}
	return (new);
}
