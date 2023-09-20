/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:52:39 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/20 14:08:25 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# define DEPTH 50

# include "../utils/vec3/vec3.h"
# include "../elements/elements.h"

typedef enum MaterialType
{
	LAMBERTIAN,
	METAL,
	DIELECTRIC
}	t_MaterialType;

typedef struct s_material
{
	t_MaterialType	type;
	t_vec3			color;
	// double			reflectance;
}	t_material;

typedef struct s_hit
{
	bool		hit;
	bool		front_facing;
	t_vec3		point;
	t_vec3		normal;
	double		t;
	t_material	mat;
}	t_hit;

typedef struct s_interval
{
	double	min;
	double	max;
}	t_interval;

typedef union u_hittable
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_hittable;



typedef struct s_object{
	t_hittable	obj;
	t_hit		(*hit_func)(t_hittable obj, t_ray ray, t_interval interval);
	t_material	mat;
}	t_object;

t_hit	hit_object(t_object *objects, t_ray ray, t_interval interval);

t_hit	hit_sphere(t_hittable hit_obj, t_ray ray, t_interval interval);

t_ray	scatter(t_hit hit, t_ray ray);

#endif
