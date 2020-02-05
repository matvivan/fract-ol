/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:51:16 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/30 22:02:01 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list **alst, char *s)
{
	if (*alst)
	{
		if (ft_strcmp((*alst)->content, s))
			return (ft_lstfind(&((*alst)->next), s));
		else
			return (*alst);
	}
	else
		return (*alst);
}
