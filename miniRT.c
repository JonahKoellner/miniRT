// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   miniRT.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/09/13 09:46:22 by jkollner          #+#    #+#             */
// /*   Updated: 2023/09/18 14:39:37 by jkollner         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "miniRT.h"
// #include <stdlib.h>
// #include <stdio.h>

// void	key_hook(void* param)
// {
// 	mlx_t	*mlx = (mlx_t *)param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// }

// t_camera	create_camera(int width, int height)
// {
// 	t_camera camera;

// 	camera.viewport_height = 2.0;
// 	camera.focal_length = 1.0;
// 	camera.viewport_width = camera.viewport_height
// 								* ((double)(width) / height);
// 	camera.cam_center = (t_vec3){0, 0, 0};
// 	camera.viewport_u = (t_vec3){camera.viewport_width, 0, 0};
// 	camera.viewport_v = (t_vec3){0, - camera.viewport_height, 0};
// 	camera.pix_delt_u = vec3_div_double(camera.viewport_u, (double)width);
// 	camera.pix_delt_v = vec3_div_double(camera.viewport_v, (double)height);

// 	camera.viewport_upr_left = vec3_sub_vec3(vec3_sub_vec3(vec3_sub_vec3
// 				(camera.cam_center,
// 					(t_vec3){0, 0, camera.focal_length}), vec3_div_double
// 				(camera.viewport_u, 2)),
// 					vec3_div_double(camera.viewport_v, 2));
// 	camera.auf_lock = vec3_add_vec3(camera.viewport_upr_left,
// 			vec3_mult_double
// 			(vec3_add_vec3(camera.pix_delt_u, camera.pix_delt_v), 0.5));
// 	return (camera);
// }

// int	gradient_test(t_window	*window)
// {
// 	for (uint32_t j = 0; j < window->mlx_image->height; ++j)
// 	{
// 		for (uint32_t i = 0; i < window->mlx_image->width; ++i)
// 		{
// 			t_vec3 pix_center = vec3_add_vec3(window->camera.auf_lock, vec3_add_vec3
// 					(vec3_mult_double(window->camera.pix_delt_u, i),
// 						vec3_mult_double(window->camera.pix_delt_v, j)));
// 			t_vec3	ray_direction = vec3_sub_vec3(pix_center, window->camera.cam_center);
// 			t_ray	ray = {window->camera.cam_center, ray_direction};
// 			mlx_put_pixel(window->mlx_image, i, j, ray_color(ray));
// 		}
// 	}
// 	return (0);
// }

// int main(void)
// {
// 	t_window	*window;

// 	window = malloc(1 * sizeof(t_window));
// 	window->aspect_ratio = 16.0 / 9.0;
// 	window->camera = create_camera(400, (int)(400 / window->aspect_ratio));
// 	window->mlx_window = mlx_init(400, (int)(400 / window->aspect_ratio), "miniRT", true);
// 	if (!window->mlx_window)
// 		return (1);
// 	window->mlx_image = mlx_new_image(window->mlx_window,
// 						window->mlx_window->width, window->mlx_window->height);
// 	if (!window->mlx_image || (mlx_image_to_window(window->mlx_window, window->mlx_image, 0, 0) < 0))
// 		return (1);
// 	gradient_test(window);
// 	mlx_loop_hook(window->mlx_window, key_hook, window->mlx_window);
// 	mlx_loop(window->mlx_window);
// 	mlx_terminate(window->mlx_window);
// 	return (0);
// }
