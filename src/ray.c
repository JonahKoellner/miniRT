/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:12:13 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/12 12:14:31 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_vec3 p_at(t_vec3 direction, t_vec3 origin, double t)
{
	return (vec3_add_vec3(origin, vec3_mult_double(direction, t)));
}
