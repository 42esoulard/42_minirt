/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vector.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:49:10 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:57:24 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_VECTOR_H
# define PARSING_VECTOR_H

# include "../includes/variables.h"
# include "../includes/parsing_checks.h"
# include "../includes/parsing_util.h"
# include "../includes/vector_util.h"
# include "../libft/libft.h"

double		entor_vector_z(char *line, int *i, int count);
double		entor_vector_y(char *line, int *i, int count);
double		entor_vector_x(char *line, int *i, int count);
t_vector	entor_vector(char *line, int *i, int count);

#endif
