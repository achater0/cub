/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:31:42 by achater           #+#    #+#             */
/*   Updated: 2024/09/28 14:33:00 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub.h"

void	open_close_door(my_mlx_t *mlx)
{
	double x;
	double y;
	double a;
	double b;

	x = mlx->x + 80.0 * cos((mlx->angle) * M_PI / 180);
	y = mlx->y + 80.0 * sin ((mlx->angle) * M_PI / 180);
	a = mlx->x + 20.0 * cos((mlx->angle) * M_PI / 180);
	b = mlx->y + 20.0 * sin ((mlx->angle) * M_PI / 180);
	if (mlx->map[(int)(y / mlx->block_size)][(int)(x / mlx->block_size)] == 'C')
		mlx->map[(int)(y / mlx->block_size)][(int)(x / mlx->block_size)] = 'O';
	else if (mlx->map[(int)(y / mlx->block_size)][(int)(x / mlx->block_size)] == 'O'
		&& mlx->map[(int)(mlx->y / mlx->block_size)][(int)(mlx->x / mlx->block_size)] != 'O'
		&& mlx->map[(int)(b / mlx->block_size)][(int)(a / mlx->block_size)] != 'O')
		mlx->map[(int)(y / mlx->block_size)][(int)(x / mlx->block_size)] = 'C';
}
