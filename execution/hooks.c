/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:53 by achater           #+#    #+#             */
/*   Updated: 2024/09/05 16:17:27 by achater          ###   ########.fr       */
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

	x = mlx->x + 5.0 * cos(mlx->angle * M_PI / 180);
	y = mlx->y + 5.0 * sin(mlx->angle * M_PI / 180);
	i = (int)(x / mlx->block_size);
	j = (int)(y / mlx->block_size);
	if (mlx->map[i][j] != '1' &&
		mlx->map[(int)(mlx->x / mlx->block_size)][j] != '1' &&
		mlx->map[i][(int)(mlx->y / mlx->block_size)] != '1'
		&& mlx->map[(int)(x+ 10) / mlx->block_size][(int)(y+ 10)/ mlx->block_size] != '1'
		&& mlx->map[(int)(x)/mlx->block_size][(int)(y+ 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x+ 10)/mlx->block_size][(int)(y)/mlx->block_size] != '1'
		&& mlx->map[(int)(x- 10)/mlx->block_size][(int)(y- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x)/mlx->block_size][(int)(y- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x- 10)/mlx->block_size][(int)(y)/mlx->block_size] != '1')
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

	x = mlx->x - 5.0 * cos(mlx->angle * M_PI / 180);
	y = mlx->y - 5.0 * sin(mlx->angle * M_PI / 180);
	i = (int)(x / mlx->block_size);
	j = (int)(y / mlx->block_size);
	if (mlx->map[i][j] != '1' &&
		mlx->map[(int)(mlx->x / mlx->block_size)][j] != '1' &&
		mlx->map[i][(int)(mlx->y / mlx->block_size)] != '1'
		&& mlx->map[(int)(x+ 10) / mlx->block_size][(int)(y+ 10)/ mlx->block_size] != '1'
		&& mlx->map[(int)(x)/mlx->block_size][(int)(y+ 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x+ 10)/mlx->block_size][(int)(y)/mlx->block_size] != '1'
		&& mlx->map[(int)(x- 10)/mlx->block_size][(int)(y- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x)/mlx->block_size][(int)(y- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x- 10)/mlx->block_size][(int)(y)/mlx->block_size] != '1')
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


	x = mlx->x - 5.0 * cos((mlx->angle + 90) * M_PI / 180);
	y = mlx->y - 5.0 * sin((mlx->angle + 90) * M_PI / 180);
	i = (int)(x / mlx->block_size);
	j = (int)(y / mlx->block_size);
	if (mlx->map[i][j] != '1' &&
		mlx->map[(int)(mlx->x / mlx->block_size)][j] != '1' &&
		mlx->map[i][(int)(mlx->y / mlx->block_size)] != '1'
		&& mlx->map[(int)(x+ 10) / mlx->block_size][(int)(y+ 10)/ mlx->block_size] != '1'
		&& mlx->map[(int)(x)/mlx->block_size][(int)(y+ 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x+ 10)/mlx->block_size][(int)(y)/mlx->block_size] != '1'
		&& mlx->map[(int)(x- 10)/mlx->block_size][(int)(y- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x)/mlx->block_size][(int)(y- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x- 10)/mlx->block_size][(int)(y)/mlx->block_size] != '1')
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


	x = mlx->x + 5.0 * cos((mlx->angle + 90) * M_PI / 180);
	y = mlx->y + 5.0 * sin((mlx->angle + 90) * M_PI / 180);
	i = (int)(x / mlx->block_size);
	j = (int)(y / mlx->block_size);
	if (mlx->map[i][j] != '1' &&
		mlx->map[(int)(mlx->x / mlx->block_size)][j] != '1' &&
		mlx->map[i][(int)(mlx->y / mlx->block_size)] != '1'
		&& mlx->map[(int)(x+ 10) / mlx->block_size][(int)(y+ 10)/ mlx->block_size] != '1'
		&& mlx->map[(int)(x)/mlx->block_size][(int)(y+ 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x+ 10)/mlx->block_size][(int)(y)/mlx->block_size] != '1'
		&& mlx->map[(int)(x- 10)/mlx->block_size][(int)(y- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x)/mlx->block_size][(int)(y- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(x- 10)/mlx->block_size][(int)(y)/mlx->block_size] != '1')
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
		move_forward(mlx);
	if (mlx_is_key_down(mlx->mlx, 83))
		move_backward(mlx);
	if (mlx_is_key_down(mlx->mlx, 65))
		move_left(mlx);
	if (mlx_is_key_down(mlx->mlx, 68))
		move_right(mlx);
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, mlx->height, mlx->width);
	draw_mlx(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);

}
