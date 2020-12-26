/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:07:17 by esoulard          #+#    #+#             */
/*   Updated: 2019/11/08 20:27:51 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**init_tab(char *arg, char **stock)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if (arg[i] && arg[i] != '%')
		{
			count++;
			while (arg[i] && arg[i] != '%')
				i++;
		}
		if (arg[i] && arg[i] == '%')
		{
			count++;
			i = parse_end_format(arg, i);
		}
	}
	if (!(stock = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	return (stock);
}
