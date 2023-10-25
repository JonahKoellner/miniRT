/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:05:31 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/25 09:53:36 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_mat4	mat4_rotation_x(double angle)
{
	t_mat4	mat;
	double	c;
	double	s;

	mat = mat4_identity();
	c = cosf(angle);
	s = sinf(angle);
	mat.m[1][1] = c;
	mat.m[1][2] = s;
	mat.m[2][1] = -s;
	mat.m[2][2] = c;
	return (mat);
}

t_mat4	mat4_rotation_y(double angle)
{
	t_mat4	mat;
	double	c;
	double	s;

	mat = mat4_identity();
	c = cosf(angle);
	s = sinf(angle);
	mat.m[0][0] = c;
	mat.m[0][2] = -s;
	mat.m[2][0] = s;
	mat.m[2][2] = c;
	return (mat);
}

t_mat4	mat4_rotation_z(double angle)
{
	t_mat4	mat;
	double	c;
	double	s;

	mat = mat4_identity();
	c = cosf(angle);
	s = sinf(angle);
	mat.m[0][0] = c;
	mat.m[0][1] = s;
	mat.m[1][0] = -s;
	mat.m[1][1] = c;
	return (mat);
}
