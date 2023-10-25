/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:00 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/25 14:51:52 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	cone_coefficient(t_ray ray, t_cone cone)
{
	t_vec3	co;
	double	a;
	double	b;
	double	c;
	t_vec3	ret;

	co = vsubv(ray.origin, cone.c);
	a = dot(ray.direction, ray.direction) - (1 + cone.cosa * cone.cosa)
		* dot(ray.direction, cone.v) * dot(ray.direction, cone.v);
	b = 2 * (dot(ray.direction, co) - (1 + cone.cosa * cone.cosa)
			* dot(ray.direction, cone.v) * dot(co, cone.v));
	c = dot(co, co) - (1 + cone.cosa * cone.cosa) * dot(co, cone.v)
		* dot(co, cone.v);
	ret = (t_vec3){a, b, c};
	return (ret);
}

t_hit	hit_cone(t_hittable hit_obj, t_ray ray, t_interval interval)
{
	t_cone	c;
	t_hit	hit;
	t_vec3	coefficient;
	double	t;
	double	discriminant;

	c = hit_obj.cone;
	hit.t = -1.0;
	coefficient = cone_coefficient(ray, c);
	discriminant = coefficient.y * coefficient.y - 4 * coefficient.x
		* coefficient.z;
	if (discriminant < 0)
		return (hit);
	t = (-coefficient.y - sqrt(discriminant)) / (2 * coefficient.x);
	if (t < interval.min || t > interval.max)
		return (hit);
	hit.t = t;
	hit.point = p_at(ray.direction, ray.origin, hit.t);
	hit.normal = unitv(vsubv(hit.point, vaddv(c.c, vmultd(c.v,
						dot(vsubv(hit.point, c.c), c.v)
						/ dot(c.v, c.v) + c.h))));
	return (hit);
}
