/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:46:22 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/25 15:57:05 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	key_hook(void* param)
{
	mlx_t	*mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

//t_camera	create_camera(int width, int height)
//{
//	t_camera camera;

//	camera.viewport_height = 2.0;
//	camera.focal_length = 1.0;
//	camera.viewport_width = camera.viewport_height
//								* ((double)(width) / height);
//	camera.cam_center = (t_vec3){0, 0, 0};
//	camera.viewport_u = (t_vec3){camera.viewport_width, 0, 0};
//	camera.viewport_v = (t_vec3){0, - camera.viewport_height, 0};
//	camera.pix_delt_u = vec3_div_double(camera.viewport_u, (double)width);
//	camera.pix_delt_v = vec3_div_double(camera.viewport_v, (double)height);

//	camera.viewport_upr_left = vec3_sub_vec3(vec3_sub_vec3(vec3_sub_vec3
//				(camera.cam_center,
//					(t_vec3){0, 0, camera.focal_length}), vec3_div_double
//				(camera.viewport_u, 2)),
//					vec3_div_double(camera.viewport_v, 2));
//	camera.auf_lock = vec3_add_vec3(camera.viewport_upr_left,
//			vec3_mult_double
//			(vec3_add_vec3(camera.pix_delt_u, camera.pix_delt_v), 0.5));
//	return (camera);
//}

void	loading(double val, int max)
{
	// printf("%d\n", (int)((val / max) * 10));
	printf("Tracing[");
	printf("%.*s", (int)((val / max) * 10), "==========");
	printf("%.*s", 10 - (int)((val / max) * 10), "          ");
	printf("]%.0f %%", ((val / max) * 100));
}

int	gradient_test(t_window	*window)
{
	t_vec3	aa_color;

	printf("\n");

	for (uint32_t j = 0; j < window->mlx_image->height; ++j)
	{
		for (uint32_t i = 0; i < window->mlx_image->width; ++i)
		{
			aa_color = pixel_sample_square(window, i, j);
			mlx_put_pixel(window->mlx_image, i, j, mlx_color(aa_color));
		}
		printf("\r");
		loading((double)(j * window->mlx_image->width), (window->mlx_image->height * window->mlx_image->width));
		// printf("Traced ==> %.0f %%", ((double)(j * window->mlx_image->width)
			// / (window->mlx_image->height * window->mlx_image->width)) * 100);
		fflush(stdout);
	}
	printf("\r");
	printf("Tracing[==========]100 %%\n");
	return (0);
}

//void	init_objects(t_window *window)
//{
//	t_material mat_ground;
//	mat_ground.type = LAMBERTIAN;
//	mat_ground.color = (t_vec3){0.8, 0.8, 0.0};
//	// mat_ground.reflectance = 0.2;

//	t_material mat_mid;
//	mat_mid.type = LAMBERTIAN;
//	mat_mid.color = (t_vec3){0.7, 0.3, 0.3};
//	// mat_ground.reflectance = 0.2;

//	t_material mat_metal_even;
//	mat_metal_even.type = METAL;
//	mat_metal_even.color = (t_vec3){0.8, 0.8, 0.8};
//	// mat_metal_even.reflectance = 0.7;

//	t_material mat_metal_yellow;
//	mat_metal_yellow.type = METAL;
//	mat_metal_yellow.color = (t_vec3){0.8, 0.6, 0.2};
//	// mat_metal_yellow.reflectance = 0.7;

//	t_material stop;
//	stop.type = STOP;

//	window->objects = ft_calloc(6, sizeof(t_object));
//	// window->objects[0].obj = (t_hittable){.sphere = (t_sphere){{0, -100.5, -1}, 100.0}};
//	// window->objects[0].hit_func = &hit_sphere;
//	// window->objects[0].mat = mat_ground;

//	window->objects[0].obj = (t_hittable){.plane = (t_plane){{0, -0.5, -1}, {0, -1, 0}}};
//	window->objects[0].hit_func = &hit_plane;
//	window->objects[0].mat = mat_ground;

//	// window->objects[1].obj = (t_hittable){.sphere = (t_sphere){{0, 0, -1}, .5}};
//	// window->objects[1].hit_func = &hit_sphere;
//	// window->objects[1].mat = mat_mid;

//	window->objects[1].obj = (t_hittable){.cylinder = (t_cylinder){{0, -0.5, -1}, {0, 1, 0.0}, .5, 50}};
//	window->objects[1].hit_func = &hit_cylinder;
//	window->objects[1].mat = mat_metal_yellow;

//	window->objects[2].obj = (t_hittable){.sphere = (t_sphere){{-1.0, 0, -1.0}, .5}};
//	window->objects[2].hit_func = &hit_sphere;
//	window->objects[2].mat = mat_metal_even;

//	window->objects[3].obj = (t_hittable){.sphere = (t_sphere){{1.0, 0, -1.0}, .5}};
//	window->objects[3].hit_func = &hit_sphere;
//	window->objects[3].mat = mat_mid;

//	window->objects[4].mat = stop;

//	// t_material	material;
//	// material.type = LAMBERTIAN;
//	// material.color = (t_vec3){0.0, 0.0, 0.0};
//	// t_material	material2;
//	// material2.type = METAL;
//	// material2.color = (t_vec3){0.9, 0.9, 0.9};
//	// window->objects = ft_calloc(5, sizeof(t_object));
//	// window->objects[0].obj = (t_hittable){.sphere = (t_sphere){{.5, .5, -2}, 0.3}};
//	// window->objects[0].hit_func = &hit_sphere;
//	// window->objects[0].mat = material;
//	// window->objects[1].obj = (t_hittable){.sphere = (t_sphere){{-.5, .5, -2}, 0.3}};
//	// window->objects[1].hit_func = &hit_sphere;
//	// window->objects[1].mat = material;
//	// material.color = (t_vec3){1.0, 0.8, 0.5};
//	// window->objects[2].obj = (t_hittable){.sphere = (t_sphere){{0, 0, -2}, 0.5}};
//	// window->objects[2].hit_func = &hit_sphere;
//	// window->objects[2].mat = material;
//	// window->objects[3].obj = (t_hittable){.sphere = (t_sphere){{0, -1001.0, -1}, 1000}};
//	// window->objects[3].hit_func = &hit_sphere;
//	// window->objects[3].mat = material2;
//}

int main(int argc, char *argv[])
{
	t_window	*window;
	int			width;

	width = 400;
	window = malloc(1 * sizeof(t_window));
	window->aspect_ratio = 16.0 / 9.0;
	//window->camera = create_camera(width, (int)(width / window->aspect_ratio));
	window->mlx_window = mlx_init(width, (int)(width / window->aspect_ratio), "miniRT", true);
	if (!window->mlx_window)
		return (1);
	window->mlx_image = mlx_new_image(window->mlx_window,
			window->mlx_window->width, window->mlx_window->height);
	if (!window->mlx_image || (mlx_image_to_window(window->mlx_window, window->mlx_image, 0, 0) < 0))
		return (1);

	//init_objects(window);
	if (argc == 2)
		parser(argv[1]);
	//gradient_test(window);
	mlx_loop_hook(window->mlx_window, key_hook, window->mlx_window);
	mlx_loop(window->mlx_window);
	mlx_terminate(window->mlx_window);
	return (0);
}





// #include "miniRT.h"
// #include <stdlib.h>
// #include <stdio.h>

// void	key_hook(void* param)
// {
// 	mlx_t	*mlx = (mlx_t *)param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// }

// int	fade(mlx_image_t *image)
// {
// 	for (uint32_t i = 0; i < image->height; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->width; ++y)
// 		{
// 			uint32_t color = mlx_color(
// 				y,
// 				i,
// 				0,
// 				255
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// 	return (0);
// }

// int main(void)
// {
// 	mlx_t		*mlx;
// 	mlx_image_t	*image;

// 	/// Calc
// 	double aspect_ratio = 16.0 / 9.0;

// 	int width = 400;
// 	int height = (int)(width / aspect_ratio);

// 	// Cameraıı∫
// 	double	viewport_height = 2.0;
// 	double	focal_length = 1.0;
// 	double	viewport_width = viewport_height * ((double)(width) / height);
// 	t_vec3	cam_center = {0, 0, 0};
// 	t_vec3	viewport_u = {viewport_width, 0, 0};
// 	t_vec3	viewport_v = {0, -viewport_height, 0};
// 	t_vec3	pix_delt_u = vec3_div_double(viewport_u, (double)width);
// 	t_vec3	pix_delt_v = vec3_div_double(viewport_v, (double)height);

// 	t_vec3	viewport_upr_left = vec3_sub_vec3(vec3_sub_vec3(vec3_sub_vec3
// 				(cam_center, (t_vec3){0, 0, focal_length}), vec3_div_double
// 				(viewport_u, 2)), vec3_div_double(viewport_v, 2));
// 	t_vec3	auf_lock = vec3_add_vec3(viewport_upr_left, vec3_mult_double
// 			(vec3_add_vec3(pix_delt_u, pix_delt_v), 0.5));

// 	mlx = mlx_init((int)width, (int)height, "miniRT", true);
// 	if (!mlx)
// 		return (1);
// 	image = mlx_new_image(mlx, mlx->width, mlx->height);
// 	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
// 		return (1);


// 	for (uint32_t j = 0; j < image->height; ++j)
// 	{
// 		for (uint32_t i = 0; i < image->width; ++i)
// 		{
// 			t_vec3 pix_center = vec3_add_vec3(auf_lock, vec3_add_vec3
// 					(vec3_mult_double(pix_delt_u, i),
// 						vec3_mult_double(pix_delt_v, j)));
// 			t_vec3	ray_direction = vec3_sub_vec3(pix_center, cam_center);
// 			t_ray	ray = {cam_center, ray_direction};
// 			mlx_put_pixel(image, i, j, ray_color(ray));
// 		}
// 	}
// 	// fade(image);
// 	mlx_loop_hook(mlx, key_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (0);
// }




