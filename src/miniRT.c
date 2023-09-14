/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:46:22 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/13 23:06:10 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

uint32_t	ray_color(t_ray r)
{
	
	t_vec3	unit_direction = unit_vec(r.direction);
	double	a = 0.5 * (unit_direction.y + 1);
	t_vec3	color = vec3_add_vec3(vec3_mult_double((t_vec3){1, 1, 1}, 1.0 - a),
						vec3_mult_double((t_vec3){0.5, 0.7, 1.0}, a));
	return (mlx_color(color.x * 255, color.y * 255, color.z * 255, 255));
}

int main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	/// Calc
	double aspect_ratio = 16.0 / 9.0;

	int width = 400;
	int height = (int)(width / aspect_ratio);

	// Cameraıı∫
	double	viewport_height = 2.0;
	double	focal_length = 1.0;
	double	viewport_width = viewport_height * ((double)(width) / height);
	t_vec3	cam_center = {0, 0, 0};
	t_vec3	viewport_u = {viewport_width, 0, 0};
	t_vec3	viewport_v = {0, -viewport_height, 0};
	t_vec3	pix_delt_u = vec3_div_double(viewport_u, (double)width);
	t_vec3	pix_delt_v = vec3_div_double(viewport_v, (double)height);

	t_vec3	viewport_upr_left = vec3_sub_vec3(vec3_sub_vec3(vec3_sub_vec3
				(cam_center, (t_vec3){0, 0, focal_length}), vec3_div_double
				(viewport_u, 2)), vec3_div_double(viewport_v, 2));
	t_vec3	auf_lock = vec3_add_vec3(viewport_upr_left, vec3_mult_double
			(vec3_add_vec3(pix_delt_u, pix_delt_v), 0.5));

	mlx = mlx_init((int)width, (int)height, "miniRT", true);
	if (!mlx)
		return (1);
	image = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		return (1);


	for (uint32_t j = 0; j < image->height; ++j)
	{
		for (uint32_t i = 0; i < image->width; ++i)
		{
			t_vec3 pix_center = vec3_add_vec3(auf_lock, vec3_add_vec3
					(vec3_mult_double(pix_delt_u, i),
						vec3_mult_double(pix_delt_v, j)));
			t_vec3	ray_direction = vec3_sub_vec3(pix_center, cam_center);
			t_ray	ray = {cam_center, ray_direction};
			mlx_put_pixel(image, i, j, ray_color(ray));
		}
	}




	// fade(image);
	mlx_loop_hook(mlx, key_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
