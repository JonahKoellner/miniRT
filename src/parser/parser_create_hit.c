/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:04:00 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/01 17:10:50 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_object	create_plane(char *define_line, int *map)
{
	(void)(define_line);
	map[OBJ_PLANE]++;
	printf("plane\n");
	return ((t_object){});
}

t_object	create_sphere(char *define_line, int *map)
{
	char		**split;
	t_vec3		*vec;
	t_object	obj;

	split = ft_split(define_line, ' ');
	if (!split)
		return (map[OBJ_ERROR]++, (t_object){});
	vec = ft_calloc(1, sizeof(t_vec3));
	if (!vec)
		return (ft_vecfree(split), map[OBJ_ERROR]++, (t_object){});
	if (ft_atov(split[1], vec))
		return (free(vec), ft_vecfree(split), map[OBJ_ERROR]++, (t_object){});
	obj.obj.sphere.center = *vec;
	obj.obj.sphere.radius = ft_atof(split[2]);
	if (obj.obj.sphere.radius < 0)
		return (ft_vecfree(split), free(vec), map[OBJ_ERROR]++, (t_object){});
	if (ft_atov(split[3], vec))
		return (ft_vecfree(split), free(vec), map[OBJ_ERROR]++, (t_object){});
	if ((vec->x > 255 || vec->x < 0) || (vec->y > 255 || vec->y < 0)
		|| (vec->z > 255 || vec->z < 0))
		return (ft_vecfree(split), free(vec), map[OBJ_ERROR]++, (t_object){});
	obj.mat.color = *vec;
	obj.mat.type = METAL;
	obj.hit_func = &hit_sphere;
	return (map[OBJ_SPHERE]++, ft_vecfree(split), free(vec), obj);
}

t_object	create_cylinder(char *define_line, int *map)
{
	(void)(define_line);
	map[OBJ_CYLINDER]++;
	printf("cylinder\n");
	return ((t_object){});
}

t_object	create_error(int *map)
{
	map[OBJ_ERROR]++;
	printf("error\n");
	return ((t_object){});
}
