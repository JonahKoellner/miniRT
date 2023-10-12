/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:18 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/12 17:41:25 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	mlx_color(t_vec3 color)
{
	int	r;
	int	g;
	int	b;

	r = fmin(fmax(sqrt(color.x), 0.0), 1.0) * 255;
	g = fmin(fmax(sqrt(color.y), 0.0), 1.0) * 255;
	b = fmin(fmax(sqrt(color.z), 0.0), 1.0) * 255;
	return (r << 24 | g << 16 | b << 8 | 255);
}

t_vec3	ray_color(t_ray r, int deph, t_window *window)
{
	t_vec3		color;
	t_hit		hit;
	t_vec3		ambient;
	int			i;

	i = 0;
	ambient = vmultd(window->ambient.color, window->ambient.brightness);
	hit = hit_object(window->objects, r, (t_interval){0.001, INFINITY});
	hit.mat = materials(hit.mat);
	if (deph <= 0)
		return ((t_vec3){0, 0, 0});
	if (hit.t > 0)
	{
		color = vmultv(ray_color(scatter(hit, r), deph - 1, window),
				hit.mat.color);
		color = vaddv(color, vmultd(ambient, hit.mat.ambient));
		while (i < window->num_lights)
		{
			color = vaddv(color, light_color(hit, window, i));
			i++;
		}
		return (color);
	}
	color = (t_vec3){BACK_COL_R, BACK_COL_G, BACK_COL_B};
	return (color);
}

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
