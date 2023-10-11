/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:17:05 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/12 00:30:36 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

typedef struct s_u_v
{
	double	u;
	double	v;
}	t_u_v;

typedef struct s_texture
{
	int		width;
	int		height;
	t_vec3	*pixels;
}	t_texture;

typedef struct s_bump_color
{
	t_texture	*color;
	t_texture	*bump;
}	t_bump_color;

#endif