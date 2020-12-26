/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:13:43 by esoulard          #+#    #+#             */
/*   Updated: 2019/10/22 19:49:56 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	i;
	int		div;
	long	o;

	div = 1;
	o = n;
	if (fd >= 0)
	{
		if (o < 0)
		{
			write(fd, "-", 1);
			o *= -1;
		}
		while ((o / div) > 9)
			div *= 10;
		while (div > 1)
		{
			i = ((o / div) % 10) + 48;
			write(fd, &i, 1);
			div /= 10;
		}
		i = (o % 10) + 48;
		write(fd, &i, 1);
	}
}
