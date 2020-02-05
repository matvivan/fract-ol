/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:32:10 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/30 22:39:01 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcut(t_list **alst, t_list *lst)
{
	if (*alst)
	{
		if (*alst == lst)
			*alst = lst->next;
		else
			ft_lstcut(&((*alst)->next), lst);
	}
}
