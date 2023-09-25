/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:05:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/25 16:02:47 by jkollner         ###   ########.fr       */
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
	printf("Error\n");
}
