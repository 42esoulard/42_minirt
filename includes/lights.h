/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:31:38 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 13:11:21 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_H
# define LIGHTS_H

# include "../includes/vector_util.h"
# include "../includes/color_util.h"

void		switch_r(double *n1, double *n2, t_vector *n_trans,
	t_vector normal);
t_color		add_transparency(t_ray ray, t_obj *scene, int *bnce, t_bu b_int);
t_color		add_mirror(t_ray ray, t_obj *scene, int *bounce, t_bu *b_int);
t_color		add_dir_lights(t_bu b_int, t_ray ray, t_obj *s, t_color px_int);

#endif
