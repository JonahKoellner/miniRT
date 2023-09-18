/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:14:32 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/18 21:55:36 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vec3_sub_vec3(t_vec3 first, t_vec3 second);
t_vec3	vec3_add_vec3(t_vec3 first, t_vec3 second);
t_vec3	vec3_mult_double(t_vec3 first, double second);
t_vec3	vec3_div_double(t_vec3 first, double second);
double	vec3_length(t_vec3 vec);
double	vec3_length_squared(t_vec3 vec);
t_vec3	cross(t_vec3 u, t_vec3 v);
double	dot(t_vec3 u, t_vec3 v);
t_vec3	unit_vec(t_vec3 v);
double	random_double(double min, double max);
t_vec3	random_unit_vec3(void);

#endif
