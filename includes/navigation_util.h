/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation_util.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 10:39:00 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:53:21 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAVIGATION_UTIL_H
# define NAVIGATION_UTIL_H

# include "../includes/vector_util.h"

int	key_hook(int keycode, void *param);
int find_obj_nb(t_obj *scene, int keycode);

#endif
