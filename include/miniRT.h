/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:47:08 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/18 14:38:42 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../src/utils/vec3/vec3.h"
# include "../src/utils/ray/ray.h"
# include "../src/elements/elements.h"
# include "../src/hit/hit.h"
# include "../src/src.h"

typedef struct s_camera{
	double	viewport_height;
	double	focal_length;
	double	viewport_width;
	t_vec3	cam_center;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	pix_delt_u;
	t_vec3	pix_delt_v;
	t_vec3	viewport_upr_left;
	t_vec3	auf_lock;
}	t_camera;

typedef struct s_window{
	mlx_t		*mlx_window;
	mlx_image_t	*mlx_image;
	double		aspect_ratio;
	t_camera	camera;
}	t_window;

#endif
