/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:06:00 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/30 21:06:01 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	if (lst)
	{
		ft_putchar('[');
		ft_putnbr(lst->content_size);
		ft_putchar(']');
		ft_putchar('[');
		ft_putnbr(ft_strlen(lst->content));
		ft_putchar(']');
		ft_putendl(lst->content);
		if (lst->next)
			ft_lstprint(lst->next);
	}
}
