/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cylinder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:17:35 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/18 14:47:23 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_CYLINDER_H
# define OBJ_CYLINDER_H

# include "../includes/vector_util.h"
# include "../includes/color_util.h"

t_obj	address_cylinder_o(t_vector vector);
t_obj	address_cylinder_3d(t_vector o, t_vector d);

#endif
