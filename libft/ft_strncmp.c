/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:00:31 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/28 11:33:47 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
		if (s1[i] != s2[i] || (i + 1) == n)
			break ;
		else
			i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
