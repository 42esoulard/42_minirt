/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:18:22 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/23 16:53:49 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haycast;

	haycast = (char *)haystack;
	i = 0;
	if (!needle[0])
		return (haycast);
	while (haycast[i] && i < len)
	{
		j = 0;
		while (haycast[i + j] && needle[j]
			&& haycast[i + j] == needle[j] && (i + j) < len)
			j++;
		if (!(needle[j]))
			return (&haycast[i]);
		i++;
	}
	return (NULL);
}
