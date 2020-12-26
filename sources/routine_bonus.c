/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:41:55 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/21 19:16:03 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/routine.h"

t_color		get_color(t_ray ray, t_obj *scene, int bounce, t_color px_int)
{
	int		inter;
	t_bu	b_int;

	px_int = init_color(0, 0, 0);
	if (bounce == 0)
		return (px_int);
	inter = intersection_mult(ray, scene, &b_int);
	b_int.noise = mult_vectors(0.001, b_int.normal);
	if (inter == 1)
	{
		px_int = mult_colors(g_ambiant_light.intensity,
			div_colors(add_colors(scene[b_int.obj_id].albedo,
				g_ambiant_light.color), 2));
		if (scene[b_int.obj_id].mirror == 1)
			px_int = add_mirror(ray, scene, &bounce, &b_int);
		else if (scene[b_int.obj_id].transparent == 1)
			px_int = add_transparency(ray, scene, &bounce, b_int);
		else
			px_int = add_dir_lights(b_int, ray, scene, px_int);
	}
	return (px_int);
}

void		routine_sqrt(void *bu, int i, int j, double *k)
{
	double a;

	a = 36;
	*k += sqrt(a) * (1 / a);
	((t_bu *)bu)->ray.d = init_vector((j - (g_h / 2)) + *k, (i - (g_w / 2)) +
		*k, (-g_h / (2 * tan(g_fov / 2))));
	((t_bu *)bu)->ray.d = rot_xyz(((t_bu *)bu)->ray.d, mult_vectors(M_PI / 2,
		g_target));
	normalize(&((t_bu *)bu)->ray.d);
	((t_bu *)bu)->px_int = add_colors(((t_bu *)bu)->px_int,
		get_color(((t_bu *)bu)->ray, ((t_bu *)bu)->scene, 5,
			((t_bu *)bu)->px_int));
}

void		*routine(void *bu)
{
	int		i;
	int		j;
	double	k;

	i = -1;
	while (++i < g_w)
	{
		j = ((t_bu *)bu)->j;
		while (j < g_h)
		{
			k = 0;
			((t_bu *)bu)->px_int = init_color(0, 0, 0);
			while (k < 1)
				routine_sqrt(bu, i, j, &k);
			((t_bu *)bu)->px_int = div_colors(((t_bu *)bu)->px_int, 8);
			((t_bu *)bu)->color = init_color(((t_bu *)bu)->px_int.b,
				((t_bu *)bu)->px_int.g, ((t_bu *)bu)->px_int.r);
			g_data_db[(g_w - i - 1) * g_h + j] = (((t_bu *)bu)->color);
			j += 8;
		}
		loading_print(((t_bu *)bu)->j, i);
	}
	pthread_exit(NULL);
}

t_data		*convert_db_to_uchar(t_data *g_data, t_color *g_data_db)
{
	int i;

	i = -1;
	while (++i < g_h * g_w)
	{
		g_data[i].b = fmax(0, fmin(255, g_data_db[i].b));
		g_data[i].g = fmax(0, fmin(255, g_data_db[i].g));
		g_data[i].r = fmax(0, fmin(255, g_data_db[i].r));
	}
	return (g_data);
}

t_bu		fill_b_routine(t_obj *scene, int k)
{
	t_bu bundle;

	bundle.scene = scene;
	bundle.j = k;
	bundle.ray = g_ray;
	return (bundle);
}
