/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:52:43 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:52:18 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intersect_obj.h"

int	inter_sp(t_ray ray, t_obj sphere, t_bu *b_loc)
{
	double a;
	double b;
	double c;
	double delta;

	a = 1;
	b = 2 * scal_vectors(ray.d, (substr_vectors(ray.o, sphere.o)));
	c = (square_norm(substr_vectors(ray.o, sphere.o)) - sphere.diam *
		sphere.diam);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	g_t1 = (-b - sqrt(delta)) / (2 * a);
	g_t2 = (-b + sqrt(delta)) / (2 * a);
	if (g_t2 < 0)
		return (0);
	if (g_t1 > 0)
		(*b_loc).t = g_t1;
	else
		(*b_loc).t = g_t2;
	(*b_loc).point = add_vectors(ray.o, mult_vectors((*b_loc).t, ray.d));
	(*b_loc).normal = (get_norm(substr_vectors((*b_loc).point, sphere.o)));
	return (1);
}

int	inter_pl(t_ray ray, t_obj plan, t_bu *b_loc)
{
	double		scal;
	double		d;

	plan.dbase = get_norm(mult_vectors(M_PI / 2, plan.d));
	scal = scal_vectors(substr_vectors(ray.o, plan.o), plan.dbase);
	d = scal_vectors(ray.d, plan.dbase);
	if (d == 0)
		return (0);
	if (-scal / d > 0)
	{
		(*b_loc).t = -scal / d;
		(*b_loc).point = add_vectors(ray.o, mult_vectors((*b_loc).t, ray.d));
		(*b_loc).normal = (get_norm(substr_vectors(plan.dbase, plan.o)));
		return (1);
	}
	return (0);
}

int	inter_tr2(t_ray ray, t_bu *b_loc, t_vector *v)
{
	(*b_loc).t = (1 / scal_vectors(v[0], v[2])) * scal_vectors(v[1], v[4]);
	(*b_loc).normal = cross(get_norm(v[0]), get_norm(v[1]));
	if ((*b_loc).normal.x + (*b_loc).normal.y + (*b_loc).normal.z < 0)
		(*b_loc).normal = cross(get_norm(v[1]), get_norm(v[0]));
	(*b_loc).point = add_vectors(ray.o, mult_vectors((*b_loc).t, ray.d));
	return (1);
}

int	inter_tr(t_ray ray, t_obj tr, t_bu *b_loc)
{
	double		a;
	double		b;
	double		c;
	t_vector	v[5];

	v[0] = substr_vectors(tr.t_corner1, tr.t_corner0);
	v[1] = substr_vectors(tr.t_corner2, tr.t_corner0);
	v[2] = cross(ray.d, v[1]);
	a = scal_vectors(v[0], v[2]);
	if (a == 0)
		return (0);
	a = 1 / a;
	v[3] = substr_vectors(ray.o, tr.t_corner0);
	b = a * scal_vectors(v[3], v[2]);
	if (b < 0 || b > 1)
		return (0);
	v[4] = cross(v[3], v[0]);
	c = a * scal_vectors(ray.d, v[4]);
	if (c < 0.0 || b + c > 1.0)
		return (0);
	b = a * scal_vectors(v[1], v[4]);
	if (b > 0.001)
		return (inter_tr2(ray, b_loc, v));
	return (0);
}

int	inter_sq(t_ray ray, t_obj square, t_bu *b_loc)
{
	t_obj triangle1;
	t_obj triangle2;

	square.tri1 = &triangle1;
	square.tri2 = &triangle2;
	((t_obj *)square.tri1)->o = square.o;
	((t_obj *)square.tri1)->d = square.d;
	((t_obj *)square.tri1)->t_corner0 = square.sq_corner0;
	((t_obj *)square.tri1)->t_corner1 = square.sq_corner1;
	((t_obj *)square.tri1)->t_corner2 = square.sq_corner2;
	if (inter_tr(ray, triangle1, b_loc) == 1)
		return (1);
	((t_obj *)square.tri2)->o = square.o;
	((t_obj *)square.tri2)->d = square.d;
	((t_obj *)square.tri2)->t_corner0 = square.sq_corner2;
	((t_obj *)square.tri2)->t_corner1 = square.sq_corner3;
	((t_obj *)square.tri2)->t_corner2 = square.sq_corner0;
	if (inter_tr(ray, triangle2, b_loc) == 1)
		return (1);
	return (0);
}
