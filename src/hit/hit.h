/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:52:39 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/14 03:40:43 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "../utils/vec3/vec3.h"
# include "../elements/elements.h"


typedef struct s_hit
{
	t_vec3	point;
	t_vec3	normal;
	double	t;
}	t_hit;

typedef struct s_interval
{
	double	min;
	double	max;
}	t_interval;

typedef union u_hittable
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_hittable;

t_hit	hit_sphere(t_sphere sphere, t_ray ray, t_interval interval);

#endif