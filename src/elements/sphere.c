/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:51:48 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/12 17:36:43 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	sphere_root(t_sphere sphere, t_ray ray)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vsubv(ray.origin, sphere.center);
	a = vlen_squared(ray.direction);
	half_b = dot(oc, ray.direction);
	c = vlen_squared(oc) - sphere.radius * sphere.radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-half_b - sqrt(discriminant)) / a);
}

static t_vec3	sphere_normal(t_sphere sphere, t_vec3 point)
{
	t_vec3	normal;

	normal = vdivd(vsubv(point, sphere.center),
			sphere.radius);
	normal = unitv(normal);
	return (normal);
}

t_hit	hit_sphere(t_hittable hit_obj, t_ray ray, t_interval interval)
{
	t_hit		hit;
	double		root;
	t_sphere	sphere;

	sphere = hit_obj.sphere;
	hit.t = -1.0;
	root = sphere_root(sphere, ray);
	if (root < interval.min || interval.max < root)
		return (hit);
	hit.t = root;
	hit.point = p_at(ray.direction, ray.origin, hit.t);
	hit.normal = sphere_normal(sphere, hit.point);
	return (hit);
}
