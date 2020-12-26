/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snippet_obj.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:23:23 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:58:15 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNIPPET_OBJ_H
# define SNIPPET_OBJ_H

# include "../includes/color_util.h"
# include "../includes/variables.h"

void	reinit_pyramid(t_obj *scene, int i, t_obj square);
void	reinit_cube(t_obj *scene, int i);
void	check_obj(t_obj *scene, int i, int trans, int rot);
int		trans_obj(int keycode, t_vector *translation);
int		rot_obj(int keycode, t_vector *rotation, double *diam, double *height);
int		rot_obj_plcy(int kcode, t_vector *rot, double *diam, double *height);

#endif
