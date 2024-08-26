/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:53 by achater           #+#    #+#             */
/*   Updated: 2024/08/26 19:03:24 by achater          ###   ########.fr       */
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

void move_forward(my_mlx_t *mlx)
{
	double y;
	double x;
	int i;
	int j;

	x = mlx->x + 1.8 * cos(mlx->angle * M_PI / 180);
	y = mlx->y + 1.8 * sin(mlx->angle * M_PI / 180);
	i = (int)(x / 80);
	j = (int)(y / 80);
	if (mlx->map[i][j] != '1' &&
		mlx->map[(int)(mlx->x / 80)][j] != '1' &&
		mlx->map[i][(int)(mlx->y / 80)] != '1')
	{
		mlx->x = x;
		mlx->y = y;
	}
}

void move_backward(my_mlx_t *mlx)
{
	double y;
	double x;
	int i;
	int j;

	x = mlx->x - 1.8 * cos(mlx->angle * M_PI / 180);
	y = mlx->y - 1.8 * sin(mlx->angle * M_PI / 180);
	i = (int)(x / 80);
	j = (int)(y / 80);
	if (mlx->map[i][j] != '1' &&
		mlx->map[(int)(mlx->x / 80)][j] != '1' &&
		mlx->map[i][(int)(mlx->y / 80)] != '1')
	{
		mlx->x = x;
		mlx->y = y;
	}
}

void move_left(my_mlx_t *mlx)
{
	double y;
	double x;
	int i;
	int j;


	x = mlx->x - 1.8 * cos((mlx->angle + 90) * M_PI / 180);
	y = mlx->y - 1.8 * sin((mlx->angle + 90) * M_PI / 180);
	i = (int)(x / 80);
	j = (int)(y / 80);
	if (mlx->map[i][j] != '1' &&
		mlx->map[(int)(mlx->x / 80)][j] != '1' &&
		mlx->map[i][(int)(mlx->y / 80)] != '1')
	{
		mlx->x = x;
		mlx->y = y;
	}
}

void move_right(my_mlx_t *mlx)
{
	double y;
	double x;
	int i;
	int j;


	x = mlx->x + 1.8 * cos((mlx->angle + 90) * M_PI / 180);
	y = mlx->y + 1.8 * sin((mlx->angle + 90) * M_PI / 180);
	i = (int)(x / 80);
	j = (int)(y / 80);
	if (mlx->map[i][j] != '1' &&
		mlx->map[(int)(mlx->x / 80)][j] != '1' &&
		mlx->map[i][(int)(mlx->y / 80)] != '1')
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
		rotate(mlx, 3);
	if (mlx_is_key_down(mlx->mlx, 263))
		rotate(mlx, -3);
	if (mlx_is_key_down(mlx->mlx, 87))
		move_forward(mlx);
	if (mlx_is_key_down(mlx->mlx, 83))
		move_backward(mlx);
	if (mlx_is_key_down(mlx->mlx, 65))
		move_left(mlx);
	if (mlx_is_key_down(mlx->mlx, 68))
		move_right(mlx);
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, 800, 800);
	draw_mlx(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);

}
