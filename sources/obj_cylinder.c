/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:15:31 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/18 14:47:18 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obj_cylinder.h"

t_obj	address_cylinder_o(t_vector vector)
{
	t_obj cylinder;

	cylinder.type = 'y';
	cylinder.o.x = vector.x;
	cylinder.o.y = vector.y;
	cylinder.o.z = vector.z;
	return (cylinder);
}

t_obj	address_cylinder_3d(t_vector o, t_vector d)
{
	t_obj cylinder;

	cylinder = address_cylinder_o(o);
	if (d.x == 0 && d.y == 0 && d.z == 0)
		d.z = 1;
	cylinder.d.x = d.x;
	cylinder.d.y = d.y;
	cylinder.d.z = d.z;
	return (cylinder);
}
