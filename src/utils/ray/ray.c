/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:12:13 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/10 16:58:34 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3 p_at(t_vec3 direction, t_vec3 origin, double t)
{
	return (vaddv(origin, vmultd(direction, t)));
}

double	distance_to_ray(t_vec3 point, t_ray ray)
{
	t_vec3	v;
	double	t;
	t_vec3	closest_point;

	v = vsubv(point, ray.origin);
	t = dot(v, ray.direction);
	closest_point = vaddv(ray.origin,
			vmultd(ray.direction, t));
	return (vlen(vsubv(point, closest_point)));
}
