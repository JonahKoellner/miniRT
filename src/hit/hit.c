/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:23:35 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/24 22:36:31 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief Calculates the intersection between a ray and and any object
/// in the scene.
/// @param objects The list of objects in the scene.
/// @param ray The ray to intersect with the objects.
/// @param interval The interval to check for intersection.
/// @return The hit object containing information about the intersection.
t_hit	hit_object(t_obj_list *objects, t_ray ray, t_interval interval)
{
	int		i;
	t_hit	hit;
	t_hit	temp_hit;

	i = -1;
	hit.t = i;
	while (objects->next_obj)
	{
		temp_hit = objects->obj.hit_func(objects->obj.obj, ray, interval);
		if (temp_hit.t > 0.0 && (hit.t < 0.0 || temp_hit.t < hit.t))
		{
			hit = temp_hit;
			hit.hit = true;
			hit.front_facing = false;
			if (dot(ray.direction, hit.normal) < 0)
				hit.front_facing = true;
			else
				hit.normal = vmultd(hit.normal, -1);
			hit.mat = objects->obj.mat;
			hit.normal = get_normal(&objects->obj, hit.point, hit.normal);
			hit.mat.color = get_surface_color(&objects->obj, hit.point);
		}
		objects = objects->next_obj;
	}
	return (hit);
}
