/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:03:56 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/21 00:33:06 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//cylinder_root with t_cylinder cylinder and t_ray ray calculates the root of the quadratic equation and returns it or -1.0 if there is no root or psoitive double if ray intersects with caps of the cylinder
static double	cylinder_root(t_cylinder cylinder, t_ray ray)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vec3_sub_vec3(ray.origin, cylinder.center);
	a = vec3_length_squared(ray.direction) - pow(dot(ray.direction, cylinder.axis), 2);
	half_b = dot(oc, ray.direction) - dot(oc, cylinder.axis) * dot(ray.direction, cylinder.axis);
	c = vec3_length_squared(oc) - pow(dot(oc, cylinder.axis), 2) - cylinder.radius * cylinder.radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0 || discriminant > cylinder.height)
		return (-1.0);
	else
		return ((-half_b - sqrt(discriminant)) / a);
}
// cylinder_normal with t_cylinder cylinder and t_vec3 point returns the normal vector of the cylinder/caps at the point
static t_vec3	cylinder_normal(t_cylinder cylinder, t_vec3 point)
{
	t_vec3	oc;
	t_vec3	normal;

	oc = vec3_sub_vec3(point, cylinder.center);
	normal = vec3_sub_vec3(oc, vec3_mult_double(cylinder.axis, dot(oc, cylinder.axis)));
	return (normal);
}

// t_vec3	cylinder_normal(t_cylinder cylinder, t_vec3 point)
// {
// 	t_vec3	normal;
// 	t_vec3	bottom_center;
// 	t_vec3	top_center;
// 	double	distance_to_bottom;
// 	double	distance_to_top;

// 	bottom_center = cylinder.center;
// 	top_center = vec3_add_vec3(cylinder.center, vec3_mult_double(cylinder.axis, cylinder.height));
// 	distance_to_bottom = vec3_length(vec3_sub_vec3(point, bottom_center));
// 	distance_to_top = vec3_length(vec3_sub_vec3(point, top_center));
// 	if (distance_to_bottom < cylinder.radius)
// 		normal = unit_vec(vec3_sub_vec3(point, bottom_center));
// 	else if (distance_to_top < cylinder.radius)
// 		normal = unit_vec(vec3_sub_vec3(point, top_center));
// 	else
// 	{
// 		t_vec3	projected_point;
// 		t_vec3	axis_to_point;
// 		double	distance_along_axis;

// 		axis_to_point = vec3_sub_vec3(point, cylinder.center);
// 		distance_along_axis = dot(axis_to_point, cylinder.axis);
// 		projected_point = vec3_add_vec3(cylinder.center, vec3_mult_double(cylinder.axis, distance_along_axis));
// 		normal = unit_vec(vec3_sub_vec3(point, projected_point));
// 	}
// 	return (normal);
// }

// t_hit	hit_caps(t_cylinder cylinder, t_ray ray, t_interval interval)
// {
// 	t_hit	hit;
// 	double	root;
// 	t_vec3	top_center;
// 	t_vec3	bot_center;

// 	hit.t = -1.0;
// 	top_center = vec3_add_vec3(cylinder.center, vec3_mult_double(cylinder.axis, cylinder.height / 2));
// 	bot_center = vec3_sub_vec3(cylinder.center, vec3_mult_double(cylinder.axis, cylinder.height / 2));
// 	root = dot(vec3_sub_vec3(cylinder.center, ray.origin), cylinder.axis) / dot(ray.direction, cylinder.axis);
// 	if (distance_to_ray(bot_center, ray) >= cylinder.radius ^
// 		distance_to_ray(top_center, ray) >= cylinder.radius)
// 		hit.t = -1.0;
// 	else
// 	{
// 		if (distance_to_ray(bot_center, ray) <= cylinder.radius)
// 			hit = hit_plane((t_hittable){.plane = {bot_center, cylinder.axis}}, ray, interval);
// 		else if (distance_to_ray(top_center, ray) <= cylinder.radius)
// 			hit = hit_plane((t_hittable){.plane = {top_center, cylinder.axis}}, ray, interval);
// 	}
// 	return (hit);
// }

t_hit	hit_cylinder(t_hittable hit_obj, t_ray ray, t_interval interval)
{
	t_hit		hit;
	// t_hit		hit_tmp;
	double		root;
	t_cylinder	cylinder;

	cylinder = hit_obj.cylinder;
	cylinder.axis = unit_vec(cylinder.axis);
	// hit_tmp = hit_caps(cylinder, ray, interval);
	hit.t = -1.0;
	root = cylinder_root(cylinder, ray);
	if (root < interval.min || interval.max < root)
		return (hit);
	hit.t = root;
	hit.point = p_at(ray.direction, ray.origin, hit.t);
	hit.normal = cylinder_normal(cylinder, hit.point);
	// Check if the intersection point is within the height range of the cylinder
	root = dot(vec3_sub_vec3(hit.point, cylinder.center), cylinder.axis);
	if (root < 0 || root > cylinder.height)
		hit.t = -1.0;
	else
		hit.normal = cylinder_normal(cylinder, hit.point);
	// if (hit_tmp.t > hit.t && hit_tmp.t > 0.0)
	// 	return (hit_tmp);
	return (hit);
}

// t_hit	hit_cylinder(t_hittable hit_obj, t_ray ray, t_interval interval)
// {
// 	t_hit		hit;
// 	double		root;
// 	t_cylinder	cylinder;

// 	cylinder = hit_obj.cylinder;
// 	hit.t = -1.0;
// 	root = cylinder_root(cylinder, ray);
// 	hit.t = root;
// 	hit.point = p_at(ray.direction, ray.origin, hit.t);
// 	hit.normal = cylinder_normal(cylinder, hit.point);
// 	// Check if the intersection point is within the height range of the cylinder
// 	root = dot(vec3_sub_vec3(hit.point, cylinder.center), cylinder.axis);
// 	if (root < 0 || root > cylinder.height)
// 		hit.t = -1.0;
// 	else if (dot(vec3_sub_vec3(hit.point, cylinder.center), cylinder.axis) >= 0 && dot(vec3_sub_vec3(hit.point, cylinder.center), cylinder.axis) <= cylinder.height)
// 	{
// 		if (vec3_length(vec3_sub_vec3(hit.point, cylinder.center)) <= cylinder.radius)
// 			hit = hit_plane((t_hittable){.plane = {cylinder.center, cylinder.axis}}, ray, interval);
// 		else if (vec3_length(vec3_sub_vec3(hit.point, vec3_add_vec3(cylinder.center, vec3_mult_double(cylinder.axis, cylinder.height)))) <= cylinder.radius)
// 			hit = hit_plane((t_hittable){.plane = {vec3_add_vec3(cylinder.center, vec3_mult_double(cylinder.axis, cylinder.height)), cylinder.axis}}, ray, interval);
// 	}
// 	return (hit);
// }