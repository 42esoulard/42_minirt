/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:57:04 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:58:36 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_UTIL_H
# define VECTOR_UTIL_H

# include "../includes/mini_rt.h"
# include <math.h>

t_vector	init_vector(double x, double y, double z);
t_vector	add_vectors(t_vector a, t_vector b);
t_vector	substr_vectors(t_vector a, t_vector b);
t_vector	mult_vectors(double a, t_vector b);
t_vector	mult_two_vectors(t_vector a, t_vector b);
t_vector	div_vectors(t_vector a, double b);
double		scal_vectors(t_vector a, t_vector b);
double		square_norm(t_vector a);
void		normalize(t_vector *a);
t_vector	get_norm(t_vector a);
double		sqr(double n1);
t_vector	cross(t_vector a, t_vector b);

#endif
