/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:07:39 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/28 18:28:53 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# define BACK_COL_R 0
# define BACK_COL_G 0
# define BACK_COL_B 0

typedef struct s_window{
	mlx_t		*mlx_window;
	mlx_image_t	*mlx_image;
	double		aspect_ratio;
	t_camera	camera;
	t_obj_list	*objects;
	t_light		*lights;
	int			num_lights;
}	t_window;


int			mlx_color(t_vec3 color);
t_vec3		pixel_sample_square(t_window *window, int i, int j);
t_vec3		ray_color(t_ray r, int deph, t_window *window);
t_vec3		light_color(t_hit hit, t_window *window, int i);

#endif
