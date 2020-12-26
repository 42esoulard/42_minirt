/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:47:26 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/24 13:04:11 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*haystack;
	char	needle;
	int		len;

	haystack = (char *)s;
	needle = (char)c;
	len = 0;
	while (haystack[len])
		len++;
	if (needle == '\0' && haystack[len] == '\0')
		return (&haystack[len]);
	while (len >= 0)
	{
		if (haystack[len] == needle)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
