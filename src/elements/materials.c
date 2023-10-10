/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:58:10 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/10 19:28:08 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	lambaterian_scatter(t_hit hit, t_ray ret)
{
	t_vec3	scattered_direction;

	if (hit.mat.type == PLASTIC)
		scattered_direction = vaddv(hit.normal, rand_on_hemi(hit.normal));
	else
	{
		scattered_direction = vaddv(hit.normal, random_unitv());
		if (near_zero(scattered_direction))
			scattered_direction = hit.normal;
	}
	// 	scattered_direction = vaddv(hit.normal, random_unitv());
	// if (near_zero(scattered_direction))
	// 	scattered_direction = hit.normal;
	ret.origin = hit.point;
	ret.direction = scattered_direction;
	return (ret);
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	t_vec3	ret;

	ret = vsubv(v, (vmultd(n, (2 * dot(v, n)))));
	return (ret);
}

t_ray	metal_scatter(t_hit hit, t_ray ray)
{
	t_vec3	reflected;
	double	fuzz;

	fuzz = 1 - (hit.mat.shininess / 1000.0);
	reflected = reflect(unitv(ray.direction), hit.normal);
	ray.origin = hit.point;
	ray.direction = vaddv(reflected, vmultd(random_unitv(), fuzz));
	return (ray);
}

t_material	materials(t_material material)
{
	const t_material	metal = {METAL, .color = material.color,
		.ambient = 0.05, .diffuse = 0.7, .specular = 0.7, .shininess = 1000};
	const t_material	lambertian = {LAMBERTIAN, .color = material.color,
		.ambient = 0.1, .diffuse = 0.7, .specular = 0.2, .shininess = 10.0};
	const t_material	plastic = {PLASTIC, .color = material.color,
		.ambient = 0.1, .diffuse = 0.5, .specular = 0.8, .shininess = 50};

	if (material.type == METAL)
		return (metal);
	else if (material.type == LAMBERTIAN)
		return (lambertian);
	else if (material.type == PLASTIC)
		return (plastic);
	return (material);
	// const t_material matteRed = {MATTE, {1.0, 0.0, 0.0}, 0.1, 0.7, 0.2, 10.0};
	// const t_material plasticBlue = {PLASTIC, {0.0, 0.0, 1.0}, 0.1, 0.5, 0.8, 50.0};
	// const t_material shinyMetal = {METAL, {0.8, 0.8, 0.8}, 0.05, 0.7, 0.9, 200.0};
	// const t_material mirror = {MIRROR, {1.0, 1.0, 1.0}, 0.05, 0.0, 1.0, 1000.0};
	// const t_material glass = {GLASS, {0.0, 0.0, 0.0}, 0.05, 0.0, 0.0, 100.0};
}

t_ray	scatter(t_hit hit, t_ray ray)
{
	t_ray	ret;

	ret = ray;
	if (hit.mat.type == LAMBERTIAN)
		ret = lambaterian_scatter(hit, ray);
	else if (hit.mat.type == METAL)
		ret = metal_scatter(hit, ray);
	else if (hit.mat.type == PLASTIC)
		ret = lambaterian_scatter(hit, ray);
	// else if (hit.material.type == DIELECTRIC)
	// 	ret = dielectric_scatter(hit, ray, material);
	return (ret);
}
