/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_general_intersect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:11:25 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 11:53:31 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int	inter_type(t_ray ray, t_obj obj, t_bu *b_loc)
{
	int inter;

	inter = 0;
	if (obj.type == 's')
		inter = inter_sp(ray, obj, b_loc);
	else if (obj.type == 'p')
		inter = inter_pl(ray, obj, b_loc);
	else if (obj.type == 'q')
		inter = inter_sq(ray, obj, b_loc);
	else if (obj.type == 't')
		inter = inter_tr(ray, obj, b_loc);
	else if (obj.type == 'y')
		inter = inter_cy(ray, obj, b_loc);
	return (inter);
}

int	intersection_mult(t_ray ray, t_obj *obj, t_bu *b_int)
{
	int		local_has_inter;
	int		has_inter;
	t_bu	b_loc;

	b_loc.j = -1;
	(*b_int).t = 1E99;
	local_has_inter = 0;
	has_inter = 0;
	b_loc.t = 0;
	while (++(b_loc.j) < g_nb_obj)
	{
		local_has_inter = inter_type(ray, obj[b_loc.j], &(b_loc));
		if (local_has_inter == 1)
		{
			has_inter = 1;
			if (b_loc.t < (*b_int).t)
			{
				(*b_int).t = b_loc.t;
				(*b_int).point = b_loc.point;
				(*b_int).normal = b_loc.normal;
				(*b_int).obj_id = b_loc.j;
			}
		}
	}
	return (has_inter);
}

int	inter_tl(t_ray ray, t_obj obj, t_bu *b_loc, t_ray shadow)
{
	int inter;

	inter = 0;
	if (obj.type == 's')
		inter = inter_sp_light(ray, obj, b_loc, shadow);
	else if (obj.type == 'p')
		inter = inter_pl_light(ray, obj, b_loc, shadow);
	else if (obj.type == 't')
		inter = inter_tr_light(ray, obj, b_loc, shadow);
	else if (obj.type == 'q')
		inter = inter_sq_light(ray, obj, b_loc, shadow);
	else if (obj.type == 'y')
		inter = inter_cy_light(ray, obj, b_loc, shadow);
	return (inter);
}

int	intersection_mult_light(t_ray ray, t_obj *obj, t_bu *b_int)
{
	int		local_has_inter;
	int		has_inter;
	t_bu	b_loc;

	b_loc.j = -1;
	(*b_int).t_lt = 1E99;
	local_has_inter = 0;
	has_inter = 0;
	b_loc.t = 0;
	while (++(b_loc.j) < g_nb_obj)
	{
		local_has_inter = inter_tl(ray, obj[b_loc.j], &b_loc, (*b_int).shadow);
		if (local_has_inter == 1)
		{
			has_inter = 1;
			if (b_loc.t < (*b_int).t_lt)
			{
				(*b_int).t_lt = b_loc.t;
				(*b_int).point_light = b_loc.point;
				(*b_int).normal_light = b_loc.normal;
				(*b_int).obj_id_light = b_loc.j;
			}
		}
	}
	return (has_inter);
}
