/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snippet_util.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:27:05 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:58:26 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNIPPET_UTIL_H
# define SNIPPET_UTIL_H

# include "../includes/color_util.h"
# include "../includes/variables.h"

double	add_range(double d);
int		g_key_to_i(int key);
int		find_i(t_obj *scene);
void	init_hook(int on, int keycode);
double	add_range_plcy(double d);

#endif
