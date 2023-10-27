/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:04:00 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/27 16:07:29 by jkollner         ###   ########.fr       */
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
	if (!(ft_veclen(split) >= 4 && ft_veclen(split) <= 5))
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	obj.obj.plane.origin = fill_vec(split[1], map, -INFINITY, INFINITY);
	obj.obj.plane.normal = fill_vec(split[2], map, -1, 1);
	obj.mat.color = fill_vec(split[3], map, 0, 255);
	obj.mat.bump_color = fill_bumpmap(NULL, NULL);
	obj.mat.type = METAL;
	if (ft_veclen(split) == 5)
		obj.mat.type = fill_material(split[4], map);
	obj.hit_func = &hit_plane;
	return (map[OBJ_PLANE]++, ft_vecfree(split), obj);
}

t_object	create_sphere(char *define_line, int *map)
{
	char		**split;
	t_object	obj;

	split = ft_split(define_line, ' ');
	if (!split)
		return (map[OBJ_ERROR]++, (t_object){});
	if (!(ft_veclen(split) >= 4 && ft_veclen(split) <= 7))
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	obj.obj.sphere.center = fill_vec(split[1], map, -INFINITY, INFINITY);
	obj.obj.sphere.radius = fill_double(split[2], map, 0, INFINITY);
	obj.mat.color = (t_vec3){0};
	obj.mat.bump_color = fill_bumpmap(NULL, NULL);
	obj.mat.type = METAL;
	if (!num_color(split[3]))
		obj.mat.color = fill_vec(split[3], map, 0, 255);
	if (ft_veclen(split) == 5)
		obj.mat.type = fill_material(split[4], map);
	if (ft_veclen(split) == 7)
		obj.mat.bump_color = fill_bumpmap(split[5], split[6]);
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
	if (!(ft_veclen(split) >= 6 && ft_veclen(split) <= 7))
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	obj.obj.cylinder.center = fill_vec(split[1], map, -INFINITY, INFINITY);
	obj.obj.cylinder.axis = fill_vec(split[2], map, -1, 1);
	obj.obj.cylinder.radius = fill_double(split[3], map, 0, INFINITY);
	obj.obj.cylinder.height = fill_double(split[4], map, 0, INFINITY);
	obj.mat.color = fill_vec(split[5], map, 0, 255);
	obj.mat.bump_color = fill_bumpmap(NULL, NULL);
	obj.mat.type = METAL;
	if (ft_veclen(split) == 7)
		obj.mat.type = fill_material(split[6], map);
	obj.hit_func = &hit_cylinder;
	return (map[OBJ_CYLINDER]++, ft_vecfree(split), obj);
}

t_object	create_cone(char *define_line, int *map)
{
	char		**split;
	t_object	obj;

	split = ft_split(define_line, ' ');
	if (!split)
		return (map[OBJ_ERROR]++, (t_object){});
	if (!(ft_veclen(split) >= 5 && ft_veclen(split) <= 8))
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	obj.obj.cone.cosa = cos(fill_double(split[1], map, 0, INFINITY));
	obj.obj.cone.h = fill_double(split[2], map, 0, INFINITY);
	obj.obj.cone.c = fill_vec(split[3], map, -INFINITY, INFINITY);
	obj.obj.cone.v = fill_vec(split[4], map, 0, 91);
	obj.mat.bump_color = fill_bumpmap(NULL, NULL);
	obj.mat.color = (t_vec3){0};
	obj.mat.color = fill_vec(split[5], map, 0, 255);
	if (ft_veclen(split) != 6 && ft_veclen(split) != 7)
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	obj.mat.type = METAL;
	if (ft_veclen(split) == 7)
		obj.mat.type = fill_material(split[6], map);
	obj.hit_func = &hit_cone;
	return (map[OBJ_CONE]++, ft_vecfree(split), obj);
}

t_object	create_error(int *map)
{
	map[OBJ_ERROR]++;
	printf("Type not found\n");
	return ((t_object){});
}
