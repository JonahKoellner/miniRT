/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:23:35 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/20 21:59:42 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_hit	hit_object(t_object *objects, t_ray ray, t_interval interval)
{
	int		i;
	t_hit	hit;
	t_hit	temp_hit;

	i = -1;
	hit.t = i;
	while (objects[++i].mat.type != STOP)
	{
		temp_hit = objects[i].hit_func(objects[i].obj, ray, interval);
		if (temp_hit.t > 0.0 && (hit.t < 0.0 || temp_hit.t < hit.t))
		{
			hit = temp_hit;
			hit.hit = true;
			if (dot(ray.direction, hit.normal) < 0)
				hit.front_facing = true;
			else
			{
				hit.front_facing = false;
				hit.normal = vec3_mult_double(hit.normal, -1);
			}
			hit.mat = objects[i].mat;
		}
	}
	return (hit);
}
