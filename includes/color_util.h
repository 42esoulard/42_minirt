/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:06:01 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 13:11:33 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_UTIL_H
# define COLOR_UTIL_H

# include "../includes/mini_rt.h"

t_color	init_color(double blue, double green, double red);
t_color	mult_colors(double a, t_color b);
double	check_color(double color);
t_color check_colors(t_color color);
t_color	add_colors(t_color a, t_color b);
t_color	div_colors(t_color a, double b);
t_color	mult_two_colors(t_color a, t_color b);

#endif
