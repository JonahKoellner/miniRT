/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:06:29 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/10 16:58:34 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_hit	hit_plane(t_hittable hit_obj, t_ray ray, t_interval interval)
{
	t_hit	hit;
	double	denom;
	double	root;

	hit.t = -1.0;
	denom = dot(hit_obj.plane.normal, ray.direction);
	if (fabs(denom) > 0.0001)
	{
		root = dot(vsubv(hit_obj.plane.origin, ray.origin),
				hit_obj.plane.normal) / denom;
		if (root < interval.min || interval.max < root)
			return (hit);
		hit.t = root;
		hit.point = p_at(ray.direction, ray.origin, hit.t);
		hit.normal = hit_obj.plane.normal;
	}
	return (hit);
}