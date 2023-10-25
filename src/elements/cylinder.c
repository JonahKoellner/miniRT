/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:03:56 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/24 22:19:44 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

///@brief cylinder_root with t_cylinder cylinder and t_ray ray calculates
/// the root of the quadratic equation
///@return returns root or -1.0 if there is no intersection with the cylinder
static double	cylinder_root(t_cylinder cylinder, t_ray ray)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vsubv(ray.origin, cylinder.center);
	a = vlen_squared(ray.direction) - pow(dot(ray.direction, cylinder.axis), 2);
	half_b = dot(oc, ray.direction) - dot(oc, cylinder.axis)
		* dot(ray.direction, cylinder.axis);
	c = vlen_squared(oc) - pow(dot(oc, cylinder.axis), 2)
		- cylinder.radius * cylinder.radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0 || discriminant > cylinder.height)
		return (-1.0);
	else
		return ((-half_b - sqrt(discriminant)) / a);
}

///@brief calculates cylinder_normal of @a t_cylinder cylinder
///at @a t_vec3 point
///@return returns the normal vector of the cylinder/caps at the point
static t_vec3	cylinder_normal(t_cylinder cylinder, t_vec3 point)
{
	t_vec3	oc;
	t_vec3	normal;

	oc = vsubv(point, cylinder.center);
	normal = vsubv(oc, vmultd(cylinder.axis, dot(oc, cylinder.axis)));
	return (normal);
}

///@brief Computes the intersection between a ray and a cylinder.
///@param hit_obj The cylinder object to intersect with.
///@param ray The ray to intersect with the cylinder.
///@param interval The interval to check for intersection.
///@return The hit object containing information about the intersection.
t_hit	hit_cylinder(t_hittable hit_obj, t_ray ray, t_interval interval)
{
	t_hit		hit;
	double		root;
	t_cylinder	cylinder;

	cylinder = hit_obj.cylinder;
	cylinder.axis = unitv(cylinder.axis);
	hit.t = -1.0;
	root = cylinder_root(cylinder, ray);
	if (root < interval.min || interval.max < root)
		return (hit);
	hit.t = root;
	hit.point = p_at(ray.direction, ray.origin, hit.t);
	hit.normal = cylinder_normal(cylinder, hit.point);
	root = dot(vsubv(hit.point, cylinder.center), cylinder.axis);
	if (root < 0 || root > cylinder.height)
		hit.t = -1.0;
	else
		hit.normal = cylinder_normal(cylinder, hit.point);
	return (hit);
}
