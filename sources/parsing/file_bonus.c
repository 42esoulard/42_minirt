/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:28:33 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/24 16:03:57 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"

int		parse_it2(char *line, int count)
{
	if (line[0] == 'c' && line[1] != 'y' && line[1] != 'u')
		parse_cam(line, count, ++g_cam_nb);
	else if (line[0] == 'l')
		parse_light(line, count);
	else if (line[0] == 's' && line[1] == 'p')
		parse_sphere(line, count);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_plane(line, count);
	else if (line[0] == 's' && line[1] == 'q')
		parse_square(line, count);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cy(line, count);
	else if (line[0] == 't' && line[1] == 'r')
		parse_tr(line, count);
	else if (line[0] == 'c' && line[1] == 'u')
		parse_cube(line, count);
	else if ((line[0] == 'p' && line[1] == 'y'))
		parse_pyramid(line, count);
	else
	{
		free(line);
		error_msg(3, count);
	}
	return (0);
}

int		parse_it(char *line, int count, int *valid)
{
	if (is_empty(line) == 0)
	{
		free(line);
		return (0);
	}
	else if (line[0] == 'R')
	{
		parse_win_size(line, count);
		(*valid)++;
	}
	else if (line[0] == 'A')
	{
		parse_amb_light(line, count);
		(*valid)++;
	}
	else
		parse_it2(line, count);
	free(line);
	return (0);
}

void	count_elems(char *line, int *checkr, int *checka)
{
	if (line[0] == 'c' && line[1] != 'y' && line[1] != 'u')
		g_cam_nb++;
	if ((line[0] == 's' && line[1] == 'p') || (line[0] == 'p' &&
		line[1] == 'l') || (line[0] == 's' && line[1] == 'q') ||
		(line[0] == 'c' && line[1] == 'y') || (line[0] == 't' &&
		line[1] == 'r'))
		g_nb_obj++;
	else if ((line[0] == 'c' && line[1] == 'u'))
		g_nb_obj += 6;
	else if ((line[0] == 'p' && line[1] == 'y'))
		g_nb_obj += 5;
	else if (line[0] == 'l')
		g_light_nb++;
	else if (line[0] == 'R')
		(*checkr)++;
	else if (line[0] == 'A')
		(*checka)++;
	free(line);
}

void	make_scene(char *file, int fd)
{
	int		k;
	char	*line;
	int		checkr;
	int		checka;

	checkr = 0;
	checka = 0;
	if ((fd = open(file, O_RDONLY)) < 0 || (read(fd, 0, 0)) < 0)
		error_msg(10, 0);
	init_globals(0);
	while ((k = get_next_line(fd, &line)) > 0)
		count_elems(line, &checkr, &checka);
	count_elems(line, &checkr, &checka);
	close(fd);
	if (!(g_scene = malloc(sizeof(t_obj) * (g_nb_obj + 1))))
		free_all();
	if (!(g_light = malloc(sizeof(t_light) * (g_light_nb + 1))))
		free_all();
	if (!(g_cam_tab = malloc(sizeof(t_ray) * (g_cam_nb + 1))) ||
		!(g_target_tab = malloc(sizeof(t_vector) * (g_cam_nb + 1))) ||
		!(g_fov_tab = malloc(sizeof(double) * (g_cam_nb + 1))))
		free_all();
	if (checkr != 1 || checka != 1)
		error_msg(1, 1);
	init_globals(-1);
}

int		read_rt(int ac, char **av, int fd, int count)
{
	char	*file;
	char	*line;
	int		valid;

	valid = 0;
	if (ac < 2 || (ac == 3 && (ft_strncmp(av[2], "-save",
		ft_strlen(av[2])) != 0 || ft_strncmp(av[2], "-save",
		6) != 0)) || ac > 3)
		return (error_msg(0, count));
	file = av[1];
	while (file[valid])
		valid++;
	if (file[--valid] != 't' || file[--valid] != 'r' || file[--valid] != '.')
		return (error_msg(0, count));
	valid = 0;
	make_scene(file, fd);
	if ((fd = open(file, O_RDONLY)) < 0 || (read(fd, 0, 0)) < 0)
		return (error_msg(0, count));
	while (get_next_line(fd, &line) > 0)
		parse_it(line, ++count, &valid);
	parse_it(line, ++count, &valid);
	close(fd);
	if (valid < 2)
		error_msg(1, count);
	return (0);
}
