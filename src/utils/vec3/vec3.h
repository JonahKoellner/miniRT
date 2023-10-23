/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:14:32 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/23 17:21:02 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vsubv(t_vec3 first, t_vec3 second);
t_vec3	vsubd(t_vec3 first, double second);
t_vec3	vaddv(t_vec3 first, t_vec3 second);
t_vec3	vmultv(t_vec3 first, t_vec3 second);
t_vec3	vdivv(t_vec3 first, t_vec3 second);
t_vec3	vmultd(t_vec3 first, double second);
t_vec3	vdivd(t_vec3 first, double second);
double	vlen(t_vec3 vec);
double	vlen_squared(t_vec3 vec);
t_vec3	cross(t_vec3 u, t_vec3 v);
double	dot(t_vec3 u, t_vec3 v);
t_vec3	unitv(t_vec3 v);
double	random_double(double min, double max);
t_vec3	random_unitv3(void);
t_vec3	rand_on_hemi(t_vec3 normal);
t_vec3	random_unitv(void);
bool	near_zero(t_vec3 vec);
t_vec3	negate(t_vec3 v);

#endif
