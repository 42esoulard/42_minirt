/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snippet_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:26:54 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:12:28 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/snippet_util.h"

double	add_range(double d)
{
	if (d > 1)
		d = -1;
	else if (d < -1)
		d = 1;
	return (d);
}

double	add_range_plcy(double d)
{
	if (d > 1)
		d = 1;
	else if (d < -1)
		d = -1;
	return (d);
}

int		g_key_to_i(int key)
{
	int i;

	i = -1;
	if (key == 82 || key == 29)
		i = 0;
	else if (key == 83 || key == 18)
		i = 1;
	else if (key == 84 || key == 19)
		i = 2;
	else if (key == 85 || key == 20)
		i = 3;
	else if (key == 86 || key == 21)
		i = 4;
	else if (key == 87 || key == 22)
		i = 5;
	else if (key == 88 || key == 23)
		i = 6;
	else if (key == 89 || key == 24)
		i = 7;
	else if (key == 90 || key == 25)
		i = 8;
	else if (key == 91 || key == 26)
		i = 9;
	return (i);
}

int		find_i(t_obj *scene)
{
	int i;

	i = g_key_to_i(g_key);
	if (scene[i].type == 't' && scene[i].subtype == 'p')
		while (scene[i].type == 't')
			i++;
	if (scene[i].type == 'q' && scene[i].subtype == 'c')
		while (scene[i].subtype == 'c')
			i--;
	return (i);
}

void	init_hook(int on, int keycode)
{
	if (on == 1)
	{
		g_key = keycode;
		g_hook = 1;
	}
	else if (on == 0)
	{
		g_hook = 0;
		g_key = 0;
	}
}
