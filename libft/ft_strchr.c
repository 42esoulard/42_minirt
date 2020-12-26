/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:43:00 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/23 15:48:52 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*haystack;
	char	needle;
	int		i;

	haystack = (char *)s;
	needle = (char)c;
	i = -1;
	while (haystack[++i])
	{
		if (haystack[i] == needle)
			return ((char *)&s[i]);
	}
	if (needle == '\0' && haystack[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
