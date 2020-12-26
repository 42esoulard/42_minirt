/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:15:10 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/22 18:52:01 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	char			*ptr;

	i = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(ptr = malloc(count * size)))
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *)ptr);
}
