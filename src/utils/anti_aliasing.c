/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:59:22 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/25 20:32:43 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define DEPTH 40
#define SAMPLES 40

/// @brief Gets the ray from the camera to the pixel.
/// @param camera The camera that casts the ray.
/// @param u The u coordinate of the pixel.
/// @param v The v coordinate of the pixel.
/// @return The ray from the camera to the pixel.
t_ray	get_ray(t_camera camera, double u, double v)
{
	t_vec3	pix_center;
	t_vec3	ray_direction;
	t_ray	ray;

	pix_center = vaddv(camera.auf_lock, vaddv
			(vmultd(camera.pix_delt_u, u),
				vmultd(camera.pix_delt_v, v)));
	ray_direction = vsubv(pix_center, camera.cam_center);
	ray = (t_ray){camera.cam_center, ray_direction};
	return (ray);
}

/// @brief Gets random pixel samples from a square around the pixel.
/// @param window The window to get the pixel samples from.
/// @param i The i coordinate of the pixel.
/// @param j The j coordinate of the pixel.
/// @return The color of the pixel sample.
t_vec3	pixel_sample_square(t_window *window, int i, int j)
{
	t_vec3	pixel_color;
	t_ray	ray;
	int		samples;
	double	u;
	double	v;

	samples = 0;
	pixel_color = (t_vec3){0, 0, 0};
	while (samples < SAMPLES)
	{
		u = -0.5 + drand48();
		v = -0.5 + drand48();
		ray = get_ray(window->camera, i + u, j + v);
		pixel_color = vaddv(pixel_color, ray_color(ray, DEPTH, window));
		samples++;
	}
	pixel_color = vdivd(pixel_color, samples);
	return (pixel_color);
}
