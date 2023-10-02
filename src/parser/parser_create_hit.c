/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:04:00 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/02 14:09:59 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_object	create_plane(char *define_line, int *map)
{
	char		**split;
	t_object	obj;

	split = ft_split(define_line, ' ');
	if (!split)
		return (map[OBJ_ERROR]++, (t_object){});
	if (!(ft_veclen(split) == 4 || ft_veclen(split) == 5))
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	obj.obj.plane.origin = fill_vec(split[1], map, -INFINITY, INFINITY);
	obj.obj.plane.normal = fill_vec(split[2], map, -1, 1);
	obj.mat.color = fill_vec(split[3], map, 0, 255);
	obj.mat.type = METAL;
	if (ft_veclen(split) == 5)
		obj.mat.type = fill_material(split[4], map);
	obj.hit_func = &hit_plane;
	return (map[OBJ_SPHERE]++, ft_vecfree(split), obj);
}

t_object	create_sphere(char *define_line, int *map)
{
	char		**split;
	t_object	obj;

	split = ft_split(define_line, ' ');
	if (!split)
		return (map[OBJ_ERROR]++, (t_object){});
	if (!(ft_veclen(split) == 4 || ft_veclen(split) == 5))
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	obj.obj.sphere.center = fill_vec(split[1], map, -INFINITY, INFINITY);
	obj.obj.sphere.radius = fill_double(split[2], map, 0, INFINITY);
	obj.mat.color = fill_vec(split[3], map, 0, 255);
	obj.mat.type = METAL;
	if (ft_veclen(split) == 5)
		obj.mat.type = fill_material(split[4], map);
	obj.hit_func = &hit_sphere;
	return (map[OBJ_SPHERE]++, ft_vecfree(split), obj);
}

t_object	create_cylinder(char *define_line, int *map)
{
	char		**split;
	t_object	obj;

	split = ft_split(define_line, ' ');
	if (!split)
		return (map[OBJ_ERROR]++, (t_object){});
	if (!(ft_veclen(split) == 6 || ft_veclen(split) == 7))
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	obj.obj.cylinder.center = fill_vec(split[1], map, -INFINITY, INFINITY);
	obj.obj.cylinder.axis = fill_vec(split[2], map, -1, 1);
	obj.obj.cylinder.radius = fill_double(split[3], map, 0, INFINITY);
	obj.obj.cylinder.height = fill_double(split[4], map, 0, INFINITY);
	obj.mat.color = fill_vec(split[5], map, 0, 255);
	obj.mat.type = METAL;
	if (ft_veclen(split) == 7)
		obj.mat.type = fill_material(split[6], map);
	obj.hit_func = &hit_cylinder;
	return (map[OBJ_CYLINDER]++, ft_vecfree(split), obj);
}

t_object	create_error(int *map)
{
	map[OBJ_ERROR]++;
	printf("Type not found\n");
	return ((t_object){});
}
