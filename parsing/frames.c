/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:11:26 by mstaali           #+#    #+#             */
/*   Updated: 2024/10/01 18:29:37 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	fill_frame_paths(my_mlx_t *mlx)
{
	mlx->frames->tex_init_state = mlx_load_png("assets/init_state.png");
	if (!mlx->frames->tex_init_state)
		error_mssg(FRAMES);
	mlx->frames->tex_animate_1 = mlx_load_png("assets/animate_1.png");
	if (!mlx->frames->tex_animate_1)
		error_mssg(FRAMES);
	mlx->frames->tex_animate_2 = mlx_load_png("assets/animate_2.png");
	if (!mlx->frames->tex_animate_2)
		error_mssg(FRAMES);
	mlx->frames->tex_animate_3 = mlx_load_png("assets/animate_3.png");
	if (!mlx->frames->tex_animate_3)
		error_mssg(FRAMES);
	mlx->frames->tex_animate_4 = mlx_load_png("assets/animate_4.png");
	if (!mlx->frames->tex_animate_4)
		error_mssg(FRAMES);
	mlx->frames->tex_animate_5 = mlx_load_png("assets/animate_5.png");
	if (!mlx->frames->tex_animate_5)
		error_mssg(FRAMES);
	mlx->frames->tex_animate_6 = mlx_load_png("assets/animate_6.png");
	if (!mlx->frames->tex_animate_6)
		error_mssg(FRAMES);
}

void	load_sprite_frames(my_mlx_t *mlx)
{
	mlx->frames = (t_frame *)malloc(sizeof(t_frame));
	if (!mlx->frames)
	{
		error_mssg(FRAMES);
	}
	fill_frame_paths(mlx);
	mlx->frames->init_state = mlx_texture_to_image(mlx->mlx, mlx->frames->tex_init_state);
	mlx->frames->animate_1 = mlx_texture_to_image(mlx->mlx, mlx->frames->tex_animate_1);
	mlx->frames->animate_2 = mlx_texture_to_image(mlx->mlx, mlx->frames->tex_animate_2);
	mlx->frames->animate_3 = mlx_texture_to_image(mlx->mlx, mlx->frames->tex_animate_3);
	mlx->frames->animate_4 = mlx_texture_to_image(mlx->mlx, mlx->frames->tex_animate_4);
	mlx->frames->animate_5 = mlx_texture_to_image(mlx->mlx, mlx->frames->tex_animate_5);
	mlx->frames->animate_6 = mlx_texture_to_image(mlx->mlx, mlx->frames->tex_animate_6);
}
