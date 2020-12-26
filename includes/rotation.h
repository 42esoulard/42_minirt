/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:00:04 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:57:44 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATION_H
# define ROTATION_H

# include "../includes/mini_rt.h"

t_vector	rot_x(t_vector v, double r);
t_vector	rot_y(t_vector v, double r);
t_vector	rot_z(t_vector v, double r);
t_vector	rot_xyz(t_vector v, t_vector r);

#endif
