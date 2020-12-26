/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:16:35 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/18 14:00:22 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *stock_ad;
	t_list *buf;

	buf = NULL;
	stock_ad = NULL;
	if (lst && *lst && del)
	{
		buf = *lst;
		while (buf->next != NULL)
		{
			stock_ad = buf->next;
			(*del)(buf->content);
			free(buf);
			buf = stock_ad;
		}
		if (buf->next == NULL)
		{
			(*del)(buf->content);
			free(buf);
		}
		buf = NULL;
		*lst = NULL;
	}
}
