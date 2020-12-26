/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_light.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:58:18 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:52:09 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_LIGHT_H
# define INTERSECT_LIGHT_H

# include "../includes/mini_rt.h"

int	inter_sp_light(t_ray ray, t_obj sphere, t_bu *b_loc, t_ray shadow);
int	inter_pl_light(t_ray ray, t_obj plan, t_bu *b_loc, t_ray shadow);
int	inter_tr_light(t_ray ray, t_obj tr, t_bu *b_loc, t_ray shadow);
int	inter_sq_light(t_ray ray, t_obj square, t_bu *b_loc, t_ray shadow);
int	inter_cy_light(t_ray ray, t_obj cy, t_bu *b_loc, t_ray shadow);

#endif
