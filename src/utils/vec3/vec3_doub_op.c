/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_doub_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:41:28 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/10 16:55:38 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vmultd(t_vec3 first, double second)
{
	t_vec3	ret;

	ret.x = first.x * second;
	ret.y = first.y * second;
	ret.z = first.z * second;
	return (ret);
}

t_vec3	vdivd(t_vec3 first, double second)
{
	t_vec3	ret;

	if (second == 0.0)
		return ((t_vec3){0, 0, 0});
	ret.x = first.x * (1 / second);
	ret.y = first.y * (1 / second);
	ret.z = first.z * (1 / second);
	return (ret);
}
