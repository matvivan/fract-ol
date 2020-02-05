/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:45:37 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/30 23:31:01 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfold(t_list **alst, t_list *(*f)(t_list *a, t_list *b))
{
	if (*alst)
	{
		if ((*alst)->next)
			return (f(*alst, ft_lstfold(&((*alst)->next), f)));
		else
			return (*alst);
	}
	else
		return (NULL);
}
