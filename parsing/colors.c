/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:29:50 by mstaali           #+#    #+#             */
/*   Updated: 2024/10/17 19:26:30 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	validate_rgb_value(char **rgb)
{
	int	i;

	i = -1;
	while (rgb[++i])
	{
		if (ft_atof(rgb[i]) < 0 || ft_atof(rgb[i]) > 255
			|| ft_atof(rgb[i]) != ft_atoi(rgb[i]))
		{
			ft_dbl_free(rgb);
			error_mssg(COLORS);
		}
	}
}

unsigned int	rgb_to_uint(char *component)
{
	int				i;
	char			**rgb;
	int				count;
	int32_t			color;

	i = -1;
	count = 0;
	while (component[++i])
		if (component[i] == ',')
			count++;
	if (count != 2)
		error_mssg_2(COLORS);
	rgb = ft_split(component, ',');
	if (ft_dbl_strlen(rgb) != 3)
	{
		ft_dbl_free(rgb);
		error_mssg_2(COLORS);
	}
	validate_rgb_value(rgb);
	color = ft_pixel(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 255);
	return (ft_dbl_free(rgb), color);
}
