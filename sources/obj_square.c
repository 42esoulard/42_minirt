/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:39:31 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/18 16:13:20 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obj_square.h"

t_obj	address_square_o(t_vector vector)
{
	t_obj square;

	square.type = 'q';
	square.o.x = vector.x;
	square.o.y = vector.y;
	square.o.z = vector.z;
	return (square);
}

t_obj	address_square_3d(t_vector o, t_vector d, t_obj square, double height)
{
	square.d = d;
	square.o = o;
	square.obase = o;
	square.height = height;
	square.heightbase = height;
	if (square.d.x == 0 && square.d.y == 0 && square.d.z == 0)
		square.d.x = -1;
	square.sq_corner0 = init_vector(-square.height / 2, square.height / 2,
		square.height / 2);
	square.sq_corner0 = add_vectors(square.o, rot_xyz(square.sq_corner0,
		mult_vectors(M_PI, square.d)));
	square.sq_corner1 = init_vector(square.height / 2, square.height / 2,
		square.height / 2);
	square.sq_corner1 = add_vectors(square.o, rot_xyz(square.sq_corner1,
		mult_vectors(M_PI, square.d)));
	square.sq_corner2 = init_vector(square.height / 2, -square.height / 2,
		square.height / 2);
	square.sq_corner2 = add_vectors(square.o, rot_xyz(square.sq_corner2,
		mult_vectors(M_PI, square.d)));
	square.sq_corner3 = init_vector(-square.height / 2, -square.height / 2,
		square.height / 2);
	square.sq_corner3 = add_vectors(square.o, rot_xyz(square.sq_corner3,
		mult_vectors(M_PI, square.d)));
	return (square);
}

t_obj	address_square_3d2(t_obj square, double height)
{
	square.height = height;
	if (square.d.x == 0 && square.d.y == 0 && square.d.z == 0)
		square.d.x = -1;
	square.sq_corner0 = init_vector(-height / 2, height / 2, 0);
	square.sq_corner0 = add_vectors(square.o, rot_xyz(square.sq_corner0,
		mult_vectors(M_PI, square.d)));
	square.sq_corner1 = init_vector(height / 2, height / 2, 0);
	square.sq_corner1 = add_vectors(square.o, rot_xyz(square.sq_corner1,
		mult_vectors(M_PI, square.d)));
	square.sq_corner2 = init_vector(height / 2, -height / 2, 0);
	square.sq_corner2 = add_vectors(square.o, rot_xyz(square.sq_corner2,
		mult_vectors(M_PI, square.d)));
	square.sq_corner3 = init_vector(-height / 2, -height / 2, 0);
	square.sq_corner3 = add_vectors(square.o, rot_xyz(square.sq_corner3,
		mult_vectors(M_PI, square.d)));
	return (square);
}

t_obj	*address_cube_3d2(t_obj *cube)
{
	cube[3].sq_corner0 = init_vector(cube[1].sq_corner0.x, cube[1].sq_corner0.y,
		cube[1].sq_corner0.z);
	cube[3].sq_corner1 = init_vector(cube[1].sq_corner1.x, cube[1].sq_corner1.y,
		cube[1].sq_corner1.z);
	cube[3].sq_corner2 = init_vector(cube[0].sq_corner1.x, cube[0].sq_corner1.y,
		cube[0].sq_corner1.z);
	cube[3].sq_corner3 = init_vector(cube[0].sq_corner0.x, cube[0].sq_corner0.y,
		cube[0].sq_corner0.z);
	cube[4].sq_corner0 = init_vector(cube[1].sq_corner1.x, cube[1].sq_corner1.y,
		cube[1].sq_corner1.z);
	cube[4].sq_corner1 = init_vector(cube[1].sq_corner2.x, cube[1].sq_corner2.y,
		cube[1].sq_corner2.z);
	cube[4].sq_corner2 = init_vector(cube[0].sq_corner2.x, cube[0].sq_corner2.y,
		cube[0].sq_corner2.z);
	cube[4].sq_corner3 = init_vector(cube[0].sq_corner1.x, cube[0].sq_corner1.y,
		cube[0].sq_corner1.z);
	cube[5].sq_corner0 = init_vector(cube[1].sq_corner2.x, cube[1].sq_corner2.y,
		cube[1].sq_corner2.z);
	cube[5].sq_corner1 = init_vector(cube[1].sq_corner3.x, cube[1].sq_corner3.y,
		cube[1].sq_corner3.z);
	cube[5].sq_corner2 = init_vector(cube[0].sq_corner3.x, cube[0].sq_corner3.y,
		cube[0].sq_corner3.z);
	cube[5].sq_corner3 = init_vector(cube[0].sq_corner2.x, cube[0].sq_corner2.y,
		cube[0].sq_corner2.z);
	return (cube);
}

t_obj	*address_cube_3d(double height, t_obj *cube)
{
	(void)height;
	cube[1].o = add_vectors(cube[0].o, rot_xyz(init_vector(0, 0, height * 2),
		mult_vectors(M_PI, cube[0].d)));
	cube[1].d = init_vector(cube[0].d.x, cube[0].d.y, cube[0].d.z);
	cube[1].sq_corner0 = add_vectors(cube[0].sq_corner0, rot_xyz(init_vector(0,
		0, -height), mult_vectors(M_PI, cube[0].d)));
	cube[1].sq_corner1 = add_vectors(cube[0].sq_corner1, rot_xyz(init_vector(0,
		0, -height), mult_vectors(M_PI, cube[0].d)));
	cube[1].sq_corner2 = add_vectors(cube[0].sq_corner2, rot_xyz(init_vector(0,
		0, -height), mult_vectors(M_PI, cube[0].d)));
	cube[1].sq_corner3 = add_vectors(cube[0].sq_corner3, rot_xyz(init_vector(0,
		0, -height), mult_vectors(M_PI, cube[0].d)));
	cube[2].sq_corner0 = init_vector(cube[0].sq_corner3.x, cube[0].sq_corner3.y,
		cube[0].sq_corner3.z);
	cube[2].sq_corner1 = init_vector(cube[0].sq_corner0.x, cube[0].sq_corner0.y,
		cube[0].sq_corner0.z);
	cube[2].sq_corner2 = init_vector(cube[1].sq_corner0.x, cube[1].sq_corner0.y,
		cube[1].sq_corner0.z);
	cube[2].sq_corner3 = init_vector(cube[1].sq_corner3.x, cube[1].sq_corner3.y,
		cube[1].sq_corner3.z);
	return (address_cube_3d2(cube));
}
