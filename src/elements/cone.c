/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:00 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/23 18:15:51 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//t_vec3	cone_normal(t_cone cone, t_vec3 point)
//{
//	t_vec3	normal;
//	t_vec3	co;

//	oc = vsubv(point, cone.c);
//	normal = vsubv(oc, vmultd(cone.v, dot(oc, cone.v)));
//	return (normal);
//}

//double	cone_root(t_cone cone, t_ray ray)
//{
//	float	a;
//	float	b;
//	float	c;
//	float	det;
//	t_vec3	co;

//	co = vsubv(ray.origin, cone.c);
//	a = dot(ray.direction, cone.v) * dot(ray.direction, cone.v) - cone.cosa * cone.cosa;
//	b = 2 * (dot(ray.direction, cone.v) * dot(co, cone.v) - dot(ray.direction, co) * cone.cosa * cone.cosa);
//	c = dot(co, cone.v) * dot(co, cone.v) - dot(co, co) * cone.cosa * cone.cosa;
//	det = b * b - 4 * a * c;
//	if (det < 0)
//		return (-1);
//	det = sqrt(det);
//	return ((-b - det) / (2 * a));
//}

//t_hit	hit_cone(t_hittable hit_obj, t_ray ray, t_interval interval)
//{
//	t_cone	cone;
//	double	root;
//	t_hit	hit;

//	cone = hit_obj.cone;

//	hit.t = -1.0;
//	root = cone_root(cone, ray);
//	if (root < interval.min || interval.max < root)
//		return (hit);
//	hit.t = root;
//	hit.point = p_at(ray.direction, ray.origin, hit.t);
//	hit.normal = cone_normal(cone, hit.point);
//	root = dot(vsubv(hit.point, cone.c), cone.v);
//	if (root < 0 || root > cone.h)
//		hit.t = -1.0;
//	else
//		hit.normal = cone_normal(cone, hit.point);
//	return (hit);
//}


t_hit hit_cone(t_hittable hit_obj, t_ray ray, t_interval interval)
{
	//given center c angle x height h
	//a = ray.direction * (cone.c * h)sqaure - cos(x)square
	//b = 2 * ((cone.c * cone.unit)* (co * cone.unit) - ray.direction * co * cos(cosa)square))
	//c = (co * cone.unit)square - co * co * cos(cosa)square

	//    t_hit hit;
    //hit.t = -1.0;
	//t_cone cone;


	//t_vec3 cone_unit = unitv(cone.v);

	//double cosa = cos(cone.angle);
	//t_vec3 co = vsubv(ray.origin, cone.c);
	//a = dot(vsubd(vmultv(ray.direction, vmultv(vmultd(cone.c, cone.h), vmultd(cone.c, cone.h))), (cosa * cosa)));
	//b = dot(vmultd((vsubv(vmultv(vmultv(cone.c, cone_unit), vmultv(co, cone_unit)), vmultv(ray.direction, vmultd(co, (cosa * cosa))))), 2));
	//c = dot(vsubv(vmultv(vmultv(co, cone_unit), vmultv(co, cone_unit)), vmultv(co, vmultd(co * (cosa * cosa)))));



    t_cone cone;
    t_hit hit;
	cone = hit_obj.cone;

    // Calculate the quadratic coefficients
    hit.t = -1.0;
    t_vec3 co = vsubv(ray.origin, cone.c);
    double a = dot(ray.direction, ray.direction) - (1 + cone.cosa * cone.cosa) * dot(ray.direction, cone.v) * dot(ray.direction, cone.v);
    double b = 2 * (dot(ray.direction, co) - (1 + cone.cosa * cone.cosa) * dot(ray.direction, cone.v) * dot(co, cone.v));
    double c = dot(co, co) - (1 + cone.cosa * cone.cosa) * dot(co, cone.v) * dot(co, cone.v);

    // Check if the ray hits the cone
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return hit;
    }

    // Calculate the hit point and normal
    double t = (-b - sqrt(discriminant)) / (2 * a);
    if (t < interval.min || t > interval.max) {
        return hit;
    }
    hit.t = t;
    hit.point = p_at(ray.direction, ray.origin, hit.t);
    hit.normal = unitv(vsubv(hit.point, vaddv(cone.c, vmultd(cone.v, dot(vsubv(hit.point, cone.c), cone.v) / dot(cone.v, cone.v) + cone.h))));
    return hit;
}
