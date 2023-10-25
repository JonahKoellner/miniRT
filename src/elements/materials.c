/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:58:10 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/24 22:31:40 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief Calculates the scattered ray for a given hit point and incoming
/// ray using the lambertian scattering model.
/// @param hit The hit point information.
/// @param ret The incoming ray.
/// @return The scattered ray.
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

/// @brief Calculates the scattered ray when a metal material is hit by a ray.
/// @param hit The hit point information.
/// @param ray The incident ray.
/// @return The scattered ray.
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

/// @brief Sets the material properties for a given material.
/// @param material The material to set the properties for.
/// @return The material with the properties set.
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
}
// const t_material matteRed = {MATTE, {1.0, 0.0, 0.0}, 0.1, 0.7, 0.2, 10.0};
// const t_material plastBlue = {PLASTIC, {0.0, 0.0, 1.0}, 0.1, 0.5, 0.8, 50.0};
// const t_material shinyMetl = {METAL, {0.8, 0.8, 0.8}, 0.05, 0.7, 0.9, 200.0};
// const t_material mirror = {MIRROR, {1.0, 1.0, 1.0}, 0.05, 0.0, 1.0, 1000.0};
// const t_material glass = {GLASS, {0.0, 0.0, 0.0}, 0.05, 0.0, 0.0, 100.0};

/// @brief Selcts the correct scatter function for the material type.
/// @param hit The hit point information.
/// @param ray The incident ray.
/// @return The scattered ray.
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
	return (ret);
}
