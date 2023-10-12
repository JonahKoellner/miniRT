/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:53:28 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/12 18:31:48 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	texture_get_pixel(t_texture *texture, double u, double v)
{
	int	x;
	int	y;

	x = (int)(u * texture->width) % texture->width;
	y = (int)(v * texture->height) % texture->height;
	return (texture->pixels[y * texture->width + x]);
}

t_vec3	get_surface_color(t_object *object, t_vec3 point)
{
	t_vec3	local_point;
	t_u_v	uv;

	if (object->mat.bump_color.color)
	{
		local_point = transform_point(point, object->transform);
		uv = get_uv(local_point);
		return (texture_get_pixel(object->mat.bump_color.color, uv.u, uv.v));
	}
	return (object->mat.color);
}

t_vec3	get_normal(t_object *object, t_vec3 point, t_vec3 normal)
{
	t_vec3	local_normal;
	t_vec3	tangent;
	t_vec3	bitangent;
	t_mat4	tangent_to_world;
	t_u_v	uv;

	if (object->mat.bump_color.bump)
	{
		uv = get_uv(point);
		local_normal = texture_get_pixel(object->mat.bump_color.bump, uv.u, uv.v);
		tangent = cross(normal, (t_vec3){0, 1, 0});
		bitangent = cross(normal, tangent);
		tangent_to_world = (t_mat4){{
		{tangent.x, tangent.y, tangent.z, 0},
		{bitangent.x, bitangent.y, bitangent.z, 0},
		{normal.x, normal.y, normal.z, 0},
		{0, 0, 0, 1}}};
		local_normal = transform_point(local_normal, tangent_to_world);
		return (local_normal);
	}
	return (normal);
}
