/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:44:21 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:53:52 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obj_sphere.h"

t_obj	address_sphere(t_vector vector)
{
	t_obj sphere;

	sphere.type = 's';
	sphere.o.x = vector.x;
	sphere.o.y = vector.y;
	sphere.o.z = vector.z;
	return (sphere);
}
