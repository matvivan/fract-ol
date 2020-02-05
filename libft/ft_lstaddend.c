/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:09:43 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/30 22:22:20 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	if (new)
	{
		if (*alst)
		{
			if ((*alst)->next)
				ft_lstaddend(&((*alst)->next), new);
			else
				(*alst)->next = new;
		}
		else
			*alst = new;
	}
}
