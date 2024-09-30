/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:09:17 by goolivei          #+#    #+#             */
/*   Updated: 2023/11/03 13:09:27 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*node;

	if (!lst || !f || !del)
		return (0);
	node = ft_lstnew(f(lst->content));
	if (!node->content)
	{
		ft_lstclear(&node, del);
		return (0);
	}
	aux = node;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(f(lst->content));
		if (!node->next)
		{
			ft_lstclear(&aux, del);
			return (0);
		}
		node = node->next;
		lst = lst->next;
	}
	return (aux);
}
