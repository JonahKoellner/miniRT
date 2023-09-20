/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:12:13 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/20 23:13:07 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3 p_at(t_vec3 direction, t_vec3 origin, double t)
{
	return (vec3_add_vec3(origin, vec3_mult_double(direction, t)));
}

double	distance_to_ray(t_vec3 point, t_ray ray)
{
	t_vec3	v;
	double	t;
	t_vec3	closest_point;

	v = vec3_sub_vec3(point, ray.origin);
	t = dot(v, ray.direction);
	closest_point = vec3_add_vec3(ray.origin,
			vec3_mult_double(ray.direction, t));
	return (vec3_length(vec3_sub_vec3(point, closest_point)));
}
