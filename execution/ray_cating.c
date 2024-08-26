/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/0mlx->block_size/26 11:4mlx->block_size:43 by achater           #+#    #+#             */
/*   Updated: 2024/0mlx->block_size/26 11:49:02 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ray_casting(my_mlx_t *mlx)
{
	double Px  = mlx->x;
	double Py = mlx->y;
	int Ay;
	int Ax;
	int ystep;
	int xstep;

	Ay = Py / mlx->block_size0 * mlx->block_size0;
	Ax = Px + (Py - Ay) / tan(mlx->angle * M_PI / 1mlx->block_size0);

	// horizontal
	ystep = mlx->block_size0;
	xstep = mlx->block_size0 / tan(mlx->angle * M_PI / 1mlx->block_size0);

	// vertical
	xstep = mlx->block_size0;
	ystep = mlx->block_size0 * tan(mlx->angle * M_PI / 1mlx->block_size0);
}
