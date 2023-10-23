/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:00 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/23 14:42:14 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	cone_normal(t_cone cone, t_vec3 point)
{
	t_vec3	normal;
	t_vec3	oc;

	oc = vsubv(point, cone.c);
	normal = vsubv(oc, vmultd(cone.v, dot(oc, cone.v)));
	return (normal);
}

double	cone_root(t_cone cone, t_ray ray)
{
	float	a;
	float	b;
	float	c;
	float	det;
	t_vec3	co;

	co = vsubv(ray.origin, cone.c);
	a = dot(ray.direction, cone.v) * dot(ray.direction, cone.v) - cone.cosa * cone.cosa;
	b = 2 * (dot(ray.direction, cone.v) * dot(co, cone.v) - dot(ray.direction, co) * cone.cosa * cone.cosa);
	c = dot(co, cone.v) * dot(co, cone.v) - dot(co, co) * cone.cosa * cone.cosa;
	det = b * b - 4 * a * c;
	if (det < 0)
		return (-1);
	det = sqrt(det);
	return ((-b - det) / (2 * a));
}

t_hit	hit_cone(t_hittable hit_obj, t_ray ray, t_interval interval)
{
	t_cone	cone;
	double	root;
	t_hit	hit;

	cone = hit_obj.cone;

	hit.t = -1.0;
	root = cone_root(cone, ray);
	if (root < interval.min || interval.max < root)
		return (hit);
	hit.t = root;
	hit.point = p_at(ray.direction, ray.origin, hit.t);
	hit.normal = cone_normal(cone, hit.point);
	root = dot(vsubv(hit.point, cone.c), cone.v);
	if (root < 0 || root > cone.h)
		hit.t = -1.0;
	else
		hit.normal = cone_normal(cone, hit.point);
	return (hit);
}
