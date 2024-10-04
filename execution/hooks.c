/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:53 by achater           #+#    #+#             */
/*   Updated: 2024/10/04 12:04:44 by achater          ###   ########.fr       */
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

int check_fct(my_mlx_t *mlx, double x, double y)
{
	int i;
	int j;

	j = (int)(x / mlx->block_size);
	i = (int)(y / mlx->block_size);
	if (mlx->map[i][j] != '1' && mlx->map[i][j] != 'C'
		&& mlx->map[(int)(mlx->y / mlx->block_size)][j] != '1'
		&& mlx->map[i][(int)(mlx->x / mlx->block_size)] != '1'
		&& mlx->map[(int)(y+ 10) / mlx->block_size][(int)(x+ 10)/ mlx->block_size] != '1'
		&& mlx->map[(int)(y)/mlx->block_size][(int)(x+ 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(y+ 10)/mlx->block_size][(int)(x)/mlx->block_size] != '1'
		&& mlx->map[(int)(y- 10)/mlx->block_size][(int)(x- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(y)/mlx->block_size][(int)(x- 10)/mlx->block_size] != '1'
		&& mlx->map[(int)(y- 10)/mlx->block_size][(int)(x)/mlx->block_size] != '1')
		return (1);
	return (0);
}

void move(my_mlx_t *mlx, double angle)
{
	double y;
	double x;

	x = mlx->x + 5.0 * cos((mlx->angle + angle) * M_PI / 180);
	y = mlx->y + 5.0 * sin((mlx->angle + angle) * M_PI / 180);
	if (check_fct(mlx, x, mlx->y))
		mlx->x = x;
	if (check_fct(mlx, x, y))
		mlx->y = y;
}

void	key_fct(struct mlx_key_data key, void *param)
{
	my_mlx_t *mlx;

	mlx = (my_mlx_t *)param;
	if (key.key == MLX_KEY_P && key.action == MLX_RELEASE)
	{
		if (mlx->hidden == 0)
		{
			mlx_set_cursor_mode(mlx->mlx, MLX_MOUSE_HIDDEN);
			mlx->hidden = 1;
		}
		else
		{
			mlx_set_cursor_mode(mlx->mlx, MLX_MOUSE_NORMAL);
			mlx->hidden = 0;
		}
	}
	if (key.key == MLX_KEY_SPACE && key.action == MLX_RELEASE)
		open_close_door(mlx);
}

// void	animate_sprite(my_mlx_t *mlx)
// {
// 	double	curr_time;

// 	if (mlx->is_animated == 0)
//         return ;
// 	curr_time = mlx_get_time();
//     if (curr_time - mlx->last_frame_time >= 0.5)
//     {
// 		mlx_set_instance_depth(&mlx->sprite_frames[mlx->curr_frame]->instances[0], -1);
// 		mlx->curr_frame = (mlx->curr_frame + 1) % mlx->num_frames;
// 		mlx->last_frame_time = curr_time;
// 		mlx_set_instance_depth(&mlx->sprite_frames[mlx->curr_frame]->instances[0], 0);
// 		if (mlx->curr_frame == 0)
// 			mlx->is_animated = 0;
//     }
// }

void mouse_hook(my_mlx_t *mlx)
{
	int x;
	int y;

	mlx_get_mouse_pos(mlx->mlx, &x, &y);
	if (mlx->hidden)
	{
		mlx_set_mouse_pos(mlx->mlx, mlx->width / 2, mlx->height / 2);
		if (x < 0 || x > mlx->width)
			return ;
		mlx->angle -= (mlx->width / 2 - x) * 180 / mlx->width / 3;
		normalize_angle(&mlx->angle);
	}
	// if (mlx_is_mouse_down(mlx->mlx, MLX_MOUSE_BUTTON_RIGHT))
    // {
	// 	mlx->is_animated = 1;
	// 	mlx->curr_frame = 0;
	// 	mlx->last_frame_time = mlx_get_time();
    // }
	mlx_key_hook(mlx->mlx, key_fct, mlx);
}

void hook_fct(void *param)
{
	my_mlx_t 	*mlx;

	mlx = (my_mlx_t *)param;
	mouse_hook(mlx);
	if (mlx_is_key_down(mlx->mlx, 256))
		mlx_close_window(mlx->mlx);
	if (!mlx->hidden)
		return ;
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
	mlx_key_hook(mlx->mlx, key_fct, mlx);
	// animate_sprite(mlx);

	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	draw_mlx(mlx);
	animate_sprite(mlx);
	draw_sprite(mlx, mlx->sprite_frames[mlx->curr_frame], mlx->sprite_textures[mlx->curr_frame]);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
}
