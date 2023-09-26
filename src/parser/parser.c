/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:41:15 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/26 11:05:23 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	id_object(char *definition_line, int *map)
{
	t_object	obj;
	if (!ft_strncmp("A ", definition_line, 2))
		obj = create_ambient_light(definition_line ,map);
	else if (!ft_strncmp("C ", definition_line, 2))
		obj = create_camera(definition_line, map);
	else if (!ft_strncmp("L ", definition_line, 2))
		obj = create_light(definition_line, map);
	else if (!ft_strncmp("pl ", definition_line, 3))
		obj = create_plane(definition_line, map);
	else if (!ft_strncmp("sp ", definition_line, 3))
		obj = create_sphere(definition_line, map);
	else if (!ft_strncmp("cy ", definition_line, 3))
		obj = create_cylinder(definition_line, map);
	else
		obj = create_error(map);
	return (obj);
}

t_obj_list	*interpretate_object(char *line, t_obj_list *list_obj, int *map)
{
	int	index;

	index = 0;
	while (ft_isspace(line[index]))
		index++;
	if (line[index] == '\0')
		return (NULL);
	list_obj->obj = id_object(&line[index], map);
	list_obj->next_obj = ft_calloc(1, sizeof(t_obj_list));
	return (list_obj->next_obj);
}

int	check_map(int *map)
{
	printf("{\nOBJECT_CAMERA: %d,\n", map[OBJECT_CAMERA]);
	printf("OBJECT_LIGHT: %d,\n", map[OBJECT_LIGHT]);
	printf("OBJECT_SPHERE: %d,\n", map[OBJECT_SPHERE]);
	printf("OBJECT_PLANE: %d,\n", map[OBJECT_PLANE]);
	//printf("OBJECT_SQUARE: %d\n", map[OBJECT_SQUARE]);
	printf("OBJECT_CYLINDER: %d,\n", map[OBJECT_CYLINDER]);
	//printf("OBJECT_TRIANGLE: %d\n", map[OBJECT_TRIANGLE]);
	printf("OBJECT_AMBIENT_LIGHT: %d,\n", map[OBJECT_AMBIENT_LIGHT]);
	printf("OBJECT_ERROR: %d\n}\n", map[OBJECT_ERROR]);
	if (map[OBJECT_CAMERA] > 1 || map[OBJECT_LIGHT] > 1
		|| map[OBJECT_AMBIENT_LIGHT] > 1)
		return (1);
	return (0);
}

t_obj_list	*read_file(int fd)
{
	char		*gnl;
	t_obj_list	*head;
	t_obj_list	*root;
	int			*map;

	gnl = get_next_line(fd);
	head = ft_calloc(1, sizeof(t_obj_list));
	if (!head)
		return (NULL);
	map = ft_calloc(OBJECT_ENUM_SIZE, sizeof(int));
	root = head;
	while (gnl)
	{
		if (!(gnl[0] == '\n'))
			head = interpretate_object(gnl, head, map);
		if (head == NULL || (!(gnl[0] == '\n') && check_map(map)))
			return (error_clean(root, map), free(gnl), NULL);
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (root);
}

int parser(char *filename)
{
	t_obj_list	*head;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	head = read_file(fd);
	if (!head)
		return (1);
	return (0);
}
