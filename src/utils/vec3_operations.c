/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:17:05 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/12 09:38:47 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_add_vec3(t_vec3 first, t_vec3 second)
{
	t_vec3 ret;

	ret.x = first.x + second.x;
	ret.y = first.y + second.y;
	ret.z = first.z + second.z;
	return (ret);
}

t_vec3	vec3_mult_double(t_vec3 first, double second)
{
	t_vec3 ret;

	ret.x = first.x + second;
	ret.y = first.y + second;
	ret.z = first.z + second;
	return (ret);
}

t_vec3	vec3_div_double(t_vec3 first, double second)
{
	t_vec3 ret;

	ret.x = first.x / second;
	ret.y = first.y / second;
	ret.z = first.z / second;
	return (ret);
}

double	vec3_length(t_vec3 vec)
{
	return (vec.x + vec.y + vec.z);
}

double	vec3_length_sqaured(t_vec3 vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}
