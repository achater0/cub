/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:11:24 by achater           #+#    #+#             */
/*   Updated: 2024/10/25 10:12:41 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	rotate(my_mlx_t *mlx, int angle)
{
	mlx->angle += angle;
	if (mlx->angle >= 360)
		mlx->angle -= 360;
	if (mlx->angle < 0)
		mlx->angle += 360;
}

int	check_fct(my_mlx_t *mlx, double x, double y)
{
	int	i;
	int	j;

	j = (int)(x / mlx->b_size);
	i = (int)(y / mlx->b_size);
	if (mlx->map[i][j] != '1'
		&& mlx->map[(int)(mlx->y / mlx->b_size)][j] != '1'
		&& mlx->map[i][(int)(mlx->x / mlx->b_size)] != '1'
		&& mlx->map[(int)(y + 10) / mlx->b_size]
			[(int)(x + 10) / mlx->b_size] != '1'
		&& mlx->map[(int)(y) / mlx->b_size][(int)(x + 10) / mlx->b_size] != '1'
		&& mlx->map[(int)(y + 10) / mlx->b_size][(int)(x) / mlx->b_size] != '1'
		&& mlx->map[(int)(y - 10) / mlx->b_size]
			[(int)(x - 10) / mlx->b_size] != '1'
		&& mlx->map[(int)(y) / mlx->b_size][(int)(x - 10) / mlx->b_size] != '1'
		&& mlx->map[(int)(y - 10) / mlx->b_size][(int)(x) / mlx->b_size] != '1')
		return (1);
	return (0);
}

void	move(my_mlx_t *mlx, double angle)
{
	double	y;
	double	x;

	x = mlx->x + 5.0 * cos((mlx->angle + angle) * M_PI / 180);
	y = mlx->y + 5.0 * sin((mlx->angle + angle) * M_PI / 180);
	if (check_fct(mlx, x, mlx->y))
		mlx->x = x;
	if (check_fct(mlx, x, y))
		mlx->y = y;
}

void	hook_fct(void *param)
{
	my_mlx_t	*mlx;
	int			i;

	mlx = (my_mlx_t *)param;
	(mlx_is_key_down(mlx->mlx, 256)) && (mlx_close_window(mlx->mlx), i = -1);
	(mlx_is_key_down(mlx->mlx, 262)) && (rotate(mlx, 2), i = -1);
	(mlx_is_key_down(mlx->mlx, 263)) && (rotate(mlx, -2), i = -1);
	(mlx_is_key_down(mlx->mlx, 87)) && (move(mlx, 0), i = -1);
	(mlx_is_key_down(mlx->mlx, 83)) && (move(mlx, 180), i = -1);
	(mlx_is_key_down(mlx->mlx, 65)) && (move(mlx, 270), i = -1);
	(mlx_is_key_down(mlx->mlx, 68)) && (move(mlx, 90), i = -1);
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	draw_mlx(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
}
