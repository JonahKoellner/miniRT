/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:18 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/18 14:27:02 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	mlx_color(int r, int g, int b, int o)
{
	return (r << 24 | g << 16 | b << 8 | o);
}

uint32_t	ray_color(t_ray r)
{
	t_vec3	unit_direction;
	double	a;
	t_vec3	color;
	t_hit	hit;
	t_vec3	n;

	hit = hit_sphere((t_sphere){{0, 0, -1}, 0.5}, r, (t_interval){0, INFINITY});
	if (hit.t > 0.0)
	{
		n = vec3_sub_vec3(hit.point, (t_vec3){0, 0, -1});
		n = vec3_div_double(n, vec3_length(n));
		return (mlx_color((n.x + 1) * 0.5 * 255, (n.y + 1) * 0.5 * 255, (n.z + 1) * 0.5 * 255, 255));
	}
	unit_direction = unit_vec(r.direction);
	a = 0.5 * (unit_direction.y + 1);
	color = vec3_add_vec3(vec3_mult_double((t_vec3){1, 1, 1}, 1.0 - a),
			vec3_mult_double((t_vec3){0.5, 0.7, 1.0}, a));
	return (mlx_color(color.x * 255, color.y * 255, color.z * 255, 255));
}
