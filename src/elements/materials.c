/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:58:10 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/18 23:08:22 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vec3	random_unit_vec(void)
{
	t_vec3	ret;
	double	length_squared;

	length_squared = 0.0;
	while (!(length_squared >= 1.0))
	{
		ret = random_unit_vec3();
		length_squared = vec3_length_squared(ret);
	}
	return (ret);
}

t_vec3	random_on_hemisphere(t_vec3 normal)
{
	t_vec3	in_unit_sphere;
	t_vec3	ret;

	in_unit_sphere = random_unit_vec();
	if (dot(in_unit_sphere, normal) > 0.0)
		ret = in_unit_sphere;
	else
		ret = vec3_mult_double(in_unit_sphere, -1);
	return (ret);
}

bool	near_zero(t_vec3 vec)
{
	const double	s = 1e-8;

	return ((fabs(vec.x) < s) && (fabs(vec.y) < s) && (fabs(vec.z) < s));
}

t_ray	lambaterian_scatter(t_hit hit, t_ray ret)
{
	t_vec3	scattered_direction;

	scattered_direction = vec3_add_vec3(hit.normal, random_unit_vec());
	if (near_zero(scattered_direction))
		scattered_direction = hit.normal;
	ret.origin = hit.point;
	ret.direction = scattered_direction;
	return (ret);
}

t_ray	scatter(t_hit hit, t_ray ray)
{
	t_ray	ret;

	ret = ray;
	if (hit.mat.type == LAMBERTIAN)
		ret = lambaterian_scatter(hit, ray);
	// else if (hit.material.type == METAL)
	// 	ret = metal_scatter(hit, ray, material);
	// else if (hit.material.type == DIELECTRIC)
	// 	ret = dielectric_scatter(hit, ray, material);
	return (ret);
}
