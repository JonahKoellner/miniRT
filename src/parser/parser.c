/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:41:15 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/28 14:17:27 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	id_obj(char *definition_line, int *map, t_window *window)
{
	if (!ft_strncmp("A ", definition_line, 2))
		create_ambient_light(definition_line, map, window);
	else if (!ft_strncmp("C ", definition_line, 2))
		create_camera(definition_line, map, window);
	else if (!ft_strncmp("L ", definition_line, 2))
		create_light(definition_line, map, window);
	else
		return (0);
	return (1);
}

t_object	id_hit(char *definition_line, int *map)
{
	t_object	obj;

	definition_line = ft_strtrim(definition_line, " \n");
	if (!ft_strncmp("pl ", definition_line, 3))
		obj = create_plane(definition_line, map);
	else if (!ft_strncmp("sp ", definition_line, 3))
		obj = create_sphere(definition_line, map);
	else if (!ft_strncmp("cy ", definition_line, 3))
		obj = create_cylinder(definition_line, map);
	else
		obj = create_error(map);
	return (obj);
}

t_obj_list	*make_obj(char *line, t_obj_list *l_obj, int *map, t_window *window)
{
	int			index;
	t_object	hit;

	index = 0;
	while (ft_isspace(line[index]))
		index++;
	if (line[index] == '\0')
		return (NULL);
	if (id_obj(&line[index], map, window))
		return (l_obj);
	hit = id_hit(&line[index], map);
	if (map[OBJECT_ERROR] > 0)
		return (NULL);
	l_obj->obj = hit;
	l_obj->next_obj = ft_calloc(1, sizeof(t_obj_list));
	return (l_obj->next_obj);
}

t_obj_list	*read_file(int fd, t_window *window)
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
			head = make_obj(gnl, head, map, window);
		if (head == NULL || (!(gnl[0] == '\n') && check_map(map)))
			return (error_clean(root, map), free(gnl), NULL);
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (root);
}

int parser(char *filename, t_window *window)
{
	t_obj_list	*head;
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	head = read_file(fd, window);
	if (!head)
		return (1);
	window->objects = head;
	return (0);
}
