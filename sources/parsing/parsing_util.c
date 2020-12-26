/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:33:52 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/24 15:25:04 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing_util.h"

double	ft_dec_atoi2(const char *str, int i)
{
	double	count;
	double	dec;

	count = 1;
	dec = 0;
	while (str[i] == '0')
	{
		count *= 0.1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		dec = dec * 10 + (str[i] - 48);
		i++;
	}
	while (dec >= 1)
		dec = dec / 10;
	dec *= count;
	return (dec);
}

double	ft_dec_atoi(const char *str)
{
	double	result;
	double	minus;
	int		i;

	i = 0;
	result = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (str[i++] == '.')
		result += ft_dec_atoi2(str, i);
	return (result * minus);
}

void	error_msg2(int nb, int count)
{
	if (nb == 7)
	{
		ft_printf("\033[1;31mError n7 - Invalid input : line %d :", count);
		ft_printf(" light intensity should be between 0 & 1\n", count);
	}
	else if (nb == 8)
	{
		ft_printf("\033[1;31mError n8 - Invalid input : line %d : ", count);
		ft_printf("color should be between 0 & 255.\n", count);
	}
	else if (nb == 9)
	{
		ft_printf("\033[1;31mError n9 - Invalid input : line %d : ", count);
		ft_printf("orientation should be between -1 & 1.\n", count);
	}
	else if (nb == 10)
	{
		ft_printf("\033[1;31mError n0 - Unable to read .rt file !\n");
		ft_printf("Command line format : ./minirt [-save] [filename.rt]\n");
	}
	else if (nb == 11)
		ft_printf("\033[1;31mError n11 - Couldn't save image !\n");
}

int		error_msg(int nb, int count)
{
	if (nb == 0)
	{
		ft_printf("\033[1;31mError n0 - Wrong argument count/format !");
		ft_printf(" Command line format : ./minirt [filename.rt] [-save]\n");
	}
	else if (nb == 1)
	{
		ft_printf("\033[1;31mError n1 - Image resolution and ambiant light");
		ft_printf("must be declared once to generate image\n");
	}
	else if (nb == 2)
		ft_printf("\033[1;31mError n2 - Bad syntax : line %d\n");
	else if (nb == 3)
		ft_printf("\033[1;31mError n3 - Invalid input : line %d\n", count);
	else if (nb == 4)
		ft_printf("\033[1;31mError n4 - Bad value : line %d\n", count);
	else if (nb == 6)
	{
		ft_printf("\033[1;31mError n6 - Invalid input : line %d :", count);
		ft_printf(" mirror or transparency options shoud be booleans\n", count);
	}
	error_msg2(nb, count);
	free_all();
	exit(0);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
