/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:12:34 by mstaali           #+#    #+#             */
/*   Updated: 2024/10/10 11:28:18 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_which_texture_side(my_mlx_t *mlx, double ray_x, double ray_y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(ray_x / mlx->b_size);
	grid_y = (int)(ray_y / mlx->b_size);
	if (mlx->is_vertical)
	{
		if (grid_x > mlx->x / mlx->b_size)
			mlx->curr_texture = mlx->texture->ea_tex;
		else
			mlx->curr_texture = mlx->texture->we_tex;
	}
	else
	{
		if (grid_y > mlx->y / mlx->b_size)
			mlx->curr_texture = mlx->texture->so_tex;
		else
			mlx->curr_texture = mlx->texture->no_tex;
	}
}

double	get_text_x(my_mlx_t *mlx, double wall_inter)
{
	double	tex_x;
	double	offset;

	offset = fmod(wall_inter, mlx->b_size);
	tex_x = (offset * mlx->curr_texture->width) / mlx->b_size;
	return (tex_x);
}

double	get_tex_y(my_mlx_t *mlx, double y, double wall_height)
{
	double	tex_y;
	double	wall_y;

	wall_y = y - (( mlx->height / 2) - (wall_height / 2));
	tex_y = (wall_y * mlx->curr_texture->height) / wall_height;
	return (tex_y);
}

unsigned int	get_texture_color(mlx_texture_t *tex, unsigned int x, unsigned int y)
{
	unsigned int	*color;

	color = (unsigned int *)tex->pixels + (((tex->width) * y) + x);
	return (*color);
}

void	adjust_color(mlx_image_t *image, unsigned int x, unsigned int y, unsigned int c)
{
	unsigned int	*color;

	color = (unsigned int *)image->pixels + (((image->width) * y) + x);
	*color = c;
}
