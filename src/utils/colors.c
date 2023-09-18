/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:18 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/18 19:21:23 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	mlx_color(t_vec3 color)
{
	int	r;
	int	g;
	int	b;

	r = color.x * 255;
	g = color.y * 255;
	b = color.z * 255;
	return (r << 24 | g << 16 | b << 8 | 255);
}

t_vec3	ray_color(t_ray r)
{
	t_vec3	unit_direction;
	double	a;
	t_vec3	color;
	t_hit	hit;
	t_vec3	n;

	hit = hit_sphere((t_hittable){.sphere=(t_sphere){{0, 0, -1}, 0.5}}, r, (t_interval){0, INFINITY});
	if (hit.t > 0.0)
	{
		n = vec3_sub_vec3(hit.point, (t_vec3){0, 0, -1});
		n = vec3_div_double(n, vec3_length(n));
		return ((t_vec3){(n.x + 1) * 0.5, (n.y + 1) * 0.5, (n.z + 1) * 0.5});
	}
	unit_direction = unit_vec(r.direction);
	a = 0.5 * (unit_direction.y + 1);
	color = vec3_add_vec3(vec3_mult_double((t_vec3){1, 1, 1}, 1.0 - a),
			vec3_mult_double((t_vec3){0.5, 0.7, 1.0}, a));
	return (color);
}
