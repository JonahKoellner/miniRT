/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:30:12 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/27 12:10:19 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	key_hook(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

/// @brief Cr
/// @param width
/// @param height
/// @param cam_ray
/// @param fov
/// @return
t_camera	create_ccamera(int width, int height, t_ray	cam_ray, double fov)
{
	t_camera	camera;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;

	w = negate(unitv(cam_ray.direction));
	u = unitv(cross((t_vec3){0, 1, 0}, w));
	v = negate(cross(u, w));
	camera.viewport_height = 2 * tan(degrees_to_radians(fov) / 2);
	camera.focal_length = 1;
	camera.viewport_width = camera.viewport_height
		* ((double)(width) / height);
	camera.cam_center = cam_ray.origin;
	camera.viewport_u = vmultv((t_vec3){camera.viewport_width, 0, 0}, u);
	camera.viewport_v = vmultv((t_vec3){0, -camera.viewport_height, 0}, v);
	camera.pix_delt_u = vdivd(camera.viewport_u, (double)width);
	camera.pix_delt_v = vdivd(camera.viewport_v, (double)height);
	camera.viewport_upr_left = vsubv(camera.cam_center, vaddv
			(vaddv(vdivd(camera.viewport_u, 2), vdivd(camera.viewport_v, 2)),
				vmultv((t_vec3){0, 0, camera.focal_length}, w)));
	camera.auf_lock = vaddv(camera.viewport_upr_left, vmultd
			(vaddv(camera.pix_delt_u, camera.pix_delt_v), 0.5));
	return (camera);
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
