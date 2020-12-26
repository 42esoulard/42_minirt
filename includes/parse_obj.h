/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:21:23 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:02:49 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_OBJ_H
# define PARSE_OBJ_H

# include "../libft/libft.h"
# include "../includes/parsing_win.h"
# include "../includes/parsing_amb.h"
# include "../includes/parsing_cam.h"
# include "../includes/parsing_light.h"
# include "../includes/parsing_util.h"
# include "../includes/file.h"

void parse_options(char *line, int i, int count);
void parse_sphere(char *line, int count);
void parse_plane(char *line, int count);
void parse_square(char *line, int count);
void parse_cy(char *line, int count);
void parse_tr(char *line, int count);
void parse_cube(char *line, int count);
void parse_pyramid(char *line, int count);
void parse_py_square(char *line, int count);

#endif
