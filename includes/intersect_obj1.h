/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj1.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:04:12 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:52:28 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_OBJ1_H
# define INTERSECT_OBJ1_H

# include "../includes/mini_rt.h"

int	inter_cy2(t_ray ray, t_obj cy, t_bu *b_loc);
int	inter_cy3(t_ray ray, t_obj cy, t_bu *b_loc);
int	inter_cy(t_ray ray, t_obj cy, t_bu *b_loc);

#endif
