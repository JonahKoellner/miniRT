/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:05:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/29 16:13:49 by jonahkollne      ###   ########.fr       */
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
	(void)head;
	if (map[OBJ_ERROR] > 0)
		printf("Error in creation of the object\n");
	else
		printf("Error\n");
	clean_list(head);
	free(map);
}

int	check_map(int *map)
{
	printf("{\nOBJ_CAMERA: %d,\n", map[OBJ_CAMERA]);
	printf("OBJ_LIGHT: %d,\n", map[OBJ_LIGHT]);
	printf("OBJ_SPHERE: %d,\n", map[OBJ_SPHERE]);
	printf("OBJ_PLANE: %d,\n", map[OBJ_PLANE]);
	printf("OBJ_CYLINDER: %d,\n", map[OBJ_CYLINDER]);
	printf("OBJ_CONE: %d,\n", map[OBJ_CONE]);
	printf("OBJ_AMBIENT_LIGHT: %d,\n", map[OBJ_AMBIENT_LIGHT]);
	printf("OBJ_ERROR: %d\n}\n", map[OBJ_ERROR]);
	if (map[OBJ_CAMERA] != 1 || map[OBJ_AMBIENT_LIGHT] != 1 || map[OBJ_ERROR] > 0)
		return (1);
	return (0);
}
