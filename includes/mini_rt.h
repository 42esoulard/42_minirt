/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:59:48 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/19 18:25:27 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <pthread.h>
# include <mlx.h>
# include <stdlib.h>

# include "../includes/parsing_win.h"
# include "../includes/file.h"
# include "../includes/variables.h"
# include "../includes/vector_util.h"
# include "../includes/color_util.h"
# include "../includes/obj_sphere.h"
# include "../includes/obj_general_intersect.h"
# include "../includes/navigation_util.h"
# include "../includes/obj_plane.h"
# include "../includes/obj_square.h"
# include "../includes/obj_triangle.h"
# include "../includes/obj_cylinder.h"
# include "../includes/lights.h"
# include "../includes/routine.h"
# include "../includes/navigation_cam_lights.h"
# include "../includes/snippet.h"
# include "../includes/snippet2.h"
# include "../includes/snippet_obj.h"
# include "../includes/snippet_util.h"
# include "../includes/intersect_obj.h"
# include "../includes/intersect_light.h"
# include "../includes/intersect_light1.h"
# include "../includes/save_bmp.h"

int		minirt(int redo, int bmp, int k);
t_color	get_color(t_ray ray, t_obj *scene, int bounce, t_color px_int);
void	free_all(void);
int		exit_hook(void *param);

#endif
