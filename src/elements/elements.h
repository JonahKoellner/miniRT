/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:51:55 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/20 10:47:20 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

// # include "../hit/hit.h"

typedef struct s_sphere
{
	t_vec3		center;
	double		radius;
}	t_sphere;

typedef struct s_plane
{
	t_vec3		origin;
	t_vec3		normal;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3		center;
	t_vec3		axis;
	double		radius;
	double		height;
}	t_cylinder;

typedef struct s_cone
{
	double	cosa;
	double	h;
	t_vec3	v;
	t_vec3	c;
}	t_cone;

typedef struct s_light
{
	t_vec3		origin;
	double		brightness;
	t_vec3		color;
}	t_light;

typedef struct s_ambient
{
	t_vec3		color;
	double		brightness;
}	t_ambient;

typedef struct s_camera{
	double	viewport_height;
	double	focal_length;
	double	viewport_width;
	double	fov;
	t_vec3	cam_center;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	pix_delt_u;
	t_vec3	pix_delt_v;
	t_vec3	viewport_upr_left;
	t_vec3	auf_lock;
}	t_camera;

#endif
