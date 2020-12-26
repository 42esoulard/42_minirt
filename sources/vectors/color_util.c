/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:56:32 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:13:01 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color_util.h"
#include "../../includes/mini_rt.h"

t_color	init_color(double blue, double green, double red)
{
	t_color color;

	color.b = blue;
	color.g = green;
	color.r = red;
	color.a = 0;
	return (color);
}

t_color	mult_colors(double a, t_color b)
{
	t_color ret;

	ret.b = a * b.b;
	ret.g = a * b.g;
	ret.r = a * b.r;
	return (ret);
}

t_color	mult_two_colors(t_color a, t_color b)
{
	t_color ret;

	ret.b = a.b * b.b;
	ret.g = a.g * b.g;
	ret.r = a.r * b.r;
	return (ret);
}

t_color	add_colors(t_color a, t_color b)
{
	t_color ret;

	ret.b = a.b + b.b;
	ret.g = a.g + b.g;
	ret.r = a.r + b.r;
	return (ret);
}

t_color	div_colors(t_color a, double b)
{
	t_color ret;

	ret.b = a.b / b;
	ret.g = a.g / b;
	ret.r = a.r / b;
	return (ret);
}
