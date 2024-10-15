/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:24:22 by mstaali           #+#    #+#             */
/*   Updated: 2024/10/09 16:12:39 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' 
		|| c == '\v' || c == '\f');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

double	ft_atof(const char *str)
{
	int     i;
	int     sign;
	double  result;
	double  decimal;
	int		decimal_places;

	i = 0;
	sign = 1;
	result = 0;
	decimal = 0;
	decimal_places = 0;
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '.' || str[i] == ','))
	{
		if (str[i] == '.' || str[i] == ',')
		{
			i++;
			while (str[i] && ft_isdigit(str[i]))
			{
				decimal = decimal * 10 + (str[i] - '0');
				decimal_places++;
				i++;
			}
			break;
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	while (decimal_places > 0)
	{
		decimal /= 10;
		decimal_places--;
	}
	return ((result + decimal) * sign);
}
