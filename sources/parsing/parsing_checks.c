/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:30:57 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:12:45 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing_checks.h"

int	check_double_isspace(char *line, int i)
{
	int count;

	count = 0;
	while (line[i] && (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
		&& line[i] != '\v' && line[i] != '\f' && line[i] != '\r') && line[i]
		!= '.')
		i++;
	if (line[i] == '.')
	{
		i++;
		while (line[i] && (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
		&& line[i] != '\v' && line[i] != '\f' && line[i] != '\r'))
		{
			if (line[i] == '.')
				return (error_msg(3, count));
			count++;
			i++;
		}
	}
	if (count > 15)
		return (-1);
	return (0);
}

int	check_double(char *line, int i, char sep)
{
	int count;

	count = 0;
	if (sep == ' ')
		return (check_double_isspace(line, i));
	else
	{
		while (line[i] && line[i] != sep && line[i] != '.')
			i++;
		if (line[i] == '.')
		{
			i++;
			while (line[i] && line[i] != sep)
			{
				if (line[i] == '.')
					return (error_msg(3, count));
				count++;
				i++;
			}
		}
		if (count > 15)
			return (-1);
	}
	return (0);
}

int	pass_spaces(char *line, int i, int count)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		|| line[i] == '\v' || line[i] == '\f' || line[i] == '\r'))
		i++;
	if (line[i] && ft_isdigit(line[i]) != 1 && line[i] != '-')
		return (error_msg(3, count));
	return (i);
}

int	check_int_isspace(char *line, int i)
{
	long	result;
	int		minus;

	result = 0;
	minus = 1;
	if (line[i] == '-')
	{
		minus *= -1;
		i++;
	}
	while (line[i] && (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
		&& line[i] != '\v' && line[i] != '\f' && line[i] != '\r')
		&& line[i] >= '0' && line[i] <= '9')
	{
		result = result * 10 + (line[i] - 48);
		i++;
	}
	result *= minus;
	if (result > 2147483647 || result < -2147483648)
		return (-1);
	return (0);
}

int	check_int(char *line, int i, char sep)
{
	long	result;
	int		minus;

	if (sep == ' ')
		return (check_int_isspace(line, i));
	result = 0;
	minus = 1;
	if (line[i] == '-')
	{
		minus *= -1;
		i++;
	}
	while (line[i] && (line[i] != sep) && line[i] >= '0' && line[i] <= '9')
	{
		result = result * 10 + (line[i] - 48);
		i++;
	}
	result *= minus;
	if (result > 2147483647 || result < -2147483648)
		return (-1);
	return (0);
}
