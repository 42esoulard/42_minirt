/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:47:15 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/24 15:35:42 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/variables.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	free_all(void)
{
	free(g_data_db);
	free(g_scene);
	free(g_light);
	free(g_cam_tab);
	free(g_target_tab);
	free(g_fov_tab);
	ft_printf("\033[1;36m					  LATER GATOR!\n");
	exit(0);
}

int		exit_hook(void *param)
{
	(void)param;
	free_all();
	exit(0);
}
