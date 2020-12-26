/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:12:58 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/22 19:44:32 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*c_str;
	unsigned char	c_c;

	c_str = (unsigned char *)s;
	c_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (c_str[i] == c_c)
			return (&c_str[i]);
		i++;
	}
	return (NULL);
}
