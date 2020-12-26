/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_amb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:26:50 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/24 16:10:53 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing_amb.h"

int	check_line(char *line, int i, int j, int count)
{
	if (j > 2)
		return (error_msg(3, count));
	if (ft_isdigit(line[i]) != 1)
		return (error_msg(3, count));
	return (0);
}

int	parse_amb_color2(char *line, int count, int i, int j)
{
	char nb[4];

	if (line[i] != ',' || ft_isdigit(line[++i]) != 1)
		return (error_msg(3, count));
	j = 0;
	while (line[i] && is_space(line[i]) == 0)
	{
		check_line(line, i, j, count);
		nb[j++] = line[i++];
	}
	nb[j] = '\0';
	g_ambiant_light.color.b = ft_atoi(nb);
	g_ambiant_light.color.a = 0;
	if (g_ambiant_light.color.r < 0 || g_ambiant_light.color.r > 255 ||
		g_ambiant_light.color.g < 0 || g_ambiant_light.color.g > 255 ||
		g_ambiant_light.color.b < 0 || g_ambiant_light.color.b > 255)
		return (error_msg(8, count));
	i = pass_spaces(line, i, count);
	if (line[i])
		error_msg(3, count);
	return (0);
}

int	parse_amb_color(char *line, int count, int i, int j)
{
	char nb[4];

	i = pass_spaces(line, i, count);
	while (line[i] && line[i] != ',')
	{
		check_line(line, i, j, count);
		nb[j++] = line[i++];
	}
	nb[j] = '\0';
	g_ambiant_light.color.r = ft_atoi(nb);
	j = 0;
	if (line[i] != ',' || ft_isdigit(line[++i]) != 1)
		return (error_msg(3, count));
	while (line[i] && line[i] != ',')
	{
		check_line(line, i, j, count);
		nb[j++] = line[i++];
	}
	nb[j] = '\0';
	g_ambiant_light.color.g = ft_atoi(nb);
	return (parse_amb_color2(line, count, i, j));
}

int	parse_amb_light(char *line, int count)
{
	char	nb[19];
	int		i;
	int		j;

	i = pass_spaces(line, 1, count);
	if (check_double(line, i, ' ') != 0)
		return (error_msg(0, count));
	j = 0;
	while (line[i] && line[i] != ' ')
	{
		if (j > 17)
			return (error_msg(3, count));
		if (ft_isdigit(line[i]) != 1 && line[i] != '.')
			return (error_msg(3, count));
		nb[j++] = line[i++];
	}
	nb[j] = '\0';
	g_ambiant_light.intensity = ft_dec_atoi(nb);
	if (g_ambiant_light.intensity < 0 || g_ambiant_light.intensity > 1)
		return (error_msg(3, count));
	j = 0;
	parse_amb_color(line, count, i, j);
	return (0);
}
