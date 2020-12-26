/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_amb.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:27:03 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:56:02 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_AMB_H
# define PARSING_AMB_H

# include "../includes/variables.h"
# include "../includes/parsing_checks.h"
# include "../includes/parsing_util.h"
# include "../libft/libft.h"

int parse_amb_color2(char *line, int count, int i, int j);
int parse_amb_color(char *line, int count, int i, int j);
int	parse_amb_light(char *line, int count);
int	check_line(char *line, int i, int j, int count);

#endif
