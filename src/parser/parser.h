/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:56:01 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/25 16:01:17 by jkollner         ###   ########.fr       */
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
	OBJECT_AMBIENT_LIGHT,
	OBJECT_CAMERA,
	OBJECT_LIGHT,
	OBJECT_PLANE,
	OBJECT_SPHERE,
	//OBJECT_SQUARE,
	OBJECT_CYLINDER,
	//OBJECT_TRIANGLE,
	OBJECT_ERROR,
	OBJECT_ENUM_SIZE
} t_object_type;

int parser(char *filename);
int	ft_isspace(char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
double ft_atof(char *str);
t_object	create_camera(char *define_line, int *map);
t_object	create_light(char *define_line, int *map);
t_object	create_plane(char *define_line, int *map);
t_object	create_sphere(char *define_line, int *map);
t_object	create_cylinder(char *define_line, int *map);
t_object	create_error(int *map);
t_object	create_ambient_light(char *define_line, int *map);
void		error_clean(t_obj_list *head, int *map);

#endif
