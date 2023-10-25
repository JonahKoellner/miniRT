/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:18 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/25 00:37:21 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief Converts from 0-1 to 0-255 and puts it into an int for mlx.
/// @param color The color to convert.
/// @return The color in int representation.
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

/// @brief Gets the color of a ray.
/// @param r The ray to get the color from.
/// @param deph The amount of refelcted rays.
/// @param window The window.
/// @return The color of the ray.
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
