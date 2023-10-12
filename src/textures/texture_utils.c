/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:53:46 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/12 18:27:21 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_u_v	get_uv(t_vec3 point)
{
	t_u_v	uv;

	uv.u = 0.5 + atan2(point.z, point.x) / (2 * M_PI);
	uv.v = 0.5 - asin(point.y) / M_PI;
	return (uv);
}

t_texture	*load_texture(char *filename)
{
	mlx_texture_t	*data;
	t_texture		*texture;
	size_t			i;

	data = mlx_load_png(filename);
	if (!data)
		return (NULL);
	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (mlx_delete_texture(data), NULL);
	texture->width = data->width;
	texture->height = data->height;
	texture->pixels = ft_calloc(data->width * data->height, sizeof(t_vec3));
	if (!texture->pixels)
		return (free(texture), mlx_delete_texture(data), NULL);
	i = -1;
	while (++i < data->width * data->height)
	{
		texture->pixels[i].x = data->pixels[i * data->bytes_per_pixel];
		texture->pixels[i].y = data->pixels[i * data->bytes_per_pixel + 1];
		texture->pixels[i].z = data->pixels[i * data->bytes_per_pixel + 2];
		texture->pixels[i] = vdivv(texture->pixels[i], (t_vec3){255, 255, 255});
	}
	mlx_delete_texture(data);
	return (texture);
}
