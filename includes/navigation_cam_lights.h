/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation_cam_lights.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:12:18 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:53:15 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAVIGATION_CAM_LIGHTS_H
# define NAVIGATION_CAM_LIGHTS_H

# include "../includes/vector_util.h"
# include "../includes/navigation_util.h"
# include "../includes/variables.h"

void	nav_amb_light(int keycode);
void	nav_light(int keycode, int i);
int		rotate_cam(int keycode, t_vector *rotation);
void	cam_mov(int keycode, int *rot, int *trans);

#endif
