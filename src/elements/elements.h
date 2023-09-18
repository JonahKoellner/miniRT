/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:51:55 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/18 14:37:26 by jkollner         ###   ########.fr       */
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

#endif