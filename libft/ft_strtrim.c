/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:01:45 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/22 19:22:55 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		trim_start(char const *s1, char const *set)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (set[i] && s1[j])
	{
		if (s1[j] == set[i])
		{
			i = -1;
			j++;
		}
		i++;
	}
	return (j);
}

static int		trim_end(char const *s1, char const *set, int j)
{
	int i;
	int k;

	i = 0;
	k = (int)ft_strlen(s1) - 1;
	if ((int)ft_strlen(s1) == j)
		return (k);
	while (set[i] && s1[k])
	{
		if (s1[k] == set[i])
		{
			i = -1;
			k--;
		}
		i++;
	}
	return (k);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;
	int		j;
	int		k;

	trimmed = NULL;
	if (!s1 || !set)
		return (NULL);
	j = trim_start(s1, set);
	k = trim_end(s1, set, j);
	if (!(trimmed = malloc(sizeof(char) * ((k - j) + 2))))
		return (NULL);
	i = 0;
	while (s1[j] && j <= k)
		trimmed[i++] = s1[j++];
	trimmed[i] = '\0';
	return (trimmed);
}
