/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_square.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:40:54 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/18 15:16:07 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_SQUARE_H
# define OBJ_SQUARE_H

# include "../includes/vector_util.h"
# include "../includes/color_util.h"
# include "../includes/rotation.h"

t_obj	address_square_o(t_vector vector);
t_obj	address_square_3d(t_vector o, t_vector d, t_obj square, double height);
t_obj	address_square_3d2(t_obj square, double height);
t_obj	*address_cube_3d(double height, t_obj	*cube);
t_obj	address_squarecube_3d(t_obj square, double height);

#endif
