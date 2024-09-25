/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:13:31 by achater           #+#    #+#             */
/*   Updated: 2024/09/25 14:50:47 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_mini_map(my_mlx_t *mlx)
{
	int i = 0;
	int j = 0;
	double i1;
	double j1;
	double j2;
	double i2;

	i1 = mlx->x - 5 * mlx->block_size;
	j1= mlx->y - 5 * mlx->block_size;
	while(j < 10 * 25)
	{
		i = 0;
		while(i < 10 * 25)
		{
			i2 = i1 + (double)i / 25 * mlx->block_size;
			j2 = j1 + (double)j / 25 * mlx->block_size;
			if (j2 >= 0 && j2 < (double)mlx->rows * mlx->block_size && i2 >= 0 && i2 < (double)mlx->cols * mlx->block_size)
			{
				if (mlx->map[(int)j2 / mlx->block_size][(int)i2 / mlx->block_size] == '1')
					mlx_put_pixel(mlx->img, i, j, ft_pixel(0, 0, 0, 255));
				else
					mlx_put_pixel(mlx->img, i, j, ft_pixel(255, 255, 255, 240));
			}
			else
				mlx_put_pixel(mlx->img, i, j, ft_pixel(128, 128, 128, 255));
			i++;
		}
		j++;
	}
	double x = (mlx->x - i1) / mlx->block_size * 25;
	double y = (mlx->y - j1) / mlx->block_size * 25;

	draw_player(mlx, x, y , 5, ft_pixel(87, 125, 47, 255));
}
