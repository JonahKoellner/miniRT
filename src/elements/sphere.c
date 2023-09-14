/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:51:48 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/14 01:07:32 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_hit	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vec3_sub_vec3(ray.origin, sphere.center);
	a = vec3_length_squared(ray.direction);
	half_b = dot(oc, ray.direction);
	c = vec3_length_squared(oc) - sphere.radius * sphere.radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-half_b - sqrt(discriminant)) / a);
}

t_vec3	sphere_normal(t_sphere sphere, t_vec3 point)
{
	t_vec3	normal;

	normal = vec3_div_double(vec3_sub_vec3(point, sphere.center),
			sphere.radius);
	return (normal);
}
