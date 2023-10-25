/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:37:03 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/25 12:04:10 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	shadow_ray(t_ray light_ray, t_window *window)
{
	double	shadow;
	t_hit	shadow_hit;
	double	light_distance;

	shadow = 1.0;
	light_distance = vlen(light_ray.direction);
	light_ray.direction = unitv(light_ray.direction);
	shadow_hit = hit_object(window->objects, light_ray,
			(t_interval){0.001, INFINITY});
	if (shadow_hit.t > 0)
	{
		if (shadow_hit.t < light_distance)
			shadow = 0.0;
	}
	return (shadow);
}

t_vec3	add_phong(t_hit hit, t_vec3 light_color, t_vec3 color, t_ray ray)
{
	t_vec3	diffuse;
	t_vec3	specular;

	diffuse = vmultd(color, fmax(0, dot(unitv(ray.direction), hit.normal)));
	specular = vmultd(light_color, hit.mat.specular);
	specular = vmultd(specular, pow(fmax(0,
					dot(unitv(ray.direction), hit.normal)), hit.mat.shininess));
	color = vaddv(diffuse, vaddv(specular, color));
	return (color);
}

t_vec3	light_color(t_hit hit, t_window *window, int i)
{
	t_ray		light_ray;
	double		shadow;
	t_vec3		light_color;

	light_ray = (t_ray){hit.point,
		vsubv(window->lights[i].origin, hit.point)};
	shadow = shadow_ray(light_ray, window);
	if (shadow > 0)
	{
		light_color = vmultv(window->lights[i].color,
				hit.mat.color);
		light_color = add_phong(hit, window->lights[i].color,
				light_color, light_ray);
		light_color = vmultd(light_color, shadow);
		light_color = vmultd(light_color, window->lights[i].brightness);
		return (light_color);
	}
	return ((t_vec3){0, 0, 0});
}
