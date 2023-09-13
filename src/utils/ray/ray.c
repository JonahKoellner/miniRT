/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:12:13 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/13 21:15:11 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../miniRT.h"

t_vec3 p_at(t_vec3 direction, t_vec3 origin, double t)
{
	return (vec3_add_vec3(origin, vec3_mult_double(direction, t)));
}
