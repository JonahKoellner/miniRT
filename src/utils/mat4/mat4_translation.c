/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_translation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:04:14 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/12 00:43:58 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_mat4	mat4_identity(void)
{
	t_mat4	mat;

	mat = (t_mat4){0};
	mat.m[0][0] = 1.0;
	mat.m[1][1] = 1.0;
	mat.m[2][2] = 1.0;
	mat.m[3][3] = 1.0;
	return (mat);
}

t_mat4	mat4_translation(t_vec3 translation)
{
	t_mat4	mat;

	mat = mat4_identity();
	mat.m[3][0] = translation.x;
	mat.m[3][1] = translation.y;
	mat.m[3][2] = translation.z;
	return (mat);
}

t_mat4	mat4_scaling(t_vec3 scale)
{
	t_mat4	mat;

	mat = mat4_identity();
	mat.m[0][0] = scale.x;
	mat.m[1][1] = scale.y;
	mat.m[2][2] = scale.z;
	return (mat);
}

t_mat4	mat4_multiply(t_mat4 a, t_mat4 b)
{
	t_mat4	result;
	int		i;
	int		j;

	result = (t_mat4){0};
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.m[i][j] = a.m[i][0] * b.m[0][j]
				+ a.m[i][1] * b.m[1][j]
				+ a.m[i][2] * b.m[2][j]
				+ a.m[i][3] * b.m[3][j];
			j++;
		}
		i++;
	}
	return (result);
}

t_vec3	transform_point(t_vec3 point, t_mat4 transform)
{
	t_vec3	ret;

	ret = (t_vec3){0};
	ret.x = point.x * transform.m[0][0]
		+ point.y * transform.m[1][0] + point.z
		* transform.m[2][0] + transform.m[3][0];
	ret.y = point.x * transform.m[0][1]
		+ point.y * transform.m[1][1] + point.z
		* transform.m[2][1] + transform.m[3][1];
	ret.z = point.x * transform.m[0][2]
		+ point.y * transform.m[1][2] + point.z
		* transform.m[2][2] + transform.m[3][2];
	return (ret);
}
