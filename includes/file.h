/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:56:08 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 13:11:31 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "../libft/libft.h"
# include "../includes/parsing_win.h"
# include "../includes/parsing_amb.h"
# include "../includes/parsing_cam.h"
# include "../includes/parsing_light.h"
# include "../includes/parse_obj.h"
# include <fcntl.h>

int		parse_it(char *line, int count, int *valid);
int		read_rt(int ac, char **av, int fd, int count);
int		parse_int(char *line, int *i, int count);
double	parse_double(char *line, int *i, int count);
int		is_empty(char *line);
void	init_globals(int what);

#endif
