/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:08:58 by achater           #+#    #+#             */
/*   Updated: 2024/09/09 11:44:41 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void initiate_angle_pos(my_mlx_t *mlx)
{
	int i;
	int j;

	i = -1;
	while(++i < 10)
	{
		j = -1;
		while(++j < 10)
		{
			if (mlx->map[i][j] == 'N')
				mlx->angle = 270;
			else if (mlx->map[i][j] == 'E')
				mlx->angle = 0;
			else if (mlx->map[i][j] == 'S')
				mlx->angle = 90;
			else if (mlx->map[i][j] == 'W')
				mlx->angle = 180;
			if (mlx->map[i][j] == 'N' || mlx->map[i][j] == 'E'
				|| mlx->map[i][j] == 'S' || mlx->map[i][j] == 'W')
			{
				mlx->x = i * mlx->block_size + mlx->block_size / 2;
				mlx->y = j * mlx->block_size + mlx->block_size / 2;
			}
		}
	}
}


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void color_the_block(mlx_image_t *img,int i, int j, int width, int height, int color)
{
	int x;
	int y;

	x = i;
	while (x < i + width - 1)
	{
		y = j;
		while (y < j + height - 1)
		{
			mlx_put_pixel(img,x, y, color);
			y++;
		}
		x++;
	}
}

void draw_player(mlx_image_t *img,int x, int y, int radius, int color)
{
	int	cx = x;
	int	cy = y;
	int	dx = -radius;
	int	dy;

	while (dx <= radius)
	{
		dy = -radius;
		while (dy <= radius)
		{
			if (dx * dx + dy * dy <= radius * radius)
				mlx_put_pixel(img, cx + dx, cy + dy, color);
			dy++;
		}
		dx++;
	}
	if (radius == 10)
		draw_player(img,x, y, 1, ft_pixel(0, 255, 0, 255));
}



void draw_mlx(my_mlx_t *mlx)
{
	// int i;
	// int j;

	// i = 0;
	// while(i < 10)
	// {
	// 	j = 0;
	// 	while(j < 10)
	// 	{
	// 		if (mlx->map[i][j] == '1')
	// 			color_the_block(mlx->img, i *mlx->block_size, j * mlx->block_size
	// 				, mlx->block_size, mlx->block_size, ft_pixel(0, 0, 0, 255));
	// 		else
	// 			color_the_block(mlx->img,i * mlx->block_size, j * mlx->block_size
	// 				, mlx->block_size, mlx->block_size, ft_pixel(255, 255, 255, 255));
	// 		j++;
	// 	}
	// 	i++;
	// }
	// draw_player(mlx->img, mlx->x, mlx->y , 10, ft_pixel(255, 0, 0, 255));
	ray_casting(mlx);
}

void	main_fct(my_mlx_t *mlx)
{
	mlx->mlx = mlx_init(mlx->height, mlx->width,"cub3d", 0);
	mlx->img = mlx_new_image(mlx->mlx, mlx->height, mlx->width);
	initiate_angle_pos(mlx);
	draw_mlx(mlx);
	mlx_loop_hook(mlx->mlx, hook_fct, mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	// // mlx_close_window(mlx);
	mlx_loop(mlx->mlx);
	// mlx_terminate(mlx->mlx);
}
