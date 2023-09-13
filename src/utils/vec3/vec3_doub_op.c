/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_doub_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:41:28 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/13 18:13:04 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_mult_double(t_vec3 first, double second)
{
	t_vec3 ret;

	ret.x = first.x * second;
	ret.y = first.y * second;
	ret.z = first.z * second;
	return (ret);
}

t_vec3	vec3_div_double(t_vec3 first, double second)
{
	t_vec3 ret;

	if (second == 0.0)
		return ((t_vec3){0, 0, 0});
	ret.x = first.x * (1 / second);
	ret.y = first.y * (1 / second);
	ret.z = first.z * (1 / second);
	return (ret);
}
