/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:46:44 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/16 20:54:58 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	last = NULL;
	if (alst && new)
	{
		last = *alst;
		if (last != NULL)
		{
			while (last->next)
			{
				last = last->next;
			}
			last->next = new;
			new->next = NULL;
		}
		else
		{
			new->next = NULL;
			*alst = new;
		}
	}
}
