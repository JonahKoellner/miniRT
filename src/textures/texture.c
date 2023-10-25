/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:53:28 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/24 22:44:34 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief Gets the apropriate pixel from a texture at coordinates.
/// @param texture The texture to get the pixel from.
/// @param u The u coordinate of the pixel.
/// @param v The v coordinate of the pixel.
/// @return The color of the pixel at the given coordinates.
t_vec3	texture_get_pixel(t_texture *texture, double u, double v)
{
	int	x;
	int	y;

	x = (int)(u * texture->width) % texture->width;
	y = (int)(v * texture->height) % texture->height;
	return (texture->pixels[y * texture->width + x]);
}

/// @brief Gets the color of a point on an object with (optional)texture.
/// @param object The object to get the color from.
/// @param point The point to get the color from.
/// @return The color of the point on the objects texture.
t_vec3	get_surface_color(t_object *object, t_vec3 point)
{
	t_u_v	uv;

	if (object->mat.bump_color.color)
	{
		uv = get_uv(point);
		return (texture_get_pixel(object->mat.bump_color.color, uv.u, uv.v));
	}
	return (object->mat.color);
}

/// @brief Gets the normal of a point on an object with (optional)bump map.
/// @param object The object to get the normal from.
/// @param point The point to get the normal from.
/// @param normal The normal of the object at the given point.
/// @return The normal of the point on the objects bump map.
t_vec3	get_normal(t_object *object, t_vec3 point, t_vec3 normal)
{
	t_vec3	mat_normal;
	t_vec3	tangent;
	t_vec3	bitangent;
	t_mat4	tangent_to_world;
	t_u_v	uv;

	if (object->mat.bump_color.bump)
	{
		uv = get_uv(point);
		mat_normal = texture_get_pixel(object->mat.bump_color.bump, uv.u, uv.v);
		tangent = cross(normal, (t_vec3){0, 1, 0});
		bitangent = cross(normal, tangent);
		tangent_to_world = (t_mat4){{
		{tangent.x, tangent.y, tangent.z, 0},
		{bitangent.x, bitangent.y, bitangent.z, 0},
		{normal.x, normal.y, normal.z, 0},
		{0, 0, 0, 1}}};
		mat_normal = transform_point(mat_normal, tangent_to_world);
		return (mat_normal);
	}
	return (normal);
}
