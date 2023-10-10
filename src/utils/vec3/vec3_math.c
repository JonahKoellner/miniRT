/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:45:41 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/10 16:58:34 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.z * v.z + u.y * v.y);
}

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	t_vec3 ret;

	ret.x = u.y * v.z - u.z * v.y;
	ret.y = u.z * v.x - u.x * v.z;
	ret.z = u.x * v.y - u.y * v.x;
	return (ret);
}

t_vec3	unitv(t_vec3 v)
{
	return (vdivd(v, vlen(v)));
}

t_vec3	random_in_unit_sphere(void)
{
	t_vec3	p;

	while (1)
	{
		p = vsubv(vmultd(random_unitv3(), 2),
				(t_vec3){1, 1, 1});
		if (vlen_squared(p) >= 1)
			continue ;
		return (p);
	}
}
