/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:34:27 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/19 13:12:06 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTIL_H
# define PARSING_UTIL_H

# include "../includes/mini_rt.h"

double	ft_dec_atoi(const char *str);
int		error_msg(int nb, int count);
int		is_space(char c);

#endif
