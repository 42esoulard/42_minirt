/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:54:19 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:52:22 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_OBJ_H
# define INTERSECT_OBJ_H

# include "../includes/mini_rt.h"

int	inter_sp(t_ray ray, t_obj sphere, t_bu *b_loc);
int	inter_pl(t_ray ray, t_obj plan, t_bu *b_loc);
int	inter_tr(t_ray ray, t_obj tr, t_bu *b_loc);
int	inter_sq(t_ray ray, t_obj square, t_bu *b_loc);
int	inter_cy(t_ray ray, t_obj cy, t_bu *b_loc);

#endif
