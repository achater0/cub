/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:31:42 by achater           #+#    #+#             */
/*   Updated: 2024/09/29 16:23:18 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub.h"

void	open_close_door(my_mlx_t *mlx)
{
	double x;
	double y;
	// double a;
	// double b;
	int i;
	int j;
	// int k;
	// int l;
	int m;
	int n;

	x = mlx->x + 80.0 * cos((mlx->angle) * M_PI / 180);
	y = mlx->y + 80.0 * sin ((mlx->angle) * M_PI / 180);
	// a = mlx->x + 20.0 * cos((mlx->angle) * M_PI / 180);
	// b = mlx->y + 20.0 * sin ((mlx->angle) * M_PI / 180);
	i = (int)(y / mlx->block_size);
	j = (int)(x / mlx->block_size);
	// k = (int)(b / mlx->block_size);
	// l = (int)(a / mlx->block_size);
	m = (int)(mlx->y / mlx->block_size);
	n = (int)(mlx->x / mlx->block_size);
	if (mlx->map[i][j] == 'C')
		mlx->map[i][j] = 'O';
	else if (mlx->map[i][j] == 'O'
		&& (!(mlx->map[m][n] == 'O' && m == i && n == j)))
		// && (!(mlx->map[k][l] == 'O' )))
		mlx->map[i][j] = 'C';
}
