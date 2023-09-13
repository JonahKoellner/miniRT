/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:46:22 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/13 12:53:54 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdlib.h>
#include <stdio.h>

void	key_hook(void* param)
{
	mlx_t	*mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}


int	fade(mlx_image_t *image)
{
	for (uint32_t i = 0; i < image->height; ++i)
	{
		for (uint32_t y = 0; y < image->width; ++y)
		{
			uint32_t color = mlx_color(
				y,
				i,
				0,
				255
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
	return (0);
}

int main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	int ratio = 16 / 9;
	mlx = mlx_init(256, 256 / ratio, "miniRT", true);
	if (!mlx)
		return (1);
	image = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		return (1);
	fade(image);
	mlx_loop_hook(mlx, key_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
