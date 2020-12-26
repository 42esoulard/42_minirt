/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:26:05 by esoulard          #+#    #+#             */
/*   Updated: 2019/11/10 15:41:26 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_malloc(char *type, int size)
{
	if (!(g_mallocs[g_malnb] = malloc(sizeof(type) * size)))
		return (NULL);
	g_malnb++;
	return (g_mallocs[g_malnb - 1]);
}

void	ft_free(char *str)
{
	g_freenb++;
	free(str);
}
