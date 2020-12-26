/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snippet2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:20:04 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/23 12:25:52 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/snippet2.h"

t_bu	snippet_fill_b_routine(t_obj *scene, int k)
{
	t_bu bundle;

	bundle.scene = scene;
	bundle.j = k;
	bundle.ray = g_ray;
	return (bundle);
}

int		snippet_init_mlx(void)
{
	int bits;

	bits = 0;
	g_image = mlx_new_image(g_cx, g_h / 2, g_w / 2);
	g_data = (t_data *)mlx_get_data_addr(g_image, &bits, &bits, &bits);
	return (0);
}

int		snippet_minirt(void)
{
	t_bu		b_routine[1];

	snippet_init_mlx();
	b_routine[0] = snippet_fill_b_routine(g_scene, 0);
	snippet_routine(&b_routine[0]);
	g_data = snippet_convert_db_to_uchar(g_data, g_data_db);
	mlx_put_image_to_window(g_cx, g_win1, g_image, 0, 0);
	mlx_key_hook(g_win1, (*key_hook), NULL);
	mlx_loop(g_cx);
	return (0);
}
