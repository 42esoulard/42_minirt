/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cam.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:05:55 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:56:17 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CAM_H
# define PARSING_CAM_H

# include "../libft/libft.h"
# include "../includes/variables.h"
# include "../includes/parsing_vector.h"
# include "../includes/vector_util.h"
# include "../includes/parsing_checks.h"

int		check_orientation_range(t_vector vector, int count);
int		add_fov(char *line, int *i, int count);
void	parse_cam(char *line, int count, int cam);

#endif
