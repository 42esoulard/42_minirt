/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_light1.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:00:47 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:52:15 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_LIGHT1_H
# define INTERSECT_LIGHT1_H

# include "../includes/mini_rt.h"

int	inter_cy_light2(t_ray ray, t_obj cy, t_bu *b_loc, t_ray shadow);
int	inter_cy_light3(t_ray ray, t_obj cy, t_bu *b_loc, t_ray shadow);
int	inter_cy_light(t_ray ray, t_obj cy, t_bu *b_loc, t_ray shadow);

#endif
