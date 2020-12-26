/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:12:03 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/19 12:35:43 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obj_triangle.h"

t_vector	triangle_normal(t_obj triangle)
{
	t_vector v;
	t_vector u;

	u = substr_vectors(triangle.t_corner1, triangle.t_corner0);
	v = substr_vectors(triangle.t_corner2, triangle.t_corner0);
	triangle.d = get_norm(cross(u, v));
	return (triangle.d);
}

t_vector	address_triangle_o(t_obj triangle)
{
	t_vector	origin;
	double		mid;

	mid = triangle.t_corner0.x - triangle.t_corner1.x;
	origin.x = (triangle.t_corner2.x - mid) / 3;
	mid = triangle.t_corner0.y - triangle.t_corner1.y;
	origin.y = (triangle.t_corner2.y - mid) / 3;
	mid = triangle.t_corner0.z - triangle.t_corner1.z;
	origin.z = (triangle.t_corner2.z - mid) / 3;
	return (origin);
}
