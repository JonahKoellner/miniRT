/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:10:48 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/13 10:29:54 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "utils/vec3/vec3.h"

typedef struct s_ray{
	t_vec3 origin;
	t_vec3 direction;
}	t_ray;

t_vec3 p_at(t_vec3 direction, t_vec3 origin, double t);

#endif
