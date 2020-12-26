/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snippet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:17:07 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/23 12:24:51 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/snippet.h"

t_color	snippet_add_dir_lights(t_bu b_i, t_ray ray, t_obj *s, t_color px_i)
{
	int		i;
	int		inter_lt;
	double	stock_px;

	i = -1;
	while (++i < g_light_nb)
	{
		b_i.shadow.o = init_vector(0, 0, 0);
		b_i.shadow.d = init_vector(0, 0, 0);
		inter_lt = intersection_mult_light(ray, s, &b_i);
		b_i.d_light2 = square_norm(substr_vectors(g_light[i].pos, b_i.point));
		if (!(inter_lt == 1 && ((b_i.t_lt * b_i.t_lt) < b_i.d_light2)))
		{
			stock_px = g_light[i].intensity *
			scal_vectors(get_norm(substr_vectors(g_light[i].pos, b_i.point)),
				b_i.normal) / b_i.d_light2;
			px_i = add_colors(px_i, mult_two_colors(mult_colors(stock_px,
				s[b_i.obj_id].albedo), g_light[i].color));
			px_i.b = fmax(0, fmin(255, (px_i.b)));
			px_i.g = fmax(0, fmin(255, (px_i.g)));
			px_i.r = fmax(0, fmin(255, (px_i.r)));
		}
	}
	return (px_i);
}

t_color	snippet_get_color(t_ray ray, t_obj *scene, t_color px_int)
{
	int		inter;
	t_bu	b_int;

	px_int = init_color(0, 0, 0);
	inter = intersection_mult(ray, scene, &b_int);
	if (inter == 1)
	{
		px_int = mult_colors(g_ambiant_light.intensity,
			div_colors(add_colors(scene[b_int.obj_id].albedo,
				g_ambiant_light.color), 2));
		px_int = snippet_add_dir_lights(b_int, ray, scene, px_int);
	}
	return (px_int);
}

void	snippet_routine_sqrt(void *bu, int i, int j)
{
	((t_bu *)bu)->ray.d = init_vector((j - ((g_h / 2) / 2)), (i -
		((g_w / 2) / 2)), (-(g_h / 2) / (2 * tan(g_fov / 2))));
	((t_bu *)bu)->ray.d = rot_xyz(((t_bu *)bu)->ray.d, mult_vectors(M_PI /
		2, g_target));
	normalize(&((t_bu *)bu)->ray.d);
	((t_bu *)bu)->px_int = add_colors(((t_bu *)bu)->px_int,
		snippet_get_color(((t_bu *)bu)->ray, ((t_bu *)bu)->scene,
			((t_bu *)bu)->px_int));
}

void	*snippet_routine(void *bu)
{
	int		i;
	int		j;

	i = 0;
	while (i < (g_w / 2))
	{
		j = ((t_bu *)bu)->j;
		while (j < (g_h / 2))
		{
			((t_bu *)bu)->px_int = init_color(0, 0, 0);
			snippet_routine_sqrt(bu, i, j);
			g_data_db[((g_w / 2) - i - 1) * (g_h / 2) + j] =
			init_color(((t_bu *)bu)->px_int.b, ((t_bu *)bu)->px_int.g,
				((t_bu *)bu)->px_int.r);
			if (i < (g_w / 2) - 1)
				g_data_db[((g_w / 2) - i - 2) * (g_h / 2) + j] =
			init_color(((t_bu *)bu)->px_int.b, ((t_bu *)bu)->px_int.g,
				((t_bu *)bu)->px_int.r);
			j++;
		}
		i += 2;
	}
	return (NULL);
}

t_data	*snippet_convert_db_to_uchar(t_data *g_data, t_color *g_data_db)
{
	int i;

	i = -1;
	while (++i < (g_h / 2) * (g_w / 2))
	{
		g_data[i].b = fmax(0, fmin(255, g_data_db[i].b));
		g_data[i].g = fmax(0, fmin(255, g_data_db[i].g));
		g_data[i].r = fmax(0, fmin(255, g_data_db[i].r));
	}
	return (g_data);
}
