/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:41:42 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/19 12:46:12 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "../includes/variables.h"
# include "../includes/lights.h"
# include "../includes/vector_util.h"
# include "../includes/color_util.h"

t_color		get_color(t_ray ray, t_obj *scene, int bounce, t_color px_int);
void		routine_sqrt(void *bu, int i, int j, double *k);
void		*routine(void *bu);
t_data		*convert_db_to_uchar(t_data *g_data, t_color *g_data_db);
t_bu		fill_b_routine(t_obj *scene, int k);
void		loading_print(int j, int i);

#endif
