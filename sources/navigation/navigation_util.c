/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 10:37:39 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/23 13:58:40 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

int	find_obj_nb2(t_obj *scene, int keycode)
{
	if (scene[g_obj_expl].type == 'q' && scene[g_obj_expl].subtype ==
		'c' && g_key == 83 && keycode == 83)
	{
		while (scene[g_obj_expl].subtype == 'c')
		{
			if (g_obj_expl-- < 0)
			{
				g_obj_expl = g_nb_obj - 1;
				find_obj_nb(scene, keycode);
			}
		}
	}
	else if (scene[g_obj_expl].type == 'q' && scene[g_obj_expl].subtype
		== 'c' && g_key == 84 && keycode == 84)
	{
		while (scene[g_obj_expl].subtype == 'c')
		{
			if (g_obj_expl++ >= g_nb_obj - 1)
			{
				g_obj_expl = 0;
				find_obj_nb(scene, keycode);
			}
		}
	}
	return (g_obj_expl);
}

int	find_obj_nb(t_obj *s, int keycode)
{
	if (s[g_obj_expl].type == 't' && s[g_obj_expl].subtype ==
		'p' && g_key == 83 && keycode == 83)
	{
		while (s[g_obj_expl].subtype == 'p' && s[g_obj_expl].type != 'q')
		{
			if (g_obj_expl-- < 0)
			{
				g_obj_expl = g_nb_obj - 1;
				find_obj_nb(s, keycode);
			}
		}
	}
	else if (s[g_obj_expl].type == 't' && s[g_obj_expl].subtype
		== 'p' && g_key == 84 && keycode == 84)
	{
		while (s[g_obj_expl].subtype == 'p' && s[g_obj_expl].type != 'q')
		{
			if (g_obj_expl++ >= g_nb_obj - 1)
			{
				g_obj_expl = 0;
				find_obj_nb(s, keycode);
			}
		}
	}
	return (find_obj_nb2(s, keycode));
}

int	change_object(int g_key, int keycode)
{
	if (g_key == 83 && keycode == 83)
	{
		if (g_obj_expl > 0)
			g_obj_expl--;
		else
			g_obj_expl = g_nb_obj - 1;
		find_obj_nb(g_scene, keycode);
		ft_printf("\033[1;34m Controlling obj n%d type %c\n", g_obj_expl,
		g_scene[g_obj_expl].type);
	}
	else if (g_key == 84 && keycode == 84)
	{
		if (g_obj_expl < g_nb_obj - 1)
			g_obj_expl++;
		else
			g_obj_expl = 0;
		find_obj_nb(g_scene, keycode);
		ft_printf("\033[1;34m Controlling obj n%d type %c\n", g_obj_expl,
		g_scene[g_obj_expl].type);
	}
	return (g_obj_expl);
}

int	key_hook2(int keycode, int i, int trans)
{
	int rot;

	if (g_key == 46)
		nav_amb_light(keycode);
	else if (g_key == 18 || g_key == 19)
		nav_light(keycode, g_key);
	else if (g_key == 8 || g_key == 9)
		cam_mov(keycode, &rot, &trans);
	else if (g_key == 83 || g_key == 84)
	{
		i = change_object(g_key, keycode);
		trans = trans_obj(keycode, &g_scene[i].o);
		if (g_scene[i].type != 'p' && g_scene[i].type != 'y')
			rot = rot_obj(keycode, &g_scene[i].d, &g_scene[i].diam,
				&g_scene[i].height);
		else
			rot = rot_obj_plcy(keycode, &g_scene[i].d, &g_scene[i].diam,
				&g_scene[i].height);
		check_obj(g_scene, i, trans, rot);
	}
	else
		init_hook(0, 0);
	mlx_destroy_image(g_cx, g_image);
	snippet_minirt();
	return (0);
}

int	key_hook(int keycode, void *param)
{
	int i;
	int trans;

	i = 0;
	trans = 0;
	if (g_hook == 0)
		init_hook(1, keycode);
	(void)param;
	if (keycode == 119)
		init_hook(0, 0);
	if (keycode == 36)
	{
		mlx_destroy_image(g_cx, g_image);
		minirt(1, 0, -1);
	}
	if (keycode == 53)
	{
		mlx_destroy_image(g_cx, g_image);
		mlx_destroy_window(g_cx, g_win1);
		free_all();
	}
	else
		key_hook2(keycode, i, trans);
	return (0);
}
