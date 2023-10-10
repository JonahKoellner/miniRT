/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:43:25 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/10 19:11:20 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	random_unitv(void)
{
	t_vec3	ret;
	double	length_squared;

	length_squared = 0.0;
	while (!(length_squared >= 1.0))
	{
		ret = random_unitv3();
		length_squared = vlen_squared(ret);
	}
	return (ret);
}

t_vec3	rand_on_hemi(t_vec3 normal)
{
	t_vec3	in_unit_sphere;
	t_vec3	ret;

	in_unit_sphere = random_unitv();
	if (dot(in_unit_sphere, normal) > 0.0)
		ret = in_unit_sphere;
	else
		ret = vmultd(in_unit_sphere, -1);
	return (ret);
}

bool	near_zero(t_vec3 vec)
{
	const double	s = 1e-8;

	return ((fabs(vec.x) < s) && (fabs(vec.y) < s) && (fabs(vec.z) < s));
}
