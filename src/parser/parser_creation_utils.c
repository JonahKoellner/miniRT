/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_creation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:14:22 by jkollner          #+#    #+#             */
/*   Updated: 2023/10/27 12:10:04 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vec3	fill_vec(char *subj, int *map, double min, double max)
{
	t_vec3	ret;

	if (ft_atov(subj, &ret))
		return (map[OBJ_ERROR]++, (t_vec3){});
	if ((ret.x > max || ret.x < min) || (ret.y > max || ret.y < min)
		|| (ret.z > max || ret.z < min))
		return (map[OBJ_ERROR]++, (t_vec3){});
	if (min == 0 && max == 255)
		ret = vdivv(ret, (t_vec3){255, 255, 255});
	return (ret);
}

int	num_color(char *subj)
{
	int	index;

	index = 0;
	while (subj[index])
	{
		if (!(subj[index] >= '0' && subj[index] <= '9')
			&& subj[index] != '.' && subj[index] != ',')
			return (1);
		index++;
	}
	return (0);
}

t_bump_color	fill_bumpmap(char *file_color, char *file_bump)
{
	t_bump_color	ret;
	char			*path_color;
	char			*path_bump;

	if (file_color == NULL || file_bump == NULL)
	{
		ret.bump = NULL;
		ret.color = NULL;
		return (ret);
	}
	path_color = ft_strjoin("src/textures/maps/", file_color);
	path_bump = ft_strjoin("src/textures/maps/", file_bump);
	ret.color = load_texture(path_color);
	ret.bump = load_texture(path_bump);
	free(path_bump);
	free(path_color);
	return (ret);
}

double	fill_double(char *subj, int *map, double min, double max)
{
	double	ret;

	ret = ft_atof(subj);
	if (min == INFINITY || min == -INFINITY)
	{
		if (max == INFINITY || max == -INFINITY)
			return (ret);
		if (ret <= max)
			return (ret);
		return (map[OBJ_ERROR]++, -1);
	}
	if (max == INFINITY || max == -INFINITY)
	{
		if (ret >= min)
			return (ret);
		return (map[OBJ_ERROR]++, -1);
	}
	if (ret < min || ret > max)
		return (map[OBJ_ERROR]++, -1);
	return (ret);
}

t_MaterialType	fill_material(char *subj, int *map)
{
	if (!ft_strncmp("metal", subj, 5))
		return (METAL);
	else if (!ft_strncmp("lambertian", subj, 10))
		return (LAMBERTIAN);
	else if (!ft_strncmp("plastic", subj, 7))
		return (PLASTIC);
	else if (!ft_strncmp("dielectric", subj, 10))
		return (DIELECTRIC);
	else
		return (map[OBJ_ERROR]++, -1);
}
