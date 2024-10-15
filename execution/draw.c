/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:08:58 by achater           #+#    #+#             */
/*   Updated: 2024/10/10 11:37:54 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	initiate_angle_pos(my_mlx_t *mlx)
{
	unsigned int	i;
	unsigned int	j;

	(1) && (i = -1, mlx->hidden = 1);
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
				mlx->x = j * mlx->b_size + mlx->b_size / 2;
				mlx->y = i * mlx->b_size + mlx->b_size / 2;
			}
		}
	}
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	color_the_block(mlx_image_t *img,int i, int j, int width, int height, int color)
{
	int	x;
	int	y;

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

void	draw_player_deriction(my_mlx_t *mlx, int x, int y)
{
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
			mlx_put_pixel(mlx->img, a, b, ft_pixel(178, 255, 255, 220));
			i++;
		}
		angle += step;
	}
}

void	draw_player(my_mlx_t *mlx,int x, int y, int radius, int color)
{
	int	dx = -radius;
	int	dy;

	draw_player_deriction(mlx, x, y);
	while (dx <= radius)
	{
		dy = -radius;
		while (dy <= radius)
		{
			if (dx * dx + dy * dy <= radius * radius)
				mlx_put_pixel(mlx->img, x + dx, y + dy, color);
			dy++;
		}
		dx++;
	}
}

void	draw_sprite(my_mlx_t *mlx, mlx_image_t *sprite_frame, mlx_texture_t *sprite_texture)
{
	int	pos_x;
	int	pos_y;
	int	sprite_w;
	int	sprite_h;
	int x;
	int y;
	int index;

	(void)sprite_frame;
	// mlx_delete_image(mlx->mlx, sprite_frame);
	sprite_w = sprite_texture->width;
	sprite_h = sprite_texture->height;
	pos_x = (mlx->width - sprite_w) / 2;
	pos_y = mlx->height - sprite_h;
	// mlx_image_to_window(mlx->mlx, sprite_frame, pos_x, pos_y);
	x = 0;
	while (x < sprite_w)
	{
		y = 0;
		while (y < sprite_h)
		{
			index = (y * sprite_w + x) * sprite_texture->bytes_per_pixel;
			if (sprite_texture->pixels[index] != 0
				|| sprite_texture->pixels[index + 1] != 0
				|| sprite_texture->pixels[index + 2] != 0
				|| sprite_texture->pixels[index + 3] != 0)
			{
				mlx_put_pixel(mlx->img, pos_x + x, pos_y + y, ft_pixel(sprite_texture->pixels[index],
					sprite_texture->pixels[index + 1], sprite_texture->pixels[index + 2], sprite_texture->pixels[index + 3]));
			}
			y++;
		}
		x++;
	}
}


void draw_mlx(my_mlx_t *mlx)
{
	ray_casting(mlx);
	draw_mini_map(mlx);
}

void	main_fct(my_mlx_t *mlx)
{
	mlx->mlx = mlx_init(mlx->width, mlx->height,"cub3d", 0);
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	initiate_angle_pos(mlx);
	load_sprite_frames(mlx);
	draw_mlx(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	mlx_set_cursor_mode(mlx->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(mlx->mlx, hook_fct, mlx);
	// // mlx_close_window(mlx);
	mlx_loop(mlx->mlx);
	// mlx_terminate(mlx->mlx);
}
