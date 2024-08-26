/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:08:58 by achater           #+#    #+#             */
/*   Updated: 2024/08/26 18:10:38 by achater          ###   ########.fr       */
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
				mlx->x = i * 80 + 40;
				mlx->y = j * 80 + 40;
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
// void draw_pov(my_mlx_t *mlx, int x, int y, double angle, int fov, int color)
// {
// 	double	start_angle = angle - (fov / 2);
// 	double	end_angle = angle + (fov / 2);
// 	double	step = 1;
// 	double	a = start_angle;
// 	double	ray_x;
// 	double	ray_y;
// 	while (a <= end_angle)
// 	{
// 		ray_x = x;
// 		ray_y = y;
// 		while (1)
// 		{
// 			ray_x += cos(a * M_PI / 180);
// 			ray_y += sin(a * M_PI / 180);
// 			if (mlx->map[(int)(ray_x / 80)][(int)(ray_y / 80)] == '1')
// 				break;
// 			mlx_put_pixel(mlx->img, (int)ray_x, (int)ray_y, color);
// 		}
// 		a += step;
// 	}
// }
void draw_pov(my_mlx_t *mlx, int x, int y, double angle, int fov, int color)
{
	double start_angle = angle - (fov / 2);
	double end_angle = angle + (fov / 2);
	double step = (double)fov / 800;
	double a = start_angle;
	int screen_x = 0;
	while (a <= end_angle)
	{
		double ray_x = x;
		double ray_y = y;
		double distance = 0;
		while (1)
		{
		    ray_x += cos(a * M_PI / 180);
		    ray_y += sin(a * M_PI / 180);
		    distance++;
		    if (mlx->map[(int)(ray_x / 80)][(int)(ray_y / 80)] == '1')
		        break;
		}
		double correct_distance = distance * cos((a - angle) * M_PI / 180);
		int wall_height = (int)((80 * 800) / correct_distance);
		int wall_start = (800 / 2) - (wall_height / 2);
		int wall_end = wall_start + wall_height;
		int y = wall_start;
		// int x = 0;
		// while(x < wall_start)
		// {
		//     mlx_put_pixel(mlx->img, screen_x, x, ft_pixel(0, 0, 0, 255));
		//     x++;
		// }
		// x = wall_end;
		// while(x < 780)
		// {
		//     mlx_put_pixel(mlx->img, screen_x, x, ft_pixel(0, 255, 255, 255));
		//     x++;
		// }
		while (y < wall_end)
		{
		    if (y >= 0 && y < 800)
		        mlx_put_pixel(mlx->img, screen_x, y, color);
		    y++;
		}
		a += step;
		screen_x++;
	}
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
	// 			color_the_block(mlx->img, i *80, j * 80, 80, 80, ft_pixel(0, 0, 0, 255));
	// 		else
	// 			color_the_block(mlx->img,i * 80, j * 80, 80, 80, ft_pixel(255, 255, 255, 255));
	// 		j++;
	// 	}
	// 	i++;
	// }
	// draw_player(mlx->img, mlx->x, mlx->y , 10, ft_pixel(255, 0, 0, 255));
	draw_pov(mlx, mlx->x, mlx->y, mlx->angle, 60, ft_pixel(0, 0, 255, 255));
}

void	main_fct(my_mlx_t *mlx)
{

	mlx->mlx = mlx_init(800, 800,"cub3d", 0);
	mlx->img = mlx_new_image(mlx->mlx, 800, 800);
	initiate_angle_pos(mlx);
	draw_mlx(mlx);
	mlx_loop_hook(mlx->mlx, hook_fct, mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	// // mlx_close_window(mlx);
	mlx_loop(mlx->mlx);
	// mlx_terminate(mlx->mlx);
}
