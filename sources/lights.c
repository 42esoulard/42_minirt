/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:27:11 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/18 17:22:49 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lights.h"

void		switch_r(double *n1, double *n2, t_vector *n_trans, t_vector normal)
{
	*n1 = 1.3;
	*n2 = 1;
	*n_trans = mult_vectors(-1, normal);
}

t_color		add_transparency(t_ray ray, t_obj *scene, int *bnce, t_bu b_int)
{
	t_ray		ray_refract;
	t_vector	normal_trans;
	double		n1;
	double		n2;
	double		radical;

	n1 = 1;
	n2 = 1.3;
	normal_trans = b_int.normal;
	if (scene[b_int.obj_id].type == 's' &&
		scal_vectors(ray.d, b_int.normal) > 0)
		switch_r(&n1, &n2, &normal_trans, b_int.normal);
	radical = 1 - sqr(n1 / n2) * (1 - sqr(scal_vectors(normal_trans, ray.d)));
	if (radical > 0)
	{
		ray_refract.d = substr_vectors(mult_vectors((n1 / n2),
			substr_vectors(ray.d, mult_vectors(scal_vectors(ray.d,
				normal_trans), normal_trans))),
		mult_vectors(sqrt(radical), normal_trans));
		b_int.noise = mult_vectors(-0.001, normal_trans);
		ray_refract.o = add_vectors(b_int.point, b_int.noise);
		b_int.px_int = get_color(ray_refract, scene, *bnce - 1, b_int.px_int);
	}
	return (b_int.px_int);
}

t_color		add_mirror(t_ray ray, t_obj *scene, int *bounce, t_bu *b_int)
{
	(*b_int).ray_mirror.d = substr_vectors(ray.d, mult_vectors(2 *
		scal_vectors((*b_int).normal, ray.d), (*b_int).normal));
	(*b_int).ray_mirror.o = add_vectors((*b_int).point, (*b_int).noise);
	(*b_int).px_int = get_color((*b_int).ray_mirror, scene, *bounce - 1,
		(*b_int).px_int);
	return ((*b_int).px_int);
}

t_color		add_dir_lights(t_bu b_int, t_ray ray, t_obj *s, t_color px_int)
{
	int		i;
	int		inter_lt;
	double	stock_px;

	i = -1;
	while (++i < g_light_nb)
	{
		b_int.shadow.o = add_vectors(b_int.point, b_int.noise);
		b_int.shadow.d = get_norm(substr_vectors(g_light[i].pos, b_int.point));
		inter_lt = intersection_mult_light(ray, s, &b_int);
		b_int.d_light2 = square_norm(substr_vectors(g_light[i].pos,
			b_int.point));
		if (!(inter_lt == 1 && ((b_int.t_lt * b_int.t_lt) < b_int.d_light2)))
		{
			stock_px = g_light[i].intensity *
			scal_vectors(get_norm(substr_vectors(g_light[i].pos,
				b_int.point)), b_int.normal) / b_int.d_light2;
			px_int = add_colors(px_int, mult_two_colors(mult_colors(stock_px,
				s[b_int.obj_id].albedo), g_light[i].color));
			px_int.b = fmax(0, fmin(255, (px_int.b)));
			px_int.g = fmax(0, fmin(255, (px_int.g)));
			px_int.r = fmax(0, fmin(255, (px_int.r)));
		}
	}
	return (px_int);
}
