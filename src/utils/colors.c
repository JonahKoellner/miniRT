/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:18 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/18 14:04:25 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	mlx_color(int r, int g, int b, int o)
{
	return (r << 24 | g << 16 | b << 8 | o);
}

uint32_t	ray_color(t_ray r)
{
	t_vec3	unit_direction;
	double	a;
	t_vec3	color;

	unit_direction = unit_vec(r.direction);
	a = 0.5 * (unit_direction.y + 1);
	color = vec3_add_vec3(vec3_mult_double((t_vec3){1, 1, 1}, 1.0 - a),
			vec3_mult_double((t_vec3){0.5, 0.7, 1.0}, a));
	return (mlx_color(color.x * 255, color.y * 255, color.z * 255, 255));
}
