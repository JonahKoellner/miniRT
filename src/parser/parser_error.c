/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:05:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/26 13:07:18 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	clean_list(t_obj_list *head)
{
	t_obj_list	*tmp;

	while (head)
	{
		tmp = head->next_obj;
		free(head);
		head = tmp;
	}
}

void	error_clean(t_obj_list *head, int *map)
{
	clean_list(head);
	if (map[OBJECT_ERROR] > 0)
		printf("Error in creation of the object\n");
	else
		printf("Error\n");
}

int	check_map(int *map)
{
	printf("{\nOBJECT_CAMERA: %d,\n", map[OBJECT_CAMERA]);
	printf("OBJECT_LIGHT: %d,\n", map[OBJECT_LIGHT]);
	printf("OBJECT_SPHERE: %d,\n", map[OBJECT_SPHERE]);
	printf("OBJECT_PLANE: %d,\n", map[OBJECT_PLANE]);
	printf("OBJECT_CYLINDER: %d,\n", map[OBJECT_CYLINDER]);
	printf("OBJECT_AMBIENT_LIGHT: %d,\n", map[OBJECT_AMBIENT_LIGHT]);
	printf("OBJECT_ERROR: %d\n}\n", map[OBJECT_ERROR]);
	if (map[OBJECT_CAMERA] > 1 || map[OBJECT_LIGHT] > 1
		|| map[OBJECT_AMBIENT_LIGHT] > 1 || map[OBJECT_ERROR] > 0)
		return (1);
	return (0);
}
