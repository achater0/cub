/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:02:44 by mstaali           #+#    #+#             */
/*   Updated: 2024/09/30 18:44:19 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_surrounded_by_walls(char **layout)
{
	int	x;
	int	y;
	int	len;

	x = -1;
	len = ft_dbl_strlen(layout);
	while (layout[0][++x])
		if (layout[0][x] != '1' && layout[0][x] != ' ' && layout[0][x] != '\t')
			return (0);
	x = -1;
	while (layout[len - 1][++x])
		if (layout[len - 1][x] != '1' && layout[len - 1][x] != ' ' && layout[len - 1][x] != '\t')
			return (0);
	y = -1;
	while (layout[++y])
	{
		x = 0;
		len = ft_strlen(layout[y]);
		while (layout[y] && layout[y][x] == ' ')
			x++;
		if ((layout[y][x] != '1' && layout[y][x] != ' ' && layout[y][x] != '\t')
			|| (layout[y][len - 1] != '1' && layout[y][len - 1] != ' ' && layout[y][len - 1] != '\t'))
				return (0);
	}
	return (1);
}

int	player_exists(char **layout)
{
	int	i;
	int	j;

	i = 0;
	while (layout[i])
	{
		j = 0;
		while (layout[i][j])
		{
			if (layout[i][j] == 'N' || layout[i][j] == 'W'
				|| layout[i][j] == 'E' || layout[i][j] == 'S')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	door_placement(char **layout, int i, int j)
{
	 if (j <= 0 || j >= (int)ft_strlen(layout[i]) - 1 || i <= 0 || i >= (int)ft_dbl_strlen(layout) - 1)
        return (0);
    if (layout[i][j - 1] == '1' && layout[i][j + 1] == '1')
        return (1);
    if (layout[i - 1][j] == '1' && layout[i + 1][j] == '1')
        return (1);
    return (0);
}

int	is_valid_doors(char **layout)
{
	int	i;
	int	j;

	i = 0;
	while (layout[i])
	{
		j = 0;
		while (layout[i][j])
		{
			if (layout[i][j] == 'O' || layout[i][j] == 'C')
				if (!door_placement(layout, i, j))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
