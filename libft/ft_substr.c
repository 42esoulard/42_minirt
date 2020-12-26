/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:25:27 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/15 14:24:09 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(new = ft_malloc("char", (len + 1))))
		return (NULL);
	if (start > ft_pstrlen(s))
	{
		new[0] = '\0';
		return (new);
	}
	while (s[start] && i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
