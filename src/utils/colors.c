/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:18 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/26 18:02:51 by mreidenb         ###   ########.fr       */
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
	t_vec3		ambient = (t_vec3){0.5, 0.5, 0.5};

	hit = hit_object(window->objects, r, (t_interval){0.001, INFINITY});
	if (deph <= 0)
		return ((t_vec3){0, 0, 0});
	if (hit.t > 0)
	{
		color = vec3_mult_vec3(ray_color(scatter(hit, r), deph - 1, window),
				hit.mat.color);
		color = vec3_add_vec3(color, ambient);
		return (color);
	}
	color = (t_vec3){BACK_COL_R, BACK_COL_G, BACK_COL_B};
	return (color);
}
