/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_triangle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:14:46 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/19 12:33:16 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_TRIANGLE_H
# define OBJ_TRIANGLE_H

# include "../includes/vector_util.h"
# include "../includes/color_util.h"
# include "../includes/rotation.h"

void		address_triangles(double height, t_obj sq, t_obj *tr);
t_obj		trans_triangle(t_obj triangle);
t_obj		address_pyramid_base(t_vector corner1, t_vector corner2);
void		address_triangles(double height, t_obj sq, t_obj *tr);
t_vector	triangle_normal(t_obj triangle);
t_vector	address_triangle_o(t_obj triangle);

#endif
