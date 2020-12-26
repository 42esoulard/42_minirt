/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:20:26 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/19 19:22:41 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

typedef struct	s_data
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;

}				t_data;

typedef struct	s_vector
{
	double x;
	double y;
	double z;
}				t_vector;

typedef struct	s_color
{
	double b;
	double g;
	double r;
	double a;
}				t_color;

typedef struct	s_ray
{
	t_vector o;
	t_vector d;
}				t_ray;

typedef struct	s_obj
{
	char		type;
	char		subtype;
	t_vector	o;
	t_vector	obase;
	t_vector	dbase;
	t_vector	d;
	double		r;
	t_color		albedo;
	int			mirror;
	int			transparent;
	double		height;
	double		heightbase;
	double		diam;
	double		diambase;
	t_vector	sq_corner0;
	t_vector	sq_corner1;
	t_vector	sq_corner2;
	t_vector	sq_corner3;
	t_vector	t_corner0;
	t_vector	t_corner1;
	t_vector	t_corner2;
	t_vector	center;
	void		*sq;
	void		*tri1;
	void		*tri2;
	void		*tri3;
	void		*tri4;
}				t_obj;

typedef struct	s_light
{
	t_vector	pos;
	double		intensity;
	t_color		color;
}				t_light;

typedef struct	s_bundle
{
	int			j;
	t_obj		*scene;
	t_ray		ray;
	t_color		px_int;
	t_color		color;
	t_vector	point;
	t_vector	normal;
	t_vector	noise;
	int			obj_id;
	double		t;
	t_ray		ray_mirror;
	t_vector	point_light;
	t_vector	normal_light;
	int			obj_id_light;
	double		d_light2;
	double		t_lt;
	t_ray		shadow;

}				t_bu;

t_obj	*g_scene;
int		g_h;
int		g_w;

void	*g_cx;
void	*g_win1;
void	*g_image;
t_data	*g_data;
t_color	*g_data_db;

int			g_nb_obj;
int			g_obj_expl;

t_ray		g_ray;
t_ray		*g_cam_tab;
int			g_cam_nb;
int			g_cam_explorer;
t_vector	g_target;
t_vector	*g_target_tab;
double		g_fov;
double		*g_fov_tab;

int			g_light_nb;
int			g_light_explorer;
t_light		*g_light;
t_light		g_ambiant_light;

int			g_key;
int			g_hook;

#endif
