/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:54:25 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/25 16:02:26 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_object	create_ambient_light(char *define_line, int *map)
{
	(void)(define_line);
	//int			index;
	//char		**split;
	//t_object	ambient_light;

	//index = 0;
	//split = ft_split(define_line, ' ');
	//ambient_light.obj = t_ambinet_light;
	//// check size of split to see if input was correct amount
	//ambient_light.obj.ratio = ft_atof(split[1]);
	map[OBJECT_AMBIENT_LIGHT]++;
	return ((t_object){});
}

t_object	create_camera(char *define_line, int *map)
{
	(void)(define_line);
	map[OBJECT_CAMERA]++;
	return ((t_object){});
}

t_object	create_light(char *define_line, int *map)
{
	(void)(define_line);
	map[OBJECT_LIGHT]++;
	return ((t_object){});
}
