/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:56:01 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/11 00:58:38 by mreidenb         ###   ########.fr       */
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
}	t_object_type;

int				parser(char *filename, t_window *window);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
double			ft_atof(char *str);
t_object		create_plane(char *define_line, int *map);
t_object		create_sphere(char *define_line, int *map);
t_object		create_cylinder(char *define_line, int *map);
t_object		create_error(int *map);
t_object		create_amb_light(char *define_line, int *map, t_window *window);
t_object		create_camera(char *define_line, int *map, t_window *window);
t_object		create_light(char *define_line, int *map, t_window *window);
void			error_clean(t_obj_list *head, int *map);
int				check_map(int *map);
int				ft_atov(char *str, t_vec3 *vec);
int				ft_strdnum(char *str);
t_vec3			fill_vec(char *subj, int *map, double min, double max);
double			fill_double(char *subj, int *map, double min, double max);
t_MaterialType	fill_material(char *subj, int *map);

void			*parse_camera(char *str, int *map, t_window *window);

#endif
