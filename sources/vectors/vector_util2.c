/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:32:54 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:13:09 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector_util.h"

t_vector	div_vectors(t_vector a, double b)
{
	t_vector ret;

	ret.x = a.x / b;
	ret.y = a.y / b;
	ret.z = a.z / b;
	return (ret);
}

double		scal_vectors(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double		square_norm(t_vector a)
{
	return ((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

void		normalize(t_vector *a)
{
	double norm;

	norm = sqrt(square_norm(*a));
	(*a).x = (*a).x / norm;
	(*a).y = (*a).y / norm;
	(*a).z = (*a).z / norm;
}

t_vector	get_norm(t_vector a)
{
	t_vector result;

	result = a;
	normalize(&result);
	return (result);
}
