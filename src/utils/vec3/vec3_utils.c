/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:42:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/18 21:54:51 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	vec3_length(t_vec3 vec)
{
	return (sqrt(vec3_length_squared(vec)));
}

double	vec3_length_squared(t_vec3 vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

double	random_double(double min, double max)
{
	return (min + (max - min) * drand48());
}


t_vec3	random_unit_vec3(void)
{
	return ((t_vec3)
		{
			random_double(-1, 1),
			random_double(-1, 1),
			random_double(-1, 1)
		});
}
