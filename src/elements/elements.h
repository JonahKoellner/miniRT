/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:51:55 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/18 16:21:57 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

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
	t_vec3		normal;
	double		diameter;
	double		height;
}	t_cylinder;

// typedef struct s_camera
// {
// 	t_vec3		origin;
// 	t_vec3		direction;
// 	double		fov;
// }	t_camera;

typedef struct s_light
{
	t_vec3		origin;
	double		brightness;
}	t_light;

typedef struct s_camera{
	double	viewport_height;
	double	focal_length;
	double	viewport_width;
	t_vec3	cam_center;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	pix_delt_u;
	t_vec3	pix_delt_v;
	t_vec3	viewport_upr_left;
	t_vec3	auf_lock;
}	t_camera;

typedef struct s_window{
	mlx_t		*mlx_window;
	mlx_image_t	*mlx_image;
	double		aspect_ratio;
	t_camera	camera;
}	t_window;

#endif
