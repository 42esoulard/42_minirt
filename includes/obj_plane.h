/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:16:44 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/18 14:45:44 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PLANE_H
# define OBJ_PLANE_H

# include "../includes/vector_util.h"
# include "../includes/color_util.h"

t_obj	address_plane_o(t_vector vector);
t_obj	address_plane_3d(t_vector o, t_vector d);

#endif
