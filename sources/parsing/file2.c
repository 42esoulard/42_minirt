/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:53:00 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/21 19:08:44 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"

int		parse_int(char *line, int *i, int count)
{
	double	result;
	char	nb[11];
	int		j;

	*i = pass_spaces(line, *i, count);
	if (check_int(line, *i, ' ') != 0)
		return (error_msg(3, count));
	j = 0;
	while (line[*i] && is_space(line[*i]) == 0 && line[*i] != ',')
	{
		if (j > 10)
			return (error_msg(3, count));
		if (ft_isdigit(line[*i]) != 1)
			return (error_msg(3, count));
		nb[j++] = line[(*i)++];
	}
	nb[j] = '\0';
	result = ft_atoi(nb);
	return (result);
}

double	parse_double(char *line, int *i, int count)
{
	double	result;
	char	nb[319];
	int		j;

	*i = pass_spaces(line, *i, count);
	if (check_double(line, *i, ' ') != 0)
		return (error_msg(3, count));
	j = 0;
	while (line[*i] && (line[*i] != ' ' && line[*i] != '\t' && line[*i] != '\n'
		&& line[*i] != '\v' && line[*i] != '\f' && line[*i] != '\r'))
	{
		if (j > 317)
			return (error_msg(3, count));
		if (ft_isdigit(line[*i]) != 1 && line[*i] != '.')
			return (error_msg(3, count));
		nb[j++] = line[(*i)++];
	}
	nb[j] = '\0';
	result = ft_dec_atoi(nb);
	return (result);
}

int		is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i] && is_space(line[i]) == 1)
		i++;
	if (line[i])
		return (-1);
	return (0);
}

void	init_globals(int what)
{
	g_light_nb = what;
	g_nb_obj = what;
	g_cam_nb = what;
}
