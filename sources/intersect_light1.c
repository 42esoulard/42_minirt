/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_light1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:00:36 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:52:12 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intersect_light1.h"

int	inter_cy_light2(t_ray ray, t_obj cy, t_bu *b_loc, t_ray shadow)
{
	double		len;
	double		stock;
	t_vector	x;

	if ((*b_loc).t > 0)
	{
		x = substr_vectors(shadow.o, cy.o);
		(*b_loc).point = add_vectors(substr_vectors(shadow.o, ray.o),
			mult_vectors((*b_loc).t, shadow.d));
		stock = scal_vectors(shadow.d, mult_vectors((*b_loc).t,
			cy.d)) + scal_vectors(x, cy.d);
		(*b_loc).normal = add_vectors(cy.o, mult_vectors(stock, cy.d));
		(*b_loc).normal = get_norm(substr_vectors((*b_loc).point,
			(*b_loc).normal));
		len = scal_vectors((*b_loc).point, cy.d);
		if (len < cy.height / 2 && len > -cy.height / 2)
			return (1);
	}
	return (0);
}

int	inter_cy_light3(t_ray ray, t_obj cy, t_bu *b_loc, t_ray shadow)
{
	double		len;
	double		stock;
	t_vector	x;

	if ((*b_loc).t > 0)
	{
		x = substr_vectors(shadow.o, cy.o);
		(*b_loc).point = add_vectors(substr_vectors(shadow.o,
			ray.o), mult_vectors((*b_loc).t, shadow.d));
		stock = scal_vectors(shadow.d, mult_vectors((*b_loc).t,
			cy.d)) + scal_vectors(x, cy.d);
		(*b_loc).normal = add_vectors(cy.o, mult_vectors(stock, cy.d));
		(*b_loc).normal = get_norm(substr_vectors((*b_loc).point,
			(*b_loc).normal));
		len = scal_vectors((*b_loc).point, cy.d);
		if (len < cy.height / 2 && len > -cy.height / 2)
			return (1);
	}
	return (0);
}

int	inter_cy_light(t_ray ray, t_obj cy, t_bu *b_loc, t_ray shadow)
{
	double		abcd[4];
	t_vector	tmp[3];

	cy.d = get_norm(mult_vectors(M_PI / 2, cy.d));
	tmp[2] = substr_vectors(shadow.o, cy.o);
	tmp[0] = substr_vectors(shadow.d,
		mult_vectors(scal_vectors(shadow.d, cy.d), cy.d));
	tmp[1] = substr_vectors(tmp[2],
		mult_vectors(scal_vectors(tmp[2], cy.d), cy.d));
	abcd[0] = scal_vectors(tmp[0], tmp[0]);
	abcd[1] = 2 * scal_vectors(tmp[0], tmp[1]);
	abcd[2] = scal_vectors(tmp[1], tmp[1]) - pow(cy.diam, 2);
	abcd[3] = abcd[1] * abcd[1] - 4 * abcd[0] * abcd[2];
	if (abcd[3] >= 0)
	{
		(*b_loc).t = (-abcd[1] - sqrt(abcd[3])) / (2 * abcd[0]);
		if (inter_cy_light2(ray, cy, b_loc, shadow) == 1)
			return (1);
		(*b_loc).t = (-abcd[1] + sqrt(abcd[3])) / (2 * abcd[0]);
		if (inter_cy_light3(ray, cy, b_loc, shadow) == 1)
			return (1);
	}
	return (0);
}
