/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:05:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/30 16:28:08 by jkollner         ###   ########.fr       */
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

char	*enun_to_str(int enun)
{
	if (enun == OBJ_CAMERA)
		return ("OBJ_CAMERA");
	if (enun == OBJ_LIGHT)
		return ("OBJ_LIGHT");
	if (enun == OBJ_SPHERE)
		return ("OBJ_SPHERE");
	if (enun == OBJ_PLANE)
		return ("OBJ_PLANE");
	if (enun == OBJ_CYLINDER)
		return ("OBJ_CYLINDER");
	if (enun == OBJ_CONE)
		return ("OBJ_CONE");
	if (enun == OBJ_AMBIENT_LIGHT)
		return ("OBJ_AMBIENT_LIGHT");
	if (enun == -1)
		return ("Unkown Object");
	return ("OBJ_ERROR");
}

void	error_clean(t_obj_list *head, int *map)
{
	printf("Error with %d. %s\n", map[map[OBJ_ERROR]] + 1,
		enun_to_str(map[OBJ_ERROR]));
	if (map[OBJ_ERROR] > 0)
		printf("Error in creation of the object\n");
	if (map[OBJ_CAMERA] > 1)
		printf("Too many cameras\n");
	if (map[OBJ_AMBIENT_LIGHT] > 1)
		printf("Too many ambient lights\n");
	else
		printf("Error\n");
	clean_list(head);
	free(map);
}

int	check_map(int *map, int final)
{
	printf("{\nOBJ_CAMERA: %d,\n", map[OBJ_CAMERA]);
	printf("OBJ_LIGHT: %d,\n", map[OBJ_LIGHT]);
	printf("OBJ_SPHERE: %d,\n", map[OBJ_SPHERE]);
	printf("OBJ_PLANE: %d,\n", map[OBJ_PLANE]);
	printf("OBJ_CYLINDER: %d,\n", map[OBJ_CYLINDER]);
	printf("OBJ_CONE: %d,\n", map[OBJ_CONE]);
	printf("OBJ_AMBIENT_LIGHT: %d,\n", map[OBJ_AMBIENT_LIGHT]);
	printf("OBJ_ERROR: %d\n}\n", map[OBJ_ERROR]);
	if (map[OBJ_CAMERA] > 1 || map[OBJ_AMBIENT_LIGHT] > 1 || map[OBJ_ERROR] > 0)
		return (1);
	if (final && (map[OBJ_CAMERA] != 1 || map[OBJ_AMBIENT_LIGHT] != 1))
		return (1);
	return (0);
}
