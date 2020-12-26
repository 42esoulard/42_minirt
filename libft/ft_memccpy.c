/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:18:01 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/23 14:23:24 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*convsrc;
	unsigned char		*convdst;
	unsigned char		needle;

	i = 0;
	convsrc = (unsigned char *)src;
	convdst = (unsigned char *)dst;
	needle = (unsigned char)c;
	while (i < n)
	{
		convdst[i] = convsrc[i];
		if (convsrc[i] == needle)
			return (&convdst[i + 1]);
		i++;
	}
	return (NULL);
}
