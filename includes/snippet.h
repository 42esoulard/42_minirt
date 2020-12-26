/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snippet.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:17:16 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/18 18:16:19 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNIPPET_H
# define SNIPPET_H

# include "../includes/color_util.h"
# include "../includes/variables.h"

t_color		snippet_add_dir_lights(t_bu b_i, t_ray ray, t_obj *s, t_color px_i);
t_color		snippet_get_color(t_ray ray, t_obj *scene, t_color px_int);
void		snippet_routine_sqrt(void *bu, int i, int j);
void		*snippet_routine(void *bu);
t_data		*snippet_convert_db_to_uchar(t_data *g_data, t_color *g_data_db);

#endif
