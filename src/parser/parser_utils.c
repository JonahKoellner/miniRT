/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:02:04 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/26 15:46:59 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_strchrn(char *str, char c)
{
	int	index;
	int	ret;

	ret = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			ret++;
		index++;
	}
	return (ret);
}

int	ft_strdnum(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!(str[index] >= '0' && str[index] <= '9') && str[index] != '.' && str[index] != '-'
			&& str[index] != '+')
			{
				return (1);
			}
		index++;
	}
	return (0);
}

int	ft_atov(char *str, t_vec3 *vec)
{
	char	**split;

	split = ft_split(str, ',');
	if (ft_veclen(split) != 3)
		return (1);
	if (ft_strchrn(split[0], '.') > 1 || ft_strchrn(split[1], '.') > 1
		|| ft_strchrn(split[2], '.') > 1)
			return (1);
	if (ft_strdnum(split[0]) || ft_strdnum(split[1]) || ft_strdnum(split[2]))
		return (1);
	vec->x = ft_atof(split[0]);
	vec->y = ft_atof(split[1]);
	vec->z = ft_atof(split[2]);
	ft_vecfree(split);
	return (0);
}

double ft_atof(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	decimal = 0.0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
		result = result * 10.0 + (double)(str[i++] - '0');
	if (str[i] == '.')
	{
		while (str[++i])
			decimal = decimal * 10.0 + (double)(str[i++] - '0');
	}
	while (decimal >= 1.0)
		decimal /= 10.0;
	return sign * (result + decimal);
}
