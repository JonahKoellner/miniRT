/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:54:25 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/28 14:42:23 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_object	create_ambient_light(char *define_line, int *map, t_window *window)
{
	//int			index;
	//char		**split;
	//t_object	ambient_light;

	//if (map[OBJ_AMBIENT_LIGHT] > 0)
	//	return (map[OBJ_ERROR]++, (t_object){});
	//index = 0;
	//split = ft_split(define_line, ' ');
	//if (ft_veclen(split) != 3) // num_args + identifier
	//	return (map[OBJ_ERROR]++, (t_object){});
	//ambient_light.obj = t_ambinet_light;
	//ambient_light.obj.ratio = ft_atof(split[1]);
	(void)define_line;
	(void)window;
	map[OBJ_AMBIENT_LIGHT]++;
	printf("ambient light\n");
	//return (ambient_light);
	return ((t_object){}); // for compiling now
}

t_object	create_camera(char *define_line, int *map, t_window *window)
{
	//char		**split;
	//t_vec3		*vec;

	//if (map[OBJ_CAMERA] > 0)
	//	return (map[OBJ_ERROR]++, (t_object){});
	//split = ft_split(define_line, ' ');
	//if (!split)
	//	return (map[OBJ_ERROR]++, (t_object){});
	//vec = ft_calloc(1, sizeof(t_vec3));
	//if (!vec)
	//	return (map[OBJ_ERROR]++, (t_object){});
	//if (ft_atov(split[1], vec))
	//	return (free(vec), ft_vecfree(split), map[OBJ_ERROR]++, (t_object){});
	//window->camera.cam_center = *vec;
	//if (ft_atov(split[2], vec))
	//	return (free(vec), ft_vecfree(split), map[OBJ_ERROR]++, (t_object){});
	//if ((vec->x < -1 || vec->x > 1) || (vec->y < -1 || vec->y > 1)
	//	|| (vec->z < -1 || vec->z > 1))
	//		return (free(vec), ft_vecfree(split), map[OBJ_ERROR]++, (t_object){});
	////window->camera. = *vec; //3d normalized oriental vector
	////window->camera. = ft_atof(split[3]); // FOV
	//if (window->camera. < 0 || window->camera. > 180)
	//	return (free(vec), ft_vecfree(split), map[OBJ_ERROR]++, (t_object){});
	//return (free(vec), ft_vecfree(split), map[OBJ_CAMERA]++, (t_object){});

	(void)define_line;
	(void)map;
	(void)window;
	return ((t_object){}); // for compiling now

}

t_object	create_light(char *define_line, int *map, t_window *window)
{
	if (map[OBJ_LIGHT] > 0)
		return (map[OBJ_ERROR]++, (t_object){});
	(void)define_line;
	(void)window;
	map[OBJ_LIGHT]++;
	printf("light\n");
	return ((t_object){});
}
