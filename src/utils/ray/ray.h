/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:10:48 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/20 23:13:17 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_ray{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

t_vec3	p_at(t_vec3 direction, t_vec3 origin, double t);
double	distance_to_ray(t_vec3 point, t_ray ray);

#endif
