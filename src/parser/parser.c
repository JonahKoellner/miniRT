/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:41:15 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/25 11:17:41 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*read_file(char *filename)
{
	char	*buff;
	char	*gnl;
	int		filename_fd;

	filename_fd = open(filename, O_RDONLY);
	if (filename_fd < 0)
		return (NULL);
	buff = ft_calloc(1, sizeof(char));
	gnl = get_next_line(filename_fd);
	while (gnl)
	{
		if (!(gnl[0] == '\n'))
			buff = ft_realloc_j(buff, gnl);
		free(gnl);
		gnl = get_next_line(filename_fd);
	}
	return (buff);
}

int parser(char *filename)
{
	char *content;

	content = read_file(filename);
	if (!content)
		return (1);
	printf("%s\n", content);
	free(content);
	system("leaks miniRT");
	return (0);
}
