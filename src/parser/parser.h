/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:56:01 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/28 14:42:23 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

# include "gnl.h"

typedef enum e_object_type
{
	OBJ_AMBIENT_LIGHT,
	OBJ_CAMERA,
	OBJ_LIGHT,
	OBJ_PLANE,
	OBJ_SPHERE,
	OBJ_CYLINDER,
	OBJ_ERROR,
	OBJ_ENUM_SIZE
} t_object_type;

int			parser(char *filename, t_window *window);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double 		ft_atof(char *str);
t_object	create_plane(char *define_line, int *map);
t_object	create_sphere(char *define_line, int *map);
t_object	create_cylinder(char *define_line, int *map);
t_object	create_error(int *map);
t_object	create_ambient_light(char *define_line, int *map, t_window *window);
t_object	create_camera(char *define_line, int *map, t_window *window);
t_object	create_light(char *define_line, int *map, t_window *window);
void		error_clean(t_obj_list *head, int *map);
int			check_map(int *map);
double 		ft_atof(char *str);
int			ft_atov(char *str, t_vec3 *vec);
int			ft_strdnum(char *str);

#endif
