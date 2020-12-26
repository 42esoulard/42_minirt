/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:11:20 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/12 15:25:29 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int count;

	if (lst)
	{
		count = 1;
		while (lst->next)
		{
			count++;
			lst = lst->next;
		}
	}
	if (!lst)
		count = 0;
	return (count);
}
