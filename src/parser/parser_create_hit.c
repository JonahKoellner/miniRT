/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:04:00 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/26 10:41:52 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_object	create_plane(char *define_line, int *map)
{
	(void)(define_line);
	map[OBJECT_PLANE]++;
	printf("plane\n");
	return ((t_object){});
}

t_object	create_sphere(char *define_line, int *map)
{
	(void)(define_line);
	map[OBJECT_SPHERE]++;
	printf("sphere\n");
	return ((t_object){});
}

t_object	create_cylinder(char *define_line, int *map)
{
	(void)(define_line);
	map[OBJECT_CYLINDER]++;
	printf("cylinder\n");
	return ((t_object){});
}

t_object	create_error(int *map)
{
	map[OBJECT_ERROR]++;
	printf("error\n");
	return ((t_object){});
}
