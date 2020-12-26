/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:31:07 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:56:29 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CHECKS_H
# define PARSING_CHECKS_H

# include "../includes/variables.h"
# include "../includes/parsing_util.h"
# include "../libft/libft.h"

int	check_double(char *line, int i, char sep);
int	pass_spaces(char *line, int i, int count);
int	check_int(char *line, int i, char sep);

#endif
