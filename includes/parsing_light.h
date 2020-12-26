/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:45:10 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:57:02 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_LIGHT_H
# define PARSING_LIGHT_H

# include "../includes/variables.h"
# include "../includes/parsing_checks.h"
# include "../includes/parsing_util.h"
# include "../includes/parsing_vector.h"
# include "../includes/color_util.h"
# include "../libft/libft.h"

void	parse_light(char *line, int count);
t_color	parse_color(char *line, int count, int *i, int j);
int		check_parsed_color(t_color color, int count);

#endif
