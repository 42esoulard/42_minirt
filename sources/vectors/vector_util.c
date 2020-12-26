/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:31:08 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:13:07 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector_util.h"

t_vector	init_vector(double x, double y, double z)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector	add_vectors(t_vector a, t_vector b)
{
	t_vector ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vector	substr_vectors(t_vector a, t_vector b)
{
	t_vector ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

t_vector	mult_vectors(double a, t_vector b)
{
	t_vector ret;

	ret.x = a * b.x;
	ret.y = a * b.y;
	ret.z = a * b.z;
	return (ret);
}

t_vector	mult_two_vectors(t_vector a, t_vector b)
{
	t_vector ret;

	ret.x = a.x * b.x;
	ret.y = a.y * b.y;
	ret.z = a.z * b.z;
	return (ret);
}
