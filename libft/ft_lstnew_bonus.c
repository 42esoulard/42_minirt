/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:17:47 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/18 17:12:57 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	if (!(lstnew = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(lstnew->content = malloc(sizeof(content) *
			ft_strlen((char *)content) + 1)))
			return (NULL);
		ft_memcpy(lstnew->content, content, ft_strlen((char *)content) + 1);
	}
	else
		lstnew->content = NULL;
	lstnew->next = NULL;
	return (lstnew);
}
