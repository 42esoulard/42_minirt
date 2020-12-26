/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snippet_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:23:12 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/23 12:55:01 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/snippet_obj.h"

void	reinit_pyramid(t_obj *scene, int i, t_obj square)
{
	t_obj	py[4];
	int		j;
	int		save;

	address_triangles(square.diam, square, py);
	save = i;
	j = 0;
	while (j < 4)
	{
		py[j].albedo = scene[save].albedo;
		py[j].mirror = scene[save].mirror;
		py[j].transparent = scene[save].transparent;
		scene[++i] = py[j++];
	}
}

t_obj	reinit_cube2(t_obj *scene, int i, t_obj *cube)
{
	cube[0] = address_square_3d(scene[i].o, scene[i].d, cube[0],
		scene[i].height);
	cube[0].albedo = init_color(scene[i].albedo.r, scene[i].albedo.g,
		scene[i].albedo.b);
	cube[0].subtype = 'b';
	cube[0].type = 'q';
	cube[0].mirror = scene[i].mirror;
	cube[0].transparent = scene[i].transparent;
	return (cube[0]);
}

void	reinit_cube(t_obj *scene, int i)
{
	t_obj	cube[6];
	double	height;
	int		j;
	int		k;

	height = scene[i].height;
	cube[0] = reinit_cube2(scene, i, cube);
	j = 0;
	k = i;
	scene[i] = cube[0];
	while (++j < 6)
	{
		cube[j].type = 'q';
		cube[j].subtype = 'c';
		cube[j].height = height;
		cube[j].albedo = scene[++i].albedo;
		cube[j].mirror = cube[0].mirror;
		cube[j].transparent = cube[0].transparent;
	}
	address_cube_3d(height, cube);
	j = 0;
	cube[0].albedo = init_color(255, 0, 0);
	while (j < 6)
		scene[k++] = cube[j++];
}

void	check_obj(t_obj *scene, int i, int trans, int rot)
{
	t_color stock;

	stock = scene[i].albedo;
	if (scene[i].type == 't' && (trans == 1 || rot == 1 || scene[i].height
		!= scene[i].heightbase))
		scene[i] = trans_triangle(scene[i]);
	if (scene[i].type == 'q' && (trans == 1 || rot == 1 || scene[i].height
		!= scene[i].heightbase))
	{
		scene[i] = address_square_3d(scene[i].o, scene[i].d, scene[i],
			scene[i].height);
		if (scene[i].subtype == 'p')
			reinit_pyramid(scene, i, scene[i]);
		if (scene[i].subtype == 'b')
			reinit_cube(scene, i);
		scene[i].albedo = stock;
		scene[i].heightbase = scene[i].height;
		scene[i].type = 'q';
	}
	if (scene[i].type == 's' || scene[i].type == 'y')
	{
		if (scene[i].diam < 0)
			scene[i].diam = 0;
		scene[i].diambase = scene[i].diam;
	}
}

int		trans_obj(int keycode, t_vector *translation)
{
	if (keycode == 13)
		(*translation).y += 5;
	else if (keycode == 1)
		(*translation).y -= 5;
	else if (keycode == 0)
		(*translation).x -= 5;
	else if (keycode == 2)
		(*translation).x += 5;
	else if (keycode == 69)
		(*translation).z -= 5;
	else if (keycode == 78)
		(*translation).z += 5;
	if (keycode == 13 || (keycode > -1 && keycode < 3) || keycode == 69 ||
		keycode == 78)
		return (1);
	return (0);
}
