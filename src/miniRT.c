/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:46:22 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/11 10:52:42 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <pthread.h>

void	key_hook(void* param)
{
	mlx_t	*mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

t_camera	create_ccamera(int width, int height, t_ray	cam_ray, double fov)
{
	t_camera camera;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;

	w = unitv(cam_ray.direction);
	u = unitv(cross((t_vec3){0, 1, 0}, w));
	v = negate(cross(u, w));
	camera.viewport_height = 2 * tan(degrees_to_radians(fov) / 2);
	camera.focal_length = 0.2;
	camera.viewport_width = camera.viewport_height
								* ((double)(width) / height);
	camera.cam_center = cam_ray.origin;
	camera.viewport_u = vmultv((t_vec3){camera.viewport_width, 0, 0}, u);
	camera.viewport_v = vmultv((t_vec3){0, - camera.viewport_height, 0}, v);
	camera.pix_delt_u = vdivd(camera.viewport_u, (double)width);
	camera.pix_delt_v = vdivd(camera.viewport_v, (double)height);
	// camera.viewport_upr_left = vsubv(vsubv(vsubv(camera.cam_center,
	// 				vmultv((t_vec3){0, 0, camera.focal_length}, w)),
	// 			vdivd(camera.viewport_u, 2)), vdivd(camera.viewport_v, 2));
	camera.viewport_upr_left = vsubv(camera.cam_center,
			vaddv(vaddv(vdivd(camera.viewport_u, 2), vdivd(camera.viewport_v, 2)),
				vmultv((t_vec3){0, 0, camera.focal_length}, w)));
	camera.auf_lock = vaddv(camera.viewport_upr_left,
			vmultd
			(vaddv(camera.pix_delt_u, camera.pix_delt_v), 0.5));
	return (camera);
}

void	loading(double val, int max)
{
	static double loaded = 0;
	// printf("%d\n", (int)((val / max) * 10));
	loaded += val;
	printf("Tracing[");
	printf("%.*s", (int)((loaded / max) * 10), "==========");
	printf("%.*s", 10 - (int)((loaded / max) * 10), "          ");
	printf("]%.0f %%", ((loaded / max) * 100));
}

typedef struct {
	uint32_t start;
	uint32_t end;
	t_window *window;
} thread_args_t;

void *render_thread(void *args)
{
	thread_args_t *thread_args = (thread_args_t *)args;
	t_vec3 aa_color;

	for (uint32_t j = thread_args->start; j < thread_args->end; ++j)
	{
		for (uint32_t i = 0; i < thread_args->window->mlx_image->width; ++i)
		{
			aa_color = pixel_sample_square(thread_args->window, i, j);
			mlx_put_pixel(thread_args->window->mlx_image, i, j, mlx_color(aa_color));
		}
		printf("\r");
		loading((double)(thread_args->window->mlx_image->width), (thread_args->window->mlx_image->height * thread_args->window->mlx_image->width));
		fflush(stdout);
	}

	return NULL;
}

int gradient_test(t_window *window)
{
	const uint32_t num_threads = 4;
	pthread_t threads[num_threads];
	thread_args_t thread_args[num_threads];
	uint32_t rows_per_thread = window->mlx_image->height / num_threads;
	uint32_t remaining_rows = window->mlx_image->height % num_threads;
	uint32_t start = 0;

	printf("\nTracing[          ]  0 %%");

	for (uint32_t i = 0; i < num_threads; ++i)
	{
		thread_args[i].start = start;
		thread_args[i].end = start + rows_per_thread + (i < remaining_rows ? 1 : 0);
		thread_args[i].window = window;
		pthread_create(&threads[i], NULL, render_thread, &thread_args[i]);
		start = thread_args[i].end;
	}

	for (uint32_t i = 0; i < num_threads; ++i)
	{
		pthread_join(threads[i], NULL);
	}

	printf("\r");
	printf("Tracing[==========]100 %%\n");
	return (0);
}

// int	gradient_test(t_window	*window)
// {
// 	t_vec3	aa_color;

// 	printf("\n");

// 	#pragma omp parallel for num_threads(16)
// 	for (uint32_t j = 0; j < window->mlx_image->height; ++j)
// 	{
// 		for (uint32_t i = 0; i < window->mlx_image->width; ++i)
// 		{
// 			aa_color = pixel_sample_square(window, i, j);
// 			mlx_put_pixel(window->mlx_image, i, j, mlx_color(aa_color));
// 		}
// 		printf("\r");
// 		loading((double)(j * window->mlx_image->width), (window->mlx_image->height * window->mlx_image->width));
// 		// printf("Traced ==> %.0f %%", ((double)(j * window->mlx_image->width)
// 			// / (window->mlx_image->height * window->mlx_image->width)) * 100);
// 		fflush(stdout);
// 	}
// 	printf("\r");
// 	printf("Tracing[==========]100 %%\n");
// 	return (0);
// }

int main(int argc, char *argv[])
{
	t_window	*window;
	int			width;

	width = 800;
	window = malloc(1 * sizeof(t_window));
	window->aspect_ratio = 16.0 / 9.0;
	// window->camera = create_ccamera(width, (int)(width / window->aspect_ratio));
	window->mlx_window = mlx_init(width, (int)(width / window->aspect_ratio), "miniRT", true);
	if (!window->mlx_window)
		return (1);
	window->mlx_image = mlx_new_image(window->mlx_window,
			window->mlx_window->width, window->mlx_window->height);
	if (!window->mlx_image || (mlx_image_to_window(window->mlx_window, window->mlx_image, 0, 0) < 0))
		return (1);
	window->lights = ft_calloc(1, sizeof(t_light));
	window->num_lights = 0;
	// init_lights(window);
	//init_objects(window);
	if (argc != 2)
		return (1);
	if (parser(argv[1], window))
		return (1); // clean window as well. Dont need to clean objects, if error in parser there are no objects
	printf("back in main\n");
	gradient_test(window);
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
// 	t_vec3	pix_delt_u = vdivd(viewport_u, (double)width);
// 	t_vec3	pix_delt_v = vdivd(viewport_v, (double)height);

// 	t_vec3	viewport_upr_left = vsubv(vsubv(vsubv
// 				(cam_center, (t_vec3){0, 0, focal_length}), vdivd
// 				(viewport_u, 2)), vdivd(viewport_v, 2));
// 	t_vec3	auf_lock = vaddv(viewport_upr_left, vmultd
// 			(vaddv(pix_delt_u, pix_delt_v), 0.5));

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
// 			t_vec3 pix_center = vaddv(auf_lock, vaddv
// 					(vmultd(pix_delt_u, i),
// 						vmultd(pix_delt_v, j)));
// 			t_vec3	ray_direction = vsubv(pix_center, cam_center);
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




