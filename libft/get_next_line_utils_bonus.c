/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:43:01 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/14 12:34:02 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	int		s1len;
	int		i;
	int		j;

	s1len = 0;
	i = -1;
	j = 0;
	new = NULL;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[s1len])
		s1len++;
	while (s2[j])
		j++;
	if (!(new = malloc(sizeof(char) * (s1len + j + 1))))
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

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

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*cpy;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	if (!(cpy = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strndup(const char *s1, int len)
{
	char	*cpy;
	int		i;

	if (!(cpy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
