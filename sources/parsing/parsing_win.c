/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:32:52 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:12:56 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing_win.h"

int	parse_win_size2(char *line, int i, int count, char *nb)
{
	int j;

	if (check_int(line, i, ' ') != 0)
		return (error_msg(3, count));
	j = 0;
	while (line[i] && is_space(line[i]) == 0)
	{
		if (ft_isdigit(line[i]) != 1)
			return (error_msg(3, count));
		nb[j++] = line[i++];
	}
	nb[j] = '\0';
	g_w = ft_atoi(nb);
	if (g_w > 1440)
		g_w = 1440;
	i = pass_spaces(line, i, count);
	if (line[i] || g_h <= 0 || g_w <= 0)
		return (error_msg(3, count));
	return (0);
}

int	parse_win_size(char *line, int count)
{
	char	nb[11];
	int		i;
	int		j;

	i = pass_spaces(line, 1, count);
	if (check_int(line, i, ' ') != 0)
		return (error_msg(3, count));
	j = 0;
	while (line[i] && is_space(line[i]) == 0)
	{
		if (ft_isdigit(line[i]) != 1)
			return (error_msg(3, count));
		nb[j++] = line[i++];
	}
	nb[j] = '\0';
	g_h = ft_atoi(nb);
	if (g_h > 2560)
		g_h = 2560;
	i = pass_spaces(line, i, count);
	parse_win_size2(line, i, count, nb);
	return (0);
}
