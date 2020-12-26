/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pyramid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:24:31 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/19 13:49:47 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obj_triangle.h"

t_obj		trans_triangle(t_obj triangle)
{
	triangle.t_corner0 = substr_vectors(triangle.t_corner0,
		substr_vectors(triangle.obase, triangle.o));
	triangle.t_corner1 = substr_vectors(triangle.t_corner1,
		substr_vectors(triangle.obase, triangle.o));
	triangle.t_corner2 = substr_vectors(triangle.t_corner2,
		substr_vectors(triangle.obase, triangle.o));
	triangle.o = triangle.obase;
	return (triangle);
}

void		address_triangles(double height, t_obj sq, t_obj *tr)
{
	int			i;
	t_vector	summit;

	summit = add_vectors(sq.o, rot_xyz(init_vector(0, 0,
		-height / 2), mult_vectors(M_PI, sq.d)));
	i = -1;
	while (++i < 4)
	{
		tr[i].type = 't';
		tr[i].subtype = 'p';
		tr[i].t_corner0 = summit;
	}
	tr[0].t_corner1 = sq.sq_corner0;
	tr[0].t_corner2 = sq.sq_corner1;
	tr[1].t_corner1 = sq.sq_corner1;
	tr[1].t_corner2 = sq.sq_corner2;
	tr[2].t_corner1 = sq.sq_corner2;
	tr[2].t_corner2 = sq.sq_corner3;
	tr[3].t_corner1 = sq.sq_corner3;
	tr[3].t_corner2 = sq.sq_corner0;
}
