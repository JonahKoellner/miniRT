/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:04:00 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/25 16:01:01 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_object	create_plane(char *define_line, int *map)
{
	(void)(define_line);
	map[OBJECT_PLANE]++;
	return ((t_object){});
}

t_object	create_sphere(char *define_line, int *map)
{
	(void)(define_line);
	map[OBJECT_SPHERE]++;
	return ((t_object){});
}

t_object	create_cylinder(char *define_line, int *map)
{
	(void)(define_line);
	map[OBJECT_CYLINDER]++;
	return ((t_object){});
}

t_object	create_error(int *map)
{
	map[OBJECT_ERROR]++;
	return ((t_object){});
}
