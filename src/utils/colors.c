/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:18 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/19 13:32:34 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	mlx_color(t_vec3 color)
{
	int	r;
	int	g;
	int	b;

	r = sqrt(color.x) * 255;
	g = sqrt(color.y) * 255;
	b = sqrt(color.z) * 255;

	// r = color.x * 255;
	// g = color.y * 255;
	// b = color.z * 255;
	return (r << 24 | g << 16 | b << 8 | 255);
}

t_vec3	ray_color(t_ray r, int deph, t_object *objects)
{
	t_vec3		unit_direction;
	double		a;
	t_vec3		color;
	t_hit		hit;

	hit = hit_object(objects, r, (t_interval){.001, INFINITY});
	if (deph <= 0)
		return ((t_vec3){0, 0, 0});
	if (hit.t > 0)
		return (vec3_mult_vec3(ray_color(scatter(hit, r), deph - 1, objects),
				hit.mat.color));
	//normal vector shading
	// if (hit.t > 0.0)
	// 	return (vec3_mult_double(hit.normal, 0.5));
	unit_direction = unit_vec(r.direction);
	a = 0.5 * (unit_direction.y + 1);
	color = vec3_add_vec3(vec3_mult_double((t_vec3){1, 1, 1}, 1.0 - a),
			vec3_mult_double((t_vec3){0.5, 0.7, 1.0}, a));
	return (color);
}
