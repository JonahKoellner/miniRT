/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:37:13 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/25 10:43:32 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	key_hook(void	*param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	put_mlx(t_window *window, int width)
{
	window->mlx_window = mlx_init(width, (int)(width / window->aspect_ratio),
			"miniRT", true);
	if (!window->mlx_window)
		return (1);
	window->mlx_image = mlx_new_image(window->mlx_window,
			window->mlx_window->width, window->mlx_window->height);
	if (!window->mlx_image || (mlx_image_to_window(window->mlx_window,
				window->mlx_image, 0, 0) < 0))
		return (1);
	return (0);
}
