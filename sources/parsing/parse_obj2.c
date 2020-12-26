/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:06:14 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/22 09:51:08 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse_obj.h"

void	parse_tr(char *line, int count)
{
	int i;

	g_nb_obj++;
	i = 2;
	g_scene[g_nb_obj].t_corner0 = entor_vector(line, &i, count);
	g_scene[g_nb_obj].t_corner1 = entor_vector(line, &i, count);
	g_scene[g_nb_obj].t_corner2 = entor_vector(line, &i, count);
	g_scene[g_nb_obj].o = address_triangle_o(g_scene[g_nb_obj]);
	g_scene[g_nb_obj].obase = g_scene[g_nb_obj].o;
	g_scene[g_nb_obj].d = triangle_normal(g_scene[g_nb_obj]);
	g_scene[g_nb_obj].albedo = parse_color(line, count, &i, 0);
	g_scene[g_nb_obj].type = 't';
	check_parsed_color(g_scene[g_nb_obj].albedo, count);
	i = pass_spaces(line, i, count);
	parse_options(line, i, count);
}

t_obj	parse_cube2(t_obj base)
{
	t_obj cube;

	cube.o = init_vector(0, 0, 0);
	cube.d = init_vector(0, 0, 0);
	cube.height = base.height;
	cube.albedo = base.albedo;
	cube.mirror = base.mirror;
	cube.transparent = base.transparent;
	return (cube);
}

void	parse_cube(char *line, int count)
{
	int		i;
	t_obj	cube[6];

	parse_square(line, count);
	g_scene[g_nb_obj].subtype = 'b';
	cube[0] = g_scene[g_nb_obj];
	i = 0;
	while (++i < 6)
		cube[i] = parse_cube2(cube[0]);
	address_cube_3d(cube[0].height, cube);
	i = 0;
	cube[i].type = 'q';
	g_scene[g_nb_obj++] = cube[i++];
	while (i < 6)
	{
		g_scene[g_nb_obj] = cube[i++];
		g_scene[g_nb_obj].type = 'q';
		g_scene[g_nb_obj++].subtype = 'c';
	}
	g_nb_obj--;
}

void	parse_py_square(char *line, int count)
{
	int			i;

	g_nb_obj++;
	i = 2;
	g_scene[g_nb_obj] = address_square_3d(entor_vector(line, &i, count),
		entor_vector(line, &i, count), g_scene[g_nb_obj],
		parse_double(line, &i, count));
	check_orientation_range(g_scene[g_nb_obj].d, count);
	g_scene[g_nb_obj].diam = parse_double(line, &i, count);
	g_scene[g_nb_obj].albedo = parse_color(line, count, &i, 0);
	check_parsed_color(g_scene[g_nb_obj].albedo, count);
	g_scene[g_nb_obj].type = 'q';
	i = pass_spaces(line, i, count);
	parse_options(line, i, count);
}

void	parse_pyramid(char *line, int count)
{
	int		i;
	int		save;
	t_obj	py[4];

	parse_py_square(line, count);
	g_scene[g_nb_obj].subtype = 'p';
	save = g_nb_obj;
	address_triangles(g_scene[g_nb_obj].diam, g_scene[g_nb_obj], py);
	i = 0;
	while (i < 4)
	{
		py[i].albedo = g_scene[save].albedo;
		py[i].mirror = g_scene[save].mirror;
		py[i].transparent = g_scene[save].transparent;
		g_scene[++g_nb_obj] = py[i++];
	}
}
