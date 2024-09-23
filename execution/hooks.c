/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:53 by achater           #+#    #+#             */
/*   Updated: 2024/09/22 16:03:46 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


void rotate(my_mlx_t *mlx, int angle)
{
	mlx->angle += angle;
	if (mlx->angle >= 360)
		mlx->angle -= 360;
	if (mlx->angle < 0)
		mlx->angle += 360;
}

void move(my_mlx_t *mlx, double angle)
{
	double y;
	double x;
	int i;
	int j;

	x = mlx->x + 5.0 * cos((mlx->angle + angle) * M_PI / 180);
	y = mlx->y + 5.0 * sin((mlx->angle + angle) * M_PI / 180);
	j = (int)(x / mlx->block_size);
	i = (int)(y / mlx->block_size);
	if (mlx->map[i][j] != '1' &&
		mlx->map[(int)(mlx->y / mlx->block_size)][j] != '1' &&
		mlx->map[i][(int)(mlx->x / mlx->block_size)] != '1'
		&& mlx->map[(int)(y+ 10) / mlx->block_size][(int)(x+ 10)/ mlx->block_size] != '1'
		&& mlx->map[(int)(y)/mlx->block_size][(int)(x+ 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(y+ 10)/mlx->block_size][(int)(x)/mlx->block_size] != '1'
		&& mlx->map[(int)(y- 10)/mlx->block_size][(int)(x- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(y)/mlx->block_size][(int)(x- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(y- 10)/mlx->block_size][(int)(x)/mlx->block_size] != '1')
	{
		mlx->x = x;
		mlx->y = y;
	}
}
void hook_fct(void *param)
{
	my_mlx_t *mlx;

	mlx = (my_mlx_t *)param;
	if (mlx_is_key_down(mlx->mlx, 256))
		mlx_close_window(mlx->mlx);
	if (mlx_is_key_down(mlx->mlx, 262))
		rotate(mlx, 2);
	if (mlx_is_key_down(mlx->mlx, 263))
		rotate(mlx, -2);
	if (mlx_is_key_down(mlx->mlx, 87))
		move(mlx, 0);
	if (mlx_is_key_down(mlx->mlx, 83))
		move(mlx, 180);
	if (mlx_is_key_down(mlx->mlx, 65))
		move(mlx, 270);
	if (mlx_is_key_down(mlx->mlx, 68))
		move(mlx, 90);
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, mlx->height, mlx->width);
	draw_mlx(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);

}
