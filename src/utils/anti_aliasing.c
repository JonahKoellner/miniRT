/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:59:22 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/18 17:07:01 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	get_ray(t_camera camera, double u, double v)
{
	t_vec3	pix_center;
	t_vec3	ray_direction;
	t_ray	ray;

	pix_center = vec3_add_vec3(camera.auf_lock, vec3_add_vec3
			(vec3_mult_double(camera.pix_delt_u, u),
				vec3_mult_double(camera.pix_delt_v, v)));
	ray_direction = vec3_sub_vec3(pix_center, camera.cam_center);
	ray = (t_ray){camera.cam_center, ray_direction};
	return (ray);
}

t_vec3	pixel_sample_square(t_window *window, int i, int j)
{
	t_vec3	pixel_color;
	t_ray	ray;
	int		samples;
	double	u;
	double	v;

	samples = 100;
	pixel_color = (t_vec3){0, 0, 0};
	for (int s = 0; s < samples; ++s)
	{
		u = -0.5 + drand48();
		v = -0.5 + drand48();
		ray = get_ray(window->camera, i + u, j + v);
		pixel_color = vec3_add_vec3(pixel_color, ray_color(ray));
	}
	pixel_color = vec3_div_double(pixel_color, samples);
	return (pixel_color);
}