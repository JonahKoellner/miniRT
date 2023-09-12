/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_vec3_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:17:05 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/12 09:42:30 by jkollner         ###   ########.fr       */
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
