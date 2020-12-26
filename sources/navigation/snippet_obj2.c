/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snippet_obj2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:52:54 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/22 15:18:56 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/snippet_obj.h"

int		rot_obj_plcy3(int kcode, t_vector *rot, double *diam, double *height)
{
	if (kcode == 126)
	{
		if ((*rot).z < 0)
			(*rot).y = add_range_plcy((*rot).y + 0.05);
		else
			(*rot).y = add_range_plcy((*rot).y - 0.05);
		if ((*rot).y < 0)
			(*rot).z = add_range_plcy((*rot).z - 0.05);
		else
			(*rot).z = add_range_plcy((*rot).z + 0.05);
	}
	if (kcode == 37)
		(*diam)++;
	else if (kcode == 38)
		(*diam)--;
	else if (kcode == 34)
		(*height)++;
	else if (kcode == 40)
		(*height)--;
	return (0);
}

int		rot_obj_plcy2(int kcode, t_vector *rot)
{
	if (kcode == 124)
	{
		if ((*rot).z < 0)
			(*rot).x = add_range_plcy((*rot).x + 0.05);
		else
			(*rot).x = add_range_plcy((*rot).x - 0.05);
		if ((*rot).x < 0)
			(*rot).z = add_range_plcy((*rot).z - 0.05);
		else
			(*rot).z = add_range_plcy((*rot).z + 0.05);
	}
	else if (kcode == 125)
	{
		if ((*rot).z < 0)
			(*rot).y = add_range_plcy((*rot).y - 0.05);
		else
			(*rot).y = add_range_plcy((*rot).y + 0.05);
		if ((*rot).y < 0)
			(*rot).z = add_range_plcy((*rot).z + 0.05);
		else
			(*rot).z = add_range_plcy((*rot).z - 0.05);
	}
	return (0);
}

int		rot_obj_plcy(int kcode, t_vector *rot, double *diam, double *height)
{
	if (kcode == 123)
	{
		if ((*rot).z < 0)
			(*rot).x = add_range_plcy((*rot).x - 0.05);
		else
			(*rot).x = add_range_plcy((*rot).x + 0.05);
		if ((*rot).x < 0)
			(*rot).z = add_range_plcy((*rot).z + 0.05);
		else
			(*rot).z = add_range_plcy((*rot).z - 0.05);
	}
	rot_obj_plcy2(kcode, rot);
	rot_obj_plcy3(kcode, rot, diam, height);
	if (kcode >= 123 && kcode <= 126)
		return (1);
	return (0);
}

int		rot_obj(int keycode, t_vector *rotation, double *diam, double *height)
{
	if (keycode == 123)
		(*rotation).y = add_range((*rotation).y + 0.05);
	else if (keycode == 124)
		(*rotation).y = add_range((*rotation).y - 0.05);
	else if (keycode == 125)
		(*rotation).x = add_range((*rotation).x - 0.05);
	else if (keycode == 126)
		(*rotation).x = add_range((*rotation).x + 0.05);
	if (keycode == 37)
		(*diam)++;
	else if (keycode == 38)
		(*diam)--;
	else if (keycode == 34)
		(*height)++;
	else if (keycode == 40)
		(*height)--;
	if (keycode >= 123 && keycode <= 126)
		return (1);
	return (0);
}
