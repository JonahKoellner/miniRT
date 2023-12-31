/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:07:39 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/27 16:02:28 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

typedef struct s_window{
	mlx_t		*mlx_window;
	mlx_image_t	*mlx_image;
	t_camera	camera;
	t_obj_list	*objects;
	t_light		*lights;
	int			num_lights;
	t_ambient	ambient;
}	t_window;

int			mlx_color(t_vec3 color);
void		key_hook(void *param);
void		loading(double val, int max);
t_vec3		pixel_sample_square(t_window *window, int i, int j);
t_vec3		ray_color(t_ray r, int deph, t_window *window);
t_vec3		light_color(t_hit hit, t_window *window, int i);
double		degrees_to_radians(double degrees);
t_camera	create_ccamera(int width, int height, t_ray	cam_ray, double fov);
void		clean_window(t_window *win);
//texture
t_u_v		get_uv(t_vec3 point);
t_texture	*load_texture(char *filename);
t_vec3		texture_get_pixel(t_texture *texture, double u, double v);
t_vec3		get_surface_color(t_object *object, t_vec3 point);
t_vec3		get_normal(t_object *object, t_vec3 point, t_vec3 normal);

#endif
