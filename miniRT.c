/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:46:22 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/13 12:01:34 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int argc, char const *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*image;


	argc++;
	(void)argv;
	mlx = mlx_init(256, 256, "miniRT", true);
	if (!mlx)
		return (1);
	image = mlx_new_image(mlx, 256, 256);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		return (1);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return 0;
}
