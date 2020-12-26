/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:44:51 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:12:47 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing_light.h"

int		check_parsed_color(t_color color, int count)
{
	if (color.r < 0 || color.r > 255 ||
		color.g < 0 || color.g > 255 ||
		color.b < 0 || color.b > 255)
		error_msg(8, count);
	return (0);
}

int		parse_color2(char *line, int count, int *i, int j)
{
	char	nb[4];
	int		blue;

	if (line[*i] != ',' || ft_isdigit(line[++(*i)]) != 1)
		return (error_msg(3, count));
	j = 0;
	while (line[*i] && is_space(line[*i]) == 0)
	{
		if (j > 2)
			return (error_msg(3, count));
		if (ft_isdigit(line[*i]) != 1)
			return (error_msg(3, count));
		nb[j++] = line[(*i)++];
	}
	nb[j] = '\0';
	blue = ft_atoi(nb);
	return (blue);
}

t_color	parse_color(char *line, int count, int *i, int j)
{
	char	nb[4];
	int		red;
	int		green;

	*i = pass_spaces(line, *i, count);
	while (line[*i] && line[*i] != ',')
	{
		if (j > 2 || ft_isdigit(line[*i]) != 1)
			error_msg(3, count);
		nb[j++] = line[(*i)++];
	}
	nb[j] = '\0';
	red = ft_atoi(nb);
	j = 0;
	if (line[*i] != ',' || ft_isdigit(line[++(*i)]) != 1)
		error_msg(3, count);
	while (line[*i] && line[*i] != ',')
	{
		if (j > 2 || ft_isdigit(line[*i]) != 1)
			error_msg(3, count);
		nb[j++] = line[(*i)++];
	}
	nb[j] = '\0';
	green = ft_atoi(nb);
	return (init_color(red, green, parse_color2(line, count, i, j)));
}

double	parse_intensity(char *line, int *i, int count)
{
	double	intensity;
	char	nb[19];
	int		j;

	*i = pass_spaces(line, *i, count);
	if (check_double(line, *i, ' ') != 0)
		return (error_msg(3, count));
	j = 0;
	while (line[*i] && (line[*i] != ' ' && line[*i] != '\t' && line[*i] != '\n'
		&& line[*i] != '\v' && line[*i] != '\f' && line[*i] != '\r'))
	{
		if (j > 17)
			return (error_msg(3, count));
		if (ft_isdigit(line[*i]) != 1 && line[*i] != '.')
			return (error_msg(3, count));
		nb[j++] = line[(*i)++];
	}
	nb[j] = '\0';
	intensity = ft_dec_atoi(nb);
	if (intensity < 0 || intensity > 1)
		return (error_msg(7, count));
	intensity *= 1000;
	return (intensity);
}

void	parse_light(char *line, int count)
{
	int i;

	i = 1;
	g_light_nb++;
	g_light[g_light_nb].pos = entor_vector(line, &i, count);
	g_light[g_light_nb].intensity = parse_intensity(line, &i, count);
	g_light[g_light_nb].color = parse_color(line, count, &i, 0);
	check_parsed_color(g_light[g_light_nb].color, count);
	i = pass_spaces(line, i, count);
	if (line[i])
		error_msg(3, count);
}
