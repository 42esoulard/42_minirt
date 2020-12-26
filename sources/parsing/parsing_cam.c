/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:05:15 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/16 12:12:42 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing_cam.h"

int		check_orientation_range(t_vector vector, int count)
{
	if (vector.x < -1 || vector.x > 1 ||
		vector.y < -1 || vector.y > 1 ||
		vector.z < -1 || vector.z > 1)
		error_msg(9, count);
	return (0);
}

int		add_fov(char *line, int *i, int count)
{
	char	nb[4];
	int		j;

	*i = pass_spaces(line, *i, count);
	if (check_int(line, *i, ' ') != 0)
		return (error_msg(3, count));
	j = 0;
	while (line[*i] && ft_isdigit(line[*i]) != 0)
	{
		if (j > 2)
			return (error_msg(3, count));
		nb[j++] = line[(*i)++];
	}
	nb[j] = '\0';
	*i = pass_spaces(line, *i, count);
	if (line[*i])
		error_msg(3, count);
	return (ft_atoi(nb));
}

void	parse_cam(char *line, int count, int g_cam_nb)
{
	int i;

	i = 1;
	g_cam_tab[g_cam_nb].o = entor_vector(line, &i, count);
	g_target_tab[g_cam_nb] = entor_vector(line, &i, count);
	check_orientation_range(g_target_tab[g_cam_nb], count);
	g_fov_tab[g_cam_nb] = add_fov(line, &i, count) * M_PI / 180;
}
