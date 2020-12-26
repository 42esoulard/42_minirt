/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:21:13 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/22 15:18:54 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse_obj.h"

void	parse_options(char *line, int i, int count)
{
	if (!line[i])
		g_scene[g_nb_obj].mirror = 0;
	else
		g_scene[g_nb_obj].mirror = parse_int(line, &i, count);
	i = pass_spaces(line, i, count);
	if (!line[i])
		g_scene[g_nb_obj].transparent = 0;
	else
		g_scene[g_nb_obj].transparent = parse_int(line, &i, count);
	if ((g_scene[g_nb_obj].mirror != 0 && g_scene[g_nb_obj].mirror != 1)
		|| (g_scene[g_nb_obj].transparent != 0 &&
			g_scene[g_nb_obj].transparent != 1))
		error_msg(6, count);
	i = pass_spaces(line, i, count);
	if (line[i])
		error_msg(3, count);
}

void	parse_sphere(char *line, int count)
{
	int i;

	g_nb_obj++;
	i = 2;
	g_scene[g_nb_obj] = address_sphere(entor_vector(line, &i, count));
	g_scene[g_nb_obj].diam = parse_double(line, &i, count);
	g_scene[g_nb_obj].diambase = g_scene[g_nb_obj].diam;
	g_scene[g_nb_obj].albedo = parse_color(line, count, &i, 0);
	check_parsed_color(g_scene[g_nb_obj].albedo, count);
	i = pass_spaces(line, i, count);
	if (!line[i])
		g_scene[g_nb_obj].mirror = 0;
	else
		g_scene[g_nb_obj].mirror = parse_int(line, &i, count);
	i = pass_spaces(line, i, count);
	if (!line[i])
		g_scene[g_nb_obj].transparent = 0;
	else
		g_scene[g_nb_obj].transparent = parse_int(line, &i, count);
	if ((g_scene[g_nb_obj].mirror != 0 && g_scene[g_nb_obj].mirror != 1) ||
	(g_scene[g_nb_obj].transparent != 0 && g_scene[g_nb_obj].transparent != 1))
		error_msg(6, count);
	i = pass_spaces(line, i, count);
	if (line[i])
		error_msg(3, count);
}

void	parse_plane(char *line, int count)
{
	int i;

	g_nb_obj++;
	i = 2;
	g_scene[g_nb_obj] = address_plane_3d(entor_vector(line, &i, count),
		entor_vector(line, &i, count));
	check_orientation_range(g_scene[g_nb_obj].d, count);
	g_scene[g_nb_obj].albedo = parse_color(line, count, &i, 0);
	check_parsed_color(g_scene[g_nb_obj].albedo, count);
	i = pass_spaces(line, i, count);
	if (!line[i])
		g_scene[g_nb_obj].mirror = 0;
	else
		g_scene[g_nb_obj].mirror = parse_int(line, &i, count);
	i = pass_spaces(line, i, count);
	if (!line[i])
		g_scene[g_nb_obj].transparent = 0;
	else
		g_scene[g_nb_obj].transparent = parse_int(line, &i, count);
	if ((g_scene[g_nb_obj].mirror != 0 && g_scene[g_nb_obj].mirror != 1) ||
	(g_scene[g_nb_obj].transparent != 0 && g_scene[g_nb_obj].transparent != 1))
		error_msg(6, count);
	i = pass_spaces(line, i, count);
	if (line[i])
		error_msg(3, count);
}

void	parse_square(char *line, int count)
{
	int			i;

	g_nb_obj++;
	i = 2;
	g_scene[g_nb_obj] = address_square_3d(entor_vector(line, &i, count),
		entor_vector(line, &i, count), g_scene[g_nb_obj],
		parse_double(line, &i, count));
	check_orientation_range(g_scene[g_nb_obj].d, count);
	g_scene[g_nb_obj].albedo = parse_color(line, count, &i, 0);
	check_parsed_color(g_scene[g_nb_obj].albedo, count);
	i = pass_spaces(line, i, count);
	g_scene[g_nb_obj].type = 'q';
	parse_options(line, i, count);
}

void	parse_cy(char *line, int count)
{
	int i;

	g_nb_obj++;
	i = 2;
	g_scene[g_nb_obj] = address_cylinder_3d(entor_vector(line, &i, count),
		entor_vector(line, &i, count));
	check_orientation_range(g_scene[g_nb_obj].d, count);
	g_scene[g_nb_obj].albedo = parse_color(line, count, &i, 0);
	check_parsed_color(g_scene[g_nb_obj].albedo, count);
	g_scene[g_nb_obj].diam = parse_double(line, &i, count);
	g_scene[g_nb_obj].diambase = g_scene[g_nb_obj].diam;
	g_scene[g_nb_obj].height = parse_double(line, &i, count);
	i = pass_spaces(line, i, count);
	parse_options(line, i, count);
}
