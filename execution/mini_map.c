/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:13:31 by achater           #+#    #+#             */
/*   Updated: 2024/11/01 10:54:31 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_contour(my_mlx_t *mlx, int32_t color)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < (10 * 20))
	{
		k = -1;
		while (++k < 4)
		{
			mlx_put_pixel(mlx->img, i, k, color);
			mlx_put_pixel(mlx->img, i, (10 * 20) - 1 - k, color);
		}
	}
	j = -1;
	while (++j < (10 * 20))
	{
		k = -1;
		while (++k < 4)
		{
			mlx_put_pixel(mlx->img, k, j, color);
			mlx_put_pixel(mlx->img, (10 * 20) - 1 - k, j, color);
		}
	}
}

void	draw_helper(my_mlx_t *mlx, double j1, double i1, int j)
{
	int		i;

	i = -1;
	while (++i < (10 * 20))
	{
		mlx->i2 = i1 + (double)i / 20 * mlx->b_size;
		mlx->j2 = j1 + (double)j / 20 * mlx->b_size;
		if (mlx->j2 >= 0 && mlx->j2 < (double)mlx->rows * mlx->b_size
			&& mlx->i2 >= 0 && mlx->i2 < (double)mlx->cols * mlx->b_size)
		{
			if (mlx->map[(int)mlx->j2 / mlx->b_size]
				[(int)mlx->i2 / mlx->b_size] == '1')
				mlx_put_pixel(mlx->img, i, j, ft_pixel(128, 128, 128, 255));
			else if (mlx->map[(int)mlx->j2 / mlx->b_size]
				[(int)mlx->i2 / mlx->b_size] == 'C')
				mlx_put_pixel(mlx->img, i, j, ft_pixel(170, 30, 30, 255));
			else if (mlx->map[(int)mlx->j2 / mlx->b_size]
				[(int)mlx->i2 / mlx->b_size] == 'O')
				mlx_put_pixel(mlx->img, i, j, ft_pixel(80, 80, 80, 255));
			else
				mlx_put_pixel(mlx->img, i, j, ft_pixel(40, 40, 40, 255));
		}
		else
			mlx_put_pixel(mlx->img, i, j, ft_pixel(20, 20, 20, 255));
	}
}

void	draw_mini_map(my_mlx_t *mlx)
{
	double	i1;
	double	j1;
	double	x;
	double	y;
	int		j;

	j = -1;
	i1 = mlx->x - 5 * mlx->b_size;
	j1 = mlx->y - 5 * mlx->b_size;
	x = 5 * 20;
	y = 5 * 20;
	while (++j < (10 * 20))
		draw_helper(mlx, j1, i1, j);
	draw_player(mlx, x, y, ft_pixel(255, 215, 0, 255));
	draw_contour(mlx, ft_pixel(200, 40, 40, 255));
}
