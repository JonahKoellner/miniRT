/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:42:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/10 16:58:20 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	vlen(t_vec3 vec)
{
	return (sqrt(vlen_squared(vec)));
}

double	vlen_squared(t_vec3 vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

double	random_double(double min, double max)
{
	return (min + (max - min) * drand48());
}


t_vec3	random_unitv3(void)
{
	return ((t_vec3)
		{
			random_double(-1, 1),
			random_double(-1, 1),
			random_double(-1, 1)
		});
}
t_vec3	vec3_clamp(t_vec3 vec, double min, double max)
{
	return ((t_vec3)
		{
			fmin(fmax(vec.x, min), max),
			fmin(fmax(vec.y, min), max),
			fmin(fmax(vec.z, min), max)
		});
}
