/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:34:33 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:13:04 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color_util.h"
#include "../../includes/mini_rt.h"

double		check_color(double color)
{
	if (color > 255)
		color = 255;
	if (color < 0)
		color = 0;
	return (color);
}

t_color		check_colors(t_color color)
{
	color.b = check_color(color.b);
	color.g = check_color(color.g);
	color.r = check_color(color.r);
	return (color);
}
