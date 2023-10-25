/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:59:46 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/25 09:49:10 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
// Includes

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "miniRT.h"

// Declarations

char	*get_next_line(int fd);
void	*ft_realloc_j(char *first, char *last);
int		clean_up_buffer(char *buffer);
void	*ft_calloc(size_t count, size_t size);
int		check_nl(char *buffer);
char	*copy_out(char *buffer, int amount);
//int		ft_strlen(char *string);
//void	ft_bzero(char *buffer, int n);
#endif /* GET_NEXT_LINE_H */
