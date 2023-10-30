/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:46:22 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/30 14:22:00 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <pthread.h>

#define WIDTH 800
#define A_X 16.0
#define A_Y 9.0
#define THREADS 12

typedef struct s_thread_args{
	uint32_t	start;
	uint32_t	end;
	t_window	*window;
}	t_thread_args;

/* Single Threaded render function */

//int	render_scene(t_window	*window, int unused)
//{
//	t_vec3		aa_color;
//	uint32_t	j;
//	uint32_t	i;

//	(void)unused;
//	printf("\n");
//	j = 0;
//	while (j < window->mlx_image->height)
//	{
//		i = 0;
//		while (i < window->mlx_image->width)
//		{
//			aa_color = pixel_sample_square(window, i, j);
//			mlx_put_pixel(window->mlx_image, i, j, mlx_color(aa_color));
//			i++;
//		}
//		printf("\r");
//		loading((double)(j * window->mlx_image->width),
//			(window->mlx_image->height * window->mlx_image->width));
//		fflush(stdout);
//		j++;
//	}
//	printf("\r");
//	printf("Tracing[==========]100 %%\n");
//	return (0);
//}

void	*render_thread(void *args)
{
	t_thread_args	*thread_args;
	t_vec3			aa_color;
	uint32_t		j;
	uint32_t		i;

	thread_args = (t_thread_args *)args;
	j = thread_args->start;
	while (j < thread_args->end)
	{
		i = -1;
		while (++i < thread_args->window->mlx_image->width)
		{
			aa_color = pixel_sample_square(thread_args->window, i, j);
			mlx_put_pixel(thread_args->window->mlx_image, i, j,
				mlx_color(aa_color));
		}
		printf("\r");
		loading((double)(thread_args->window->mlx_image->width),
			(thread_args->window->mlx_image->height
				* thread_args->window->mlx_image->width));
		fflush(stdout);
		j++;
	}
	return (NULL);
}

int	render_scene(t_window *window, const uint32_t rows_per_thread)
{
	pthread_t		threads[THREADS];
	t_thread_args	thread_args[THREADS];
	uint32_t		remaining_rows;
	uint32_t		start;
	uint32_t		i;

	start = 0;
	remaining_rows = window->mlx_image->height % THREADS;
	printf("\nTracing[          ]  0 %%");
	i = 0;
	while (i < THREADS)
	{
		thread_args[i].start = start;
		thread_args[i].end = start + rows_per_thread;
		if (i < remaining_rows)
			thread_args[i].end++;
		thread_args[i].window = window;
		pthread_create(&threads[i], NULL, render_thread, &thread_args[i]);
		start = thread_args[i++].end;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(threads[i++], NULL);
	printf("\rTracing[==========]100 %%\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_window	*window;

	window = malloc(1 * sizeof(t_window));
	window->mlx_window = mlx_init(WIDTH, (WIDTH / (A_X / A_Y)), "miniRT", true);
	if (!window->mlx_window)
		return (1);
	window->mlx_image = mlx_new_image(window->mlx_window,
			window->mlx_window->width, window->mlx_window->height);
	if (!window->mlx_image || (mlx_image_to_window(window->mlx_window,
				window->mlx_image, 0, 0) < 0))
		return (1);
	window->lights = ft_calloc(1, sizeof(t_light));
	window->num_lights = 0;
	window->ambient.brightness = 0;
	window->ambient.color = (t_vec3){0};
	if (argc != 2)
		return (1);
	if (parser(argv[1], window))
		return (clean_window(window), 1);
	render_scene(window, window->mlx_image->height / THREADS);
	mlx_loop_hook(window->mlx_window, key_hook, window->mlx_window);
	mlx_loop(window->mlx_window);
	mlx_delete_image(window->mlx_window, window->mlx_image);
	mlx_terminate(window->mlx_window);
	return (clean_window(window), 0);
}
