/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:20:45 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/18 17:13:02 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlst;
	t_list *begin;

	if (lst == NULL || !f || !del)
		return (NULL);
	if (!(newlst = ft_lstnew(NULL)))
		return (NULL);
	begin = newlst;
	while (lst)
	{
		if (!(newlst->content = (*f)(lst->content)))
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		if (!(newlst->next = ft_lstnew(NULL)))
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		newlst = newlst->next;
		lst = lst->next;
	}
	return (begin);
}
