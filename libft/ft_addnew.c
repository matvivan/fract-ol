/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:50:20 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/30 20:50:24 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_addnew(char **arr, size_t size, char *elem)
{
	char	**new;
	size_t	i;

	i = 0;
	new = (char **)malloc((size + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	if (arr)
	{
		while (i < size)
		{
			new[i] = arr[i];
			i++;
		}
		free(arr);
	}
	new[i] = elem;
	return (new);
}
