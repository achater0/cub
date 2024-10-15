/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:13:31 by achater           #+#    #+#             */
/*   Updated: 2024/10/10 11:28:18 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_contour(my_mlx_t *mlx)
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
            mlx_put_pixel(mlx->img, i, k, ft_pixel(62, 95, 138, 255));
            mlx_put_pixel(mlx->img, i, (10 * 20) - 1 - k, ft_pixel(62, 95, 138, 255));
        }
	}
	j = -1;
    while (++j < (10 * 20))
	{
		k = -1;
        while (++k < 4)
        {
            mlx_put_pixel(mlx->img, k, j, ft_pixel(62, 95, 138, 255));
            mlx_put_pixel(mlx->img, (10 * 20) - 1 - k, j, ft_pixel(62, 95, 138, 255));
        }
	}
}

void	draw_mini_map(my_mlx_t *mlx)
{
	int i = 0;
	int j = 0;
	double i1;
	double j1;
	double j2;
	double i2;

	i1 = mlx->x - 5 * mlx->b_size;
	j1= mlx->y - 5 * mlx->b_size;
	while(j < 10 * 20)
	{
		i = 0;
		while(i < 10 * 20)
		{
			i2 = i1 + (double)i / 20 * mlx->b_size;
			j2 = j1 + (double)j / 20 * mlx->b_size;
			if (j2 >= 0 && j2 < (double)mlx->rows * mlx->b_size && i2 >= 0 && i2 < (double)mlx->cols * mlx->b_size)
			{
				if (mlx->map[(int)j2 / mlx->b_size][(int)i2 / mlx->b_size] == '1')
					mlx_put_pixel(mlx->img, i, j, ft_pixel(147, 190, 222, 255));
				else if (mlx->map[(int)j2 / mlx->b_size][(int)i2 / mlx->b_size] == 'C')
					mlx_put_pixel(mlx->img, i, j, ft_pixel(86, 108, 134, 255));
				else if (mlx->map[(int)j2 / mlx->b_size][(int)i2 / mlx->b_size] == 'O')
					mlx_put_pixel(mlx->img, i, j, ft_pixel(202, 235, 255, 255));
				else
					mlx_put_pixel(mlx->img, i, j, ft_pixel(230, 245, 255, 255));
			}
			else
				mlx_put_pixel(mlx->img, i, j, ft_pixel(48, 65, 88, 255));
			i++;
		}
		j++;
	}
	double x = (mlx->x - i1) / mlx->b_size * 20;
	double y = (mlx->y - j1) / mlx->b_size * 20;

	draw_player(mlx, x, y , 5, ft_pixel(0, 195, 255, 255));
    draw_contour(mlx);
}
