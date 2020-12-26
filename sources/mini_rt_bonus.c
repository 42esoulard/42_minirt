/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:36:32 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/24 15:19:58 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	loading_print(int j, int i)
{
	if (j == 6 && i == 0)
	{
		ft_printf("\n\n\033[1;33m					 HALFWAY THROUGH !\n");
		ft_printf("\n\033[1;31m					    LOADING...\n\n\n\n");
	}
	if (j == 6 && i == g_w / 2)
		ft_printf("\n\033[1;36m				       NEVER BEEN SO CLOSE...\n");
	if (j == 7 && i == 0)
		ft_printf("\n\n\033[1;35m					  ALMOST THERE...\n");
	if (j == 7 && i == g_w / 4 * 3)
		ft_printf("\n\033[1;32m					    I SWEAR...\n");
}

void	init_scene(void)
{
	g_light_nb++;
	g_nb_obj++;
	g_cam_nb++;
	g_ray.o = g_cam_tab[0].o;
	g_target = g_target_tab[0];
	g_fov = g_fov_tab[0];
	g_cam_explorer = -1;
	g_obj_expl = -1;
	g_light_explorer = -1;
	ft_printf("\n\n\033[1;32m					PARSING COMPLETE !\n");
	ft_printf("\n\n\n\033[1;36m					  LOADING SCENE...\n");
}

int		init_mlx(int redo)
{
	int bits;

	bits = 0;
	if (redo == 0)
	{
		if (!(g_data_db = malloc(sizeof(t_color) * (g_h * g_w))))
			return (-1);
		init_scene();
		if ((g_cx = mlx_init()) == NULL)
			return (-1);
		if ((g_win1 = mlx_new_window(g_cx, g_h, g_w, "I'M A WINDOW - RALPH"))
			== NULL)
			return (-1);
	}
	g_image = mlx_new_image(g_cx, g_h, g_w);
	g_data = (t_data *)mlx_get_data_addr(g_image, &bits, &bits, &bits);
	return (0);
}

int		minirt(int redo, int bmp, int k)
{
	t_bu		b_routine[8];
	pthread_t	thread_tab[8];

	if (init_mlx(redo) == -1)
		free_all();
	while (++k < 8)
	{
		thread_tab[k] = 0;
		b_routine[k] = fill_b_routine(g_scene, k);
		if (pthread_create(&thread_tab[k], NULL, routine, &b_routine[k]))
			return (-1);
	}
	k = -1;
	while (++k < 8)
		if (pthread_join(thread_tab[k], NULL))
			return (-1);
	g_data = convert_db_to_uchar(g_data, g_data_db);
	if (bmp == 1)
		save_bmp();
	mlx_put_image_to_window(g_cx, g_win1, g_image, 0, 0);
	ft_printf("\n\n\n\033[1;33m				 	   THERE YOU GO!\n\n\n");
	mlx_hook(g_win1, 17, 0, (*exit_hook), g_win1);
	mlx_key_hook(g_win1, (*key_hook), NULL);
	mlx_loop(g_cx);
	return (0);
}

int		main(int ac, char **av)
{
	int	fd;
	int	count;

	ft_printf("\033[1;35m					    LOADING...\n\n\n");
	fd = 0;
	count = 0;
	g_hook = 0;
	read_rt(ac, av, fd, count);
	if (ac == 3 && ft_strncmp(av[2], "-save", 5) == 0)
		minirt(0, 1, -1);
	else
		minirt(0, 0, -1);
	free_all();
	return (0);
}
