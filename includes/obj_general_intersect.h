/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_general_intersect.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:11:35 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:53:35 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_GENERAL_INTERSECT_H
# define OBJ_GENERAL_INTERSECT_H

# include "../includes/obj_sphere.h"
# include "../includes/mini_rt.h"

double g_t1;
double g_t2;

int intersection_mult(t_ray ray, t_obj *scene, t_bu *b_int);
int intersection_mult_light(t_ray ray, t_obj *spheres, t_bu *b_int);

#endif
