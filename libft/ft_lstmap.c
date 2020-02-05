/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:19:03 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/27 16:31:23 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst)
	{
		if (lst->next)
		{
			new = ft_lstmap(lst->next, f);
			ft_lstadd(&new, f(lst));
		}
		else
			new = f(lst);
		return (new);
	}
	return (NULL);
}
