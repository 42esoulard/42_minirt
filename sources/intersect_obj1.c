/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:03:59 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:52:25 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intersect_obj1.h"

int	inter_cy2(t_ray ray, t_obj cy, t_bu *b_loc)
{
	double		len;
	double		stock;
	t_vector	x;

	if ((*b_loc).t > 0)
	{
		x = substr_vectors(ray.o, cy.o);
		(*b_loc).point = add_vectors(substr_vectors(ray.o,
			cy.o), mult_vectors((*b_loc).t, ray.d));
		stock = scal_vectors(ray.d, mult_vectors((*b_loc).t,
			cy.dbase)) + scal_vectors(x, cy.dbase);
		(*b_loc).normal = add_vectors(cy.o, mult_vectors(stock, cy.dbase));
		(*b_loc).normal = get_norm(substr_vectors((*b_loc).point,
			(*b_loc).normal));
		len = scal_vectors((*b_loc).point, cy.dbase);
		if (len < cy.height / 2 && len > -cy.height / 2)
			return (1);
	}
	return (0);
}

int	inter_cy3(t_ray ray, t_obj cy, t_bu *b_loc)
{
	double		len;
	double		stock;
	t_vector	x;

	if ((*b_loc).t > 0)
	{
		x = substr_vectors(ray.o, cy.o);
		(*b_loc).point = add_vectors(substr_vectors(ray.o,
			cy.o), mult_vectors((*b_loc).t, ray.d));
		stock = scal_vectors(ray.d, mult_vectors((*b_loc).t,
			cy.dbase)) + scal_vectors(x, cy.dbase);
		(*b_loc).normal = add_vectors(cy.o, mult_vectors(stock, cy.dbase));
		(*b_loc).normal = get_norm(substr_vectors((*b_loc).point,
			(*b_loc).normal));
		len = scal_vectors((*b_loc).point, cy.dbase);
		if (len < cy.height / 2 && len > -cy.height / 2)
			return (1);
	}
	return (0);
}

int	inter_cy(t_ray ray, t_obj cy, t_bu *b_loc)
{
	double		abcd[4];
	t_vector	tmp[3];

	cy.dbase = get_norm(mult_vectors(M_PI, cy.d));
	tmp[2] = substr_vectors(ray.o, cy.o);
	tmp[0] = substr_vectors(ray.d, mult_vectors(scal_vectors(ray.d,
		cy.dbase), cy.dbase));
	tmp[1] = substr_vectors(tmp[2], mult_vectors(scal_vectors(tmp[2],
		cy.dbase), cy.dbase));
	abcd[0] = scal_vectors(tmp[0], tmp[0]);
	abcd[1] = 2 * scal_vectors(tmp[0], tmp[1]);
	abcd[2] = scal_vectors(tmp[1], tmp[1]) - pow(cy.diam, 2);
	abcd[3] = abcd[1] * abcd[1] - 4 * abcd[0] * abcd[2];
	if (abcd[3] >= 0)
	{
		(*b_loc).t = (-abcd[1] - sqrt(abcd[3])) / (2 * abcd[0]);
		if (inter_cy2(ray, cy, b_loc) == 1)
			return (1);
		(*b_loc).t = (-abcd[1] + sqrt(abcd[3])) / (2 * abcd[0]);
		if (inter_cy3(ray, cy, b_loc) == 1)
			return (1);
	}
	return (0);
}
