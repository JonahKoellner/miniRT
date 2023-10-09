/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:18 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/02 15:19:01 by mreidenb         ###   ########.fr       */
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
	t_vec3		ambient = (t_vec3){0.0, 0.0, 0.0};
	int			i;

	i = 0;
	hit = hit_object(window->objects, r, (t_interval){0.001, INFINITY});
	if (deph <= 0)
		return ((t_vec3){0, 0, 0});
	if (hit.t > 0)
	{
		color = vec3_mult_vec3(ray_color(scatter(hit, r), deph - 1, window),
				hit.mat.color);
		// color = vec3_mult_double(color, 0.5);
		color = vec3_add_vec3(color, ambient);
		while (i < window->num_lights)
		{
			color = vec3_add_vec3(color, light_color(hit, window, i));
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
	light_distance = vec3_length(light_ray.direction);
	light_ray.direction = unit_vec(light_ray.direction);
	shadow_hit = hit_object(window->objects, light_ray,
			(t_interval){0.001, INFINITY});
	if (shadow_hit.t > 0)
	{
		if (shadow_hit.t < light_distance)
			shadow = 0.0;
	}
	return (shadow);
}

t_vec3	light_color(t_hit hit, t_window *window, int i)
{
	t_ray		light_ray;
	double		shadow;
	t_vec3		light_color;

	light_ray = (t_ray){hit.point,
		vec3_sub_vec3(window->lights[i].origin, hit.point)};
	shadow = shadow_ray(light_ray, window);
	if (shadow > 0)
	{
		light_color = vec3_mult_vec3(window->lights[i].color,
				hit.mat.color);
		light_color = vec3_mult_double(light_color, shadow);
		light_color = vec3_mult_double(light_color, window->lights[i].brightness);
		// printf("light_color: %f %f %f\n", light_color.x, light_color.y, light_color.z);
		return (light_color);
	}
	return ((t_vec3){0, 0, 0});
}
