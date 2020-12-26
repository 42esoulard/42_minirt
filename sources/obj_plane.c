/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:11:54 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/18 14:45:20 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obj_plane.h"

t_obj	address_plane_o(t_vector vector)
{
	t_obj plane;

	plane.type = 'p';
	plane.o.x = vector.x;
	plane.o.y = vector.y;
	plane.o.z = vector.z;
	return (plane);
}

t_obj	address_plane_3d(t_vector o, t_vector d)
{
	t_obj plane;

	plane = address_plane_o(o);
	if (d.x == 0 && d.y == 0 && d.z == 0)
		d.z = 1;
	plane.d.x = d.x;
	plane.d.y = d.y;
	plane.d.z = d.z;
	return (plane);
}
