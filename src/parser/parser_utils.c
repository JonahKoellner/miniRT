/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:02:04 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/28 14:40:37 by jkollner         ###   ########.fr       */
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
		if (!(str[index] >= '0' && str[index] <= '9')
			&& str[index] != '.' && str[index] != '-'
			&& str[index] != '+')
			return (1);
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

double	ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		fractiondigits;
	int		negative;

	negative = 1;
	result = 0.0;
	fraction = 0.0;
	fractiondigits = 0;
	if (*str == '-' && str++)
		negative = -1;
	while (ft_isdigit(*str))
		result = result * 10.0 + (*(str++) - '0');
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			fraction = fraction * 10.0 + (*(str++) - '0');
			fractiondigits++;
		}
	}
	result += fraction / pow(10, fractiondigits);
	return (negative * result);
}
