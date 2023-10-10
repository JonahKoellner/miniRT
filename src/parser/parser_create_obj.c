/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:54:25 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/11 00:57:41 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_object	create_amb_light(char *define_line, int *map, t_window *window)
{
	char		**split;
	t_ambient	light;

	split = ft_split(define_line, ' ');
	if (!split)
		return (map[OBJ_ERROR]++, (t_object){});
	if (!(ft_veclen(split) == 3))
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	light.brightness = fill_double(split[1], map, 0, 1);
	light.color = fill_vec(split[2], map, 0, 255);
	printf("Error %d\n", map[OBJ_ERROR]);
	window->ambient = light;
	return (map[OBJ_AMBIENT_LIGHT]++, ft_vecfree(split), (t_object){});
}

t_object	create_camera(char *define_line, int *map, t_window *window)
{
	// char		**split;
	// t_vec3		*vec;

	// if (map[OBJ_CAMERA] > 0)
	// 	return (map[OBJ_ERROR]++, (t_object){});
	// split = ft_split(define_line, ' ');
	// if (!split)
	// 	return (map[OBJ_ERROR]++, (t_object){});
	// vec = ft_calloc(1, sizeof(t_vec3));
	// if (!vec)
	// 	return (map[OBJ_ERROR]++, (t_object){});
	// if (ft_atov(split[1], vec))
	// 	return (free(vec), ft_vecfree(split), map[OBJ_ERROR]++, (t_object){});
	// window->camera.cam_center = *vec;
	// if (ft_atov(split[2], vec))
	// 	return (free(vec), ft_vecfree(split), map[OBJ_ERROR]++, (t_object){});
	// if ((vec->x < -1 || vec->x > 1) || (vec->y < -1 || vec->y > 1)
	// 	|| (vec->z < -1 || vec->z > 1))
	// 		return (free(vec), ft_vecfree(split), map[OBJ_ERROR]++, (t_object){});
	// // window->camera. = *vec; //3d normalized oriental vector
	// // window->camera. = ft_atof(split[3]); // FOV
	// // if (window->camera. < 0 || window->camera. > 180)
	// // 	return (free(vec), ft_vecfree(split), map[OBJ_ERROR]++, (t_object){});
	// return (free(vec), ft_vecfree(split), map[OBJ_CAMERA]++, (t_object){});

	(void)define_line;
	(void)map;
	(void)window;
	return ((t_object){}); // for compiling now

}


// t_camera *create_camera(t_vec3 pos, t_vec3 dir, float fov)
// {
// 	t_camera *camera = malloc(sizeof(t_camera));
// 	if (!camera)
// 		return NULL;

// 	camera->pos = pos;
// 	camera->dir = vec3_normalize(dir);
// 	camera->fov = fov;

// 	return camera;
// }

void *parse_camera(char *str, int *map, t_window *window)
{
	t_vec3	pos;
	t_vec3	dir;
	t_ray	ray;
	double	fov;

	(void)map;
	int count = sscanf(str, "C %lf,%lf,%lf %lf,%lf,%lf %lf", &pos.x, &pos.y, &pos.z, &dir.x, &dir.y, &dir.z, &fov);
	printf("x %lf, y %lf, z %lf, dirx %lf, diry %lf, dirz %lf, fov %lf\n", pos.x, pos.y, pos.z, dir.x, dir.y, dir.z, fov);
	if (count != 7)
		return NULL;
	ray = (t_ray){pos, dir};
	window->camera = create_ccamera(window->mlx_window->width, window->mlx_window->height, ray, fov);
	map[OBJ_CAMERA]++;
	return (NULL);
}

void	*ft_array_realloc(void *array, size_t old_size, size_t new_size, size_t elem_size)
{
	void	*new_array;

	new_array = ft_calloc(new_size, elem_size);
	if (!new_array)
		return (NULL);
	if (array)
	{
		ft_memcpy(new_array, array, old_size * elem_size);
		free(array);
	}
	return (new_array);
}
t_object	create_light(char *define_line, int *map, t_window *window)
{
	char		**split;
	t_light		light;

	split = ft_split(define_line, ' ');
	if (!split)
		return (map[OBJ_ERROR]++, (t_object){});
	if (!(ft_veclen(split) == 4))
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	light.origin = fill_vec(split[1], map, -INFINITY, INFINITY);
	light.brightness = fill_double(split[2], map, 0, 1);
	light.color = fill_vec(split[3], map, 0, 255);
	printf("Error %d\n", map[OBJ_ERROR]);
	window->lights = ft_array_realloc(window->lights, window->num_lights, window->num_lights + 1, sizeof(t_light));
	if (window->lights == NULL)
		return (map[OBJ_ERROR]++, ft_vecfree(split), (t_object){});
	window->lights[window->num_lights] = light;
	window->num_lights += 1;
	return (map[OBJ_LIGHT]++, ft_vecfree(split), (t_object){});
}
