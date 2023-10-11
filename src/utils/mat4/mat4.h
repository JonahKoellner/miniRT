/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:01:24 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/12 00:41:29 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

typedef struct s_mat4
{
	double	m[4][4];
}	t_mat4;

t_mat4	mat4_identity(void);
t_mat4	mat4_rotation_y(double angle);
t_mat4	mat4_rotation_z(double angle);
t_mat4	mat4_rotation_x(double angle);
t_mat4	mat4_translation(t_vec3 v);
t_mat4	mat4_scaling(t_vec3 v);
t_mat4	mat4_multiply(t_mat4 a, t_mat4 b);
t_vec3	transform_point(t_vec3 point, t_mat4 transform);

#endif