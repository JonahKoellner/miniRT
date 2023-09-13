/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:14:32 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/12 09:54:43 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

#include <math.h>

typedef struct s_vec3{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vec3_add_vec3(t_vec3 first, t_vec3 second);
t_vec3	vec3_mult_double(t_vec3 first, double second);
t_vec3	vec3_div_double(t_vec3 first, double second);
double	vec3_length(t_vec3 vec);
double	vec3_length_sqaured(t_vec3 vec);
t_vec3	cross(t_vec3 u, t_vec3 v);
double	dot(t_vec3 u, t_vec3 v);
t_vec3	unit_vec(t_vec3 v);

#endif