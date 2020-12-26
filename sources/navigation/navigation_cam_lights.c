/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation_cam_lights.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:11:47 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/23 13:57:47 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/navigation_cam_lights.h"

void	nav_amb_light(int keycode)
{
	if (keycode == 69)
		g_ambiant_light.intensity += 0.025;
	else if (keycode == 78)
		g_ambiant_light.intensity -= 0.025;
	else if (keycode == 15)
		g_ambiant_light.color = init_color(0, 0, 255);
	else if (keycode == 5)
		g_ambiant_light.color = init_color(0, 255, 0);
	else if (keycode == 11)
		g_ambiant_light.color = init_color(255, 0, 0);
	else if (keycode == 1)
		g_ambiant_light.color = init_color(20, 66, 112);
	else if (keycode == 13)
		g_ambiant_light.color = init_color(255, 255, 255);
}

int		change_light(int g_key, int keycode)
{
	if (g_key == 18 && keycode == 18)
	{
		if (g_light_explorer > 0)
			g_light_explorer--;
		else
			g_light_explorer = g_light_nb - 1;
		ft_printf("\033[1;33m Controlling light n%d\n", g_light_explorer);
	}
	else if (g_key == 19 && keycode == 19)
	{
		if (g_light_explorer < g_light_nb - 1)
			g_light_explorer++;
		else
			g_light_explorer = 0;
		ft_printf("\033[1;33m Controlling light n%d\n", g_light_explorer);
	}
	return (g_light_explorer);
}

void	nav_light(int keycode, int g_key)
{
	int i;

	i = change_light(g_key, keycode);
	if (keycode == 13)
		g_light[i].pos.y += 5;
	else if (keycode == 1)
		g_light[i].pos.y -= 5;
	else if (keycode == 0)
		g_light[i].pos.x -= 5;
	else if (keycode == 2)
		g_light[i].pos.x += 5;
	else if (keycode == 69)
		g_light[i].pos.z -= 5;
	else if (keycode == 78)
		g_light[i].pos.z += 5;
	else if (keycode == 37)
		g_light[i].intensity += 10;
	else if (keycode == 38)
		g_light[i].intensity -= 10;
}

int		rotate_cam(int keycode, t_vector *rotation)
{
	if (keycode == 123)
		(*rotation).y += 0.05;
	else if (keycode == 124)
		(*rotation).y -= 0.05;
	else if (keycode == 125)
		(*rotation).x -= 0.05;
	else if (keycode == 126)
		(*rotation).x += 0.05;
	if (keycode > 122 && keycode < 127)
		return (1);
	return (0);
}

void	cam_mov(int keycode, int *rot, int *trans)
{
	if (g_key == 8 && keycode == 8)
	{
		if (g_cam_explorer > 0)
			g_cam_explorer--;
		else
			g_cam_explorer = g_cam_nb - 1;
		ft_printf("\033[1;35m Controlling cam n%d\n", g_cam_explorer);
	}
	else if (g_key == 9 && keycode == 9)
	{
		if (g_cam_explorer < g_cam_nb - 1)
			g_cam_explorer++;
		else
			g_cam_explorer = 0;
		ft_printf("\033[1;35m Controlling cam n%d\n", g_cam_explorer);
	}
	if (keycode > 122 && keycode < 127)
		*rot = rotate_cam(keycode, &g_target_tab[g_cam_explorer]);
	else
		*trans = trans_obj(keycode, &g_cam_tab[g_cam_explorer].o);
	g_ray.o = g_cam_tab[g_cam_explorer].o;
	g_target = g_target_tab[g_cam_explorer];
	g_fov = g_fov_tab[g_cam_explorer];
}
