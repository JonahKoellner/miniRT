/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:07:39 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/18 19:20:23 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

typedef struct s_window{
	mlx_t		*mlx_window;
	mlx_image_t	*mlx_image;
	double		aspect_ratio;
	t_camera	camera;
	t_object	*objects;
}	t_window;


int			mlx_color(t_vec3 color);
t_vec3		pixel_sample_square(t_window *window, int i, int j);
t_vec3		ray_color(t_ray r);

#endif
