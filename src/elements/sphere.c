/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:51:48 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/13 21:19:04 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

bool	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vec3_sub_vec3(ray.origin, sphere.center);
	a = vec3_length_squared(ray.direction);
	half_b = vec3_dot(oc, ray.direction);
	c = vec3_length_squared(oc) - sphere.radius * sphere.radius;
	discriminant = half_b * half_b - a * c;
	return (discriminant > 0);
}
