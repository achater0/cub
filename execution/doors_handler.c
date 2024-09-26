/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:31:42 by achater           #+#    #+#             */
/*   Updated: 2024/09/26 15:35:57 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub.h"

void	open_close_door(my_mlx_t *mlx)
{
	double x;
	double y;

	x = mlx->x + 5.0 * cos((mlx->angle) * M_PI / 180);
	y = mlx->y + 5.0 * sin ((mlx->angle) * M_PI / 180);

	if (mlx->map[(int)(y / mlx->block_size)][(int)(x / mlx->block_size)] == 'C')
		mlx->map[(int)(y / mlx->block_size)][(int)(x / mlx->block_size)] = 'O';
	else if (mlx->map[(int)(y / mlx->block_size)][(int)(x / mlx->block_size)] == 'O')
		mlx->map[(int)(y / mlx->block_size)][(int)(x / mlx->block_size)] = 'C';
}
