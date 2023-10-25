/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:46:22 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/25 10:45:26 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <pthread.h>

t_camera	create_ccamera(int width, int height, t_ray	cam_ray, double fov)
{
	t_camera	cam;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;

	w = negate(unitv(cam_ray.direction));
	u = unitv(cross((t_vec3){0, 1, 0}, w));
	v = negate(cross(u, w));
	cam.viewport_height = 2 * tan(degrees_to_radians(fov) / 2);
	cam.focal_length = 1;
	cam.viewport_width = cam.viewport_height
		* ((double)(width) / height);
	cam.cam_center = cam_ray.origin;
	cam.viewport_u = vmultv((t_vec3){cam.viewport_width, 0, 0}, u);
	cam.viewport_v = vmultv((t_vec3){0, -cam.viewport_height, 0}, v);
	cam.pix_delt_u = vdivd(cam.viewport_u, (double)width);
	cam.pix_delt_v = vdivd(cam.viewport_v, (double)height);
	cam.viewport_upr_left = vsubv(cam.cam_center,
			vaddv(vaddv(vdivd(cam.viewport_u, 2), vdivd(cam.viewport_v, 2)),
				vmultv((t_vec3){0, 0, cam.focal_length}, w)));
	cam.auf_lock = vaddv(cam.viewport_upr_left,
			vmultd(vaddv(cam.pix_delt_u, cam.pix_delt_v), 0.5));
	return (cam);
}

void	loading(double val, int max)
{
	static double	loaded = 0;

	loaded += val;
	printf("Tracing[");
	printf("%.*s", (int)((loaded / max) * 10), "==========");
	printf("%.*s", 10 - (int)((loaded / max) * 10), "          ");
	printf("]%.0f %%", ((loaded / max) * 100));
}

void	*render_thread(void *args)
{
	t_thread_args	*thread_args;
	t_vec3			aa_color;
	uint32_t		j;
	uint32_t		i;

	thread_args = (t_thread_args *)args;
	j = thread_args->start - 1;
	i = -1;
	while (++j < thread_args->end)
	{
		while (++i < thread_args->window->mlx_image->width)
		{
			aa_color = pixel_sample_square(thread_args->window, i, j);
			mlx_put_pixel(thread_args->window->mlx_image, i,
				j, mlx_color(aa_color));
		}
		i = -1;
		printf("\r");
		loading((double)(thread_args->window->mlx_image->width),
			(thread_args->window->mlx_image->height
				* thread_args->window->mlx_image->width));
		fflush(stdout);
	}
	return (NULL);
}

int	gradient_test(t_window *window)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_args	thread_args[NUM_THREADS];
	uint32_t		start;
	uint32_t		i;

	start = 0;
	i = -1;
	printf("\nTracing[          ]  0 %%");
	while (++i < NUM_THREADS)
	{
		thread_args[i].start = start;
		thread_args[i].end = start + window->mlx_image->height / NUM_THREADS;
		if (i < (window->mlx_image->height % NUM_THREADS))
			thread_args[i].end += 1;
		thread_args[i].window = window;
		pthread_create(&threads[i], NULL, render_thread, &thread_args[i]);
		start = thread_args[i].end;
	}
	i = -1;
	while (++i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
	}
	printf("\rTracing[==========]100 %%\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_window	*window;
	int			width;

	width = 800;
	window = malloc(1 * sizeof(t_window));
	window->aspect_ratio = 16.0 / 9.0;
	if (put_mlx(window, width))
		return (1);
	window->lights = ft_calloc(1, sizeof(t_light));
	window->num_lights = 0;
	window->ambient.brightness = 0;
	window->ambient.color = (t_vec3){0};
	if (!(argc == 2 && !parser(argv[1], window)))
		return (1);
	gradient_test(window);
	mlx_loop_hook(window->mlx_window, key_hook, window->mlx_window);
	mlx_loop(window->mlx_window);
	mlx_terminate(window->mlx_window);
	return (0);
}
