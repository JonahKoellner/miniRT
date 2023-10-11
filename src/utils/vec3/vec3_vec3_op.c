/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_vec3_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:17:05 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/11 23:21:25 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vaddv(t_vec3 first, t_vec3 second)
{
	t_vec3 ret;

	ret.x = first.x + second.x;
	ret.y = first.y + second.y;
	ret.z = first.z + second.z;
	return (ret);
}

t_vec3	vsubv(t_vec3 first, t_vec3 second)
{
	t_vec3 ret;

	ret.x = first.x - second.x;
	ret.y = first.y - second.y;
	ret.z = first.z - second.z;
	return (ret);
}

t_vec3	vmultv(t_vec3 first, t_vec3 second)
{
	t_vec3 ret;

	ret.x = first.x * second.x;
	ret.y = first.y * second.y;
	ret.z = first.z * second.z;
	return (ret);
}

t_vec3	vdivv(t_vec3 first, t_vec3 second)
{
	t_vec3 ret;

	ret.x = first.x / second.x;
	ret.y = first.y / second.y;
	ret.z = first.z / second.z;
	return (ret);
}
