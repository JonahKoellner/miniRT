/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:42:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/12 09:54:04 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	vec3_length(t_vec3 vec)
{
	return (sqrt(vec3_length_sqaured(vec)));
}

double	vec3_length_sqaured(t_vec3 vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}
