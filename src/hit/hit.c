/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:23:35 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/26 15:02:22 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_hit	hit_object(t_obj_list *objects, t_ray ray, t_interval interval)
{
	int		i;
	t_hit	hit;
	t_hit	temp_hit;

	i = -1;
	hit.t = i;
	//while (objects[++i].mat.type != STOP)
	while (objects->next_obj)
	{
		temp_hit = objects->obj.hit_func(objects->obj.obj, ray, interval);
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
			hit.mat = objects->obj.mat;
		}
		objects = objects->next_obj;
	}
	return (hit);
}
