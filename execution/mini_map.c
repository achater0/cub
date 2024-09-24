/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:13:31 by achater           #+#    #+#             */
/*   Updated: 2024/09/24 13:07:38 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_mini_map(my_mlx_t *mlx)
{
	int i = 0;
	int j = 0;
	int i1;
	int j1;
	int j2;
	int i2;

	i1 = mlx->x / mlx->block_size - 5;
	j1= mlx->y / mlx->block_size - 5;
	while(j < 10)
	{
		i = 0;
		while(i < 10)
		{
			i2 = i1 + i;
			j2 = j1 + j;
			if (j2 >= 0 && j2 < (int)mlx->rows && i2 >= 0 && i2 < (int)mlx->cols)
			{
				if (mlx->map[j2][i2] == '1')
					color_the_block(mlx->img, i * 25, j * 25, 25, 25, ft_pixel(0, 0, 0, 255));
				else
					color_the_block(mlx->img, i * 25, j * 25, 25, 25, ft_pixel(255, 255, 255, 255));
			}
			else
				color_the_block(mlx->img, i * 25, j * 25, 25, 25, ft_pixel(128, 128, 128, 255));
			i++;
		}
		j++;
	}
	double x = (mlx->x - i1 * mlx->block_size) / mlx->block_size * 25;
	double y = (mlx->y - j1 * mlx->block_size) / mlx->block_size * 25;

	draw_player(mlx->img, x, y , 3, ft_pixel(255, 0, 0, 255));
}
