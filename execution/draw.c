/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:08:58 by achater           #+#    #+#             */
/*   Updated: 2024/09/27 17:57:21 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void initiate_angle_pos(my_mlx_t *mlx)
{
	unsigned int i;
	unsigned int j;

	i = -1;
	mlx->hidden = 1;
	while(++i < mlx->rows)
	{
		j = -1;
		while(++j < mlx->cols)
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
				mlx->x = j * mlx->block_size + mlx->block_size / 2;
				mlx->y = i * mlx->block_size + mlx->block_size / 2;
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

void draw_player(my_mlx_t *mlx,int x, int y, int radius, int color)
{
	int	cx = x;
	int	cy = y;
	int	dx = -radius;
	int	dy;
	double start_angle;
	double step;
	double angle;
	int i ;
	double a;
	double b;

	start_angle = mlx->angle - 30;
	step = 1;
	angle = start_angle;
	while(angle < 60 + start_angle)
	{
		i = 0;
		a = x;
		b = y;
		while(i < 25)
		{
			a += cos(angle * M_PI / 180);
			b += sin(angle * M_PI / 180);
			mlx_put_pixel(mlx->img, a, b, ft_pixel(205, 205, 180, 255));
			i++;
		}
		angle += step;
	}
	while (dx <= radius)
	{
		dy = -radius;
		while (dy <= radius)
		{
			if (dx * dx + dy * dy <= radius * radius)
				mlx_put_pixel(mlx->img, cx + dx, cy + dy, color);
			dy++;
		}
		dx++;
	}
}



void draw_mlx(my_mlx_t *mlx)
{
	// unsigned int i;
	// unsigned int j;

	// i = 0;
	// while(i < mlx->rows)
	// {
	// 	j = 0;
	// 	while(j < mlx->cols)
	// 	{
	// 		if (mlx->map[i][j] == '1')
	// 			color_the_block(mlx->img, j *mlx->block_size, i * mlx->block_size
	// 				, mlx->block_size, mlx->block_size, ft_pixel(0, 0, 0, 255));
	// 		else if (mlx->map[i][j] == '0' || mlx->map[i][j] == 'N'
	// 			|| mlx->map[i][j] == 'E' || mlx->map[i][j] == 'S'
	// 				|| mlx->map[i][j] == 'W')
	// 			color_the_block(mlx->img,j * mlx->block_size, i * mlx->block_size
	// 				, mlx->block_size, mlx->block_size, ft_pixel(255, 255, 255, 255));
	// 		j++;
	// 	}
	// 	i++;
	// }
	// draw_player(mlx->img, mlx->x, mlx->y , 10, ft_pixel(255, 0, 0, 255));
	ray_casting(mlx);
	draw_mini_map(mlx);
}

void	main_fct(my_mlx_t *mlx)
{
	mlx->mlx = mlx_init(mlx->width, mlx->height,"cub3d", 0);
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	initiate_angle_pos(mlx);
	draw_mlx(mlx);
	mlx_set_cursor_mode(mlx->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(mlx->mlx, hook_fct, mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	// // mlx_close_window(mlx);
	mlx_loop(mlx->mlx);
	// mlx_terminate(mlx->mlx);
}
