/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:11:26 by mstaali           #+#    #+#             */
/*   Updated: 2024/10/23 13:33:01 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	fill_frame_paths(mlx_texture_t **sprite_textures)
{
	sprite_textures[0] = mlx_load_png("assets/init_state_g.png");
	if (!sprite_textures[0])
		error_mssg_2(FRAMES);
	sprite_textures[1] = mlx_load_png("assets/animate_1_g.png");
	if (!sprite_textures[1])
		error_mssg_2(FRAMES);
	sprite_textures[2] = mlx_load_png("assets/animate_2_g.png");
	if (!sprite_textures[2])
		error_mssg_2(FRAMES);
	sprite_textures[3] = mlx_load_png("assets/animate_3_g.png");
	if (!sprite_textures[3])
		error_mssg_2(FRAMES);
	sprite_textures[4] = mlx_load_png("assets/animate_4_g.png");
	if (!sprite_textures[4])
		error_mssg_2(FRAMES);
	sprite_textures[5] = mlx_load_png("assets/animate_5_g.png");
	if (!sprite_textures[5])
		error_mssg_2(FRAMES);
	sprite_textures[6] = mlx_load_png("assets/animate_6_g.png");
	if (!sprite_textures[6])
		error_mssg_2(FRAMES);
}

void	load_sprite_frames(my_mlx_t *mlx)
{
	int	i;

	mlx->num_frames = 7;
	mlx->curr_frame = 0;
	mlx->is_animated = 0;
	mlx->last_frame_time = mlx_get_time();
	mlx->sprite_textures = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *)
			* mlx->num_frames);
	if (!mlx->sprite_textures)
		error_mssg_2(FRAMES);
	fill_frame_paths(mlx->sprite_textures);
	mlx->sprite_frames = (mlx_image_t **)malloc(sizeof(mlx_image_t *)
			* mlx->num_frames);
	if (!mlx->sprite_frames)
		error_mssg_2(FRAMES);
	i = -1;
	while (++i < mlx->num_frames)
	{
		mlx->sprite_frames[i] = mlx_texture_to_image(mlx->mlx,
				mlx->sprite_textures[i]);
		if (!mlx->sprite_frames[i])
			error_mssg_2(FRAMES);
	}
}

void	animation_process(my_mlx_t *mlx, double current_time)
{
	current_time = mlx_get_time();
	if (current_time - mlx->last_frame_time >= 0.04)
	{
		if (mlx->sprite_frames[mlx->curr_frame])
			mlx_delete_image(mlx->mlx, mlx->sprite_frames[mlx->curr_frame]);
		mlx->curr_frame++;
		if (mlx->curr_frame >= mlx->num_frames)
		{
			mlx->curr_frame = 0;
			mlx->is_animated = 0;
		}
		mlx->sprite_frames[mlx->curr_frame] = mlx_texture_to_image(mlx->mlx,
				mlx->sprite_textures[mlx->curr_frame]);
		draw_sprite(mlx, mlx->sprite_textures[mlx->curr_frame], -1, -1);
		mlx->last_frame_time = current_time;
	}
}

void	animate_sprite(my_mlx_t *mlx)
{
	static int	last_state;
	int			curr_state;
	double		current_time;

	current_time = 0.0;
	last_state = 0;
	curr_state = mlx_is_mouse_down(mlx->mlx, MLX_MOUSE_BUTTON_RIGHT);
	if (curr_state && !last_state && !mlx->is_animated)
	{
		mlx->is_animated = 1;
		mlx->curr_frame = 0;
		mlx->last_frame_time = mlx_get_time();
	}
	last_state = curr_state;
	if (mlx->is_animated)
		animation_process(mlx, current_time);
}
