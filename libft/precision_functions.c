/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:50:32 by esoulard          #+#    #+#             */
/*   Updated: 2019/11/10 15:28:42 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_precision(char *arg, int i)
{
	int start;
	int precision;

	precision = 0;
	if (arg[i] == '%' && i != 0)
		i--;
	while (arg[i] != '%' && i != 0)
		i--;
	i++;
	while (is_type(arg, i) == 0 && arg[i] != '.')
		i++;
	if (arg[i] == '.' && is_type(arg, i + 1) == 1)
		return (-2);
	if (arg[i++] == '.')
	{
		start = i;
		if (arg[i] == '-')
			return (-1);
		while (ft_isdigit(arg[i]) == 1)
			i++;
		while (start < i)
			precision = precision * 10 + (arg[start++] - 48);
		return (precision);
	}
	return (-1);
}

void	kill_that_precision(char *newret, char *ret, int precision, char type)
{
	int j;
	int k;
	int l;

	j = 0;
	k = 0;
	l = 0;
	if (type == 'p')
	{
		while (j < 2)
			newret[j++] = ret[l++];
		newret[j++] = '0';
		newret[j++] = 'x';
	}
	else
		while (j < 2)
			newret[j++] = ret[l++];
	if (ret[2] == '-' && ft_isdigit(ret[3]) == 1)
		newret[k++ + j] = ret[l++];
	while (k < (precision - actual_len(ret)))
		newret[k++ + j] = '0';
	while (k < precision)
		newret[k++ + j] = ret[l++];
	newret[k + j] = '\0';
}

char	*damn_large_precision(char *arg, int i, char *ret, int precision)
{
	char	*newret;

	if (ret[2] == '-' && ft_isdigit(ret[3]) == 1)
		precision += 2;
	if (arg[i] == 'p')
	{
		if (!(newret = ft_malloc("char", (precision + 5))))
			return (NULL);
		kill_that_precision(newret, ret, precision, 'p');
	}
	else
	{
		if (!(newret = ft_malloc("char", (precision + 3))))
			return (NULL);
		kill_that_precision(newret, ret, precision, 'r');
	}
	ft_free(ret);
	return (newret);
}

char	*make_empty_string(char *newret, char *ret, char type)
{
	int i;

	i = 0;
	if (type == 'p')
	{
		if (!(newret = ft_malloc("char", 5)))
			return (NULL);
	}
	else
	{
		if (!(newret = ft_malloc("char", 3)))
			return (NULL);
	}
	newret[i++] = 'R';
	newret[i++] = '1';
	if (type == 'p')
	{
		newret[i++] = '0';
		newret[i++] = 'x';
	}
	newret[i++] = '\0';
	ft_free(ret);
	return (newret);
}

char	*damn_precision(char *ret, char *arg, int i, int precision)
{
	char	*newret;
	int		conv;
	int		len;

	len = give_precision_a_damn_len(ret);
	conv = i;
	if (is_type(arg, i) == 0)
		conv++;
	newret = NULL;
	if (precision != -1)
	{
		while (arg[i] && arg[i] != '.')
			i--;
		if (arg[conv] == 's' && precision > 0 && precision <= len)
			return (damn_large_precision(arg, i, ret, precision));
		if (arg[i] == '.' && (conv == (i + 1) || precision <= len))
		{
			if (eligible_for_empty_str(arg, conv, precision, ret) == 1)
				return (make_empty_string(newret, ret, arg[conv]));
		}
		else if (precision > len && arg[conv] != 's' && arg[conv] != '%')
			return (damn_large_precision(arg, i, ret, precision));
	}
	return (ret);
}
