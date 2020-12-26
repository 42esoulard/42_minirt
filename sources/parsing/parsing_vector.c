/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:48:47 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:12:53 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing_vector.h"

double		entor_vector_z(char *line, int *i, int count)
{
	char	nb[315];
	int		j;

	if (check_double(line, *i, ' ') != 0)
		return (error_msg(0, count));
	j = 0;
	if (line[*i] == '-')
		nb[j++] = line[(*i)++];
	while (line[*i] && is_space(line[*i]) == 0)
	{
		if (j > 315)
			return (error_msg(3, count));
		if (ft_isdigit(line[*i]) != 1 && line[*i] != '.')
			return (error_msg(3, count));
		nb[j++] = line[(*i)++];
	}
	nb[j] = '\0';
	return (ft_dec_atoi(nb));
}

double		entor_vector_y(char *line, int *i, int count)
{
	char	nb[315];
	int		j;

	if (check_double(line, *i, ',') != 0)
		return (error_msg(3, count));
	j = 0;
	if (line[*i] == '-')
		nb[j++] = line[(*i)++];
	while (line[*i] && line[*i] != ',')
	{
		if (j > 315)
			return (error_msg(3, count));
		if (ft_isdigit(line[*i]) != 1 && line[*i] != '.')
			return (error_msg(3, count));
		nb[j++] = line[(*i)++];
	}
	nb[j] = '\0';
	if (!line[*i] || line[*i] != ',' || (ft_isdigit(line[++(*i)]) != 1
		&& line[*i] != '-'))
		return (error_msg(3, count));
	return (ft_dec_atoi(nb));
}

double		entor_vector_x(char *line, int *i, int count)
{
	char	nb[315];
	int		j;

	*i = pass_spaces(line, *i, count);
	if ((ft_isdigit(line[*i]) != 1 && line[*i] != '-') ||
		check_double(line, *i, ',') != 0)
		return (error_msg(3, count));
	j = 0;
	if (line[*i] == '-')
		nb[j++] = line[(*i)++];
	while (line[*i] && line[*i] != ',')
	{
		if (j > 314)
			return (error_msg(3, count));
		if (ft_isdigit(line[*i]) != 1 && line[*i] != '.')
			return (error_msg(3, count));
		nb[j++] = line[(*i)++];
	}
	nb[j] = '\0';
	if (!line[*i] || line[*i] != ',' || (ft_isdigit(line[++(*i)]) != 1
		&& line[*i] != '-'))
		return (error_msg(3, count));
	return (ft_dec_atoi(nb));
}

t_vector	entor_vector(char *line, int *i, int count)
{
	double	x;
	double	y;
	double	z;

	x = entor_vector_x(line, i, count);
	y = entor_vector_y(line, i, count);
	z = entor_vector_z(line, i, count);
	return (init_vector(x, y, z));
}
