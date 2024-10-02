/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:58:19 by mstaali           #+#    #+#             */
/*   Updated: 2024/09/30 18:00:26 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_texture(t_texture *texture)
{
	texture->no = NULL;
	texture->so = NULL;
	texture->we = NULL;
	texture->ea = NULL;
	texture->door = NULL;
	texture->c_clr = 0;	
	texture->f_clr = 0;
}

int	is_valid_texture(char *component)
{
	if (!ft_strcmp(component, "NO") || !ft_strcmp(component, "SO")
		|| !ft_strcmp(component, "WE") || !ft_strcmp(component, "EA")
		|| !ft_strcmp(component, "F") || !ft_strcmp(component, "C")
		|| !ft_strcmp(component, "DO"))
			return (1);
	return (0);
}

unsigned int	rgb_to_uint(char *component)
{
	int				i;
	char			**rgb;
	int				count;
	unsigned int	color;

	i = -1;
	count = 0;
	while (component[++i])
		if (component[i] == ',')
			count++;
	if (count != 2)
		error_mssg(COLORS);
	rgb = ft_split(component, ',');
	if (ft_dbl_strlen(rgb) != 3)
	{
		ft_dbl_free(rgb);
		error_mssg(COLORS);
	}
	i = -1;
	while (rgb[++i])
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			ft_dbl_free(rgb);
			error_mssg(COLORS);
		}
	color = (ft_atoi(rgb[0]) << 16) | (ft_atoi(rgb[1]) << 8) | ft_atoi(rgb[2]);
	return (ft_dbl_free(rgb), color);
}

void	fill_texture(t_texture *texture, char **components)
{
	if (!ft_strcmp(components[0], "NO"))
		texture->no_tex = mlx_load_png(components[1]);
	else if (!ft_strcmp(components[0], "SO"))
		texture->so_tex = mlx_load_png(components[1]);
	else if (!ft_strcmp(components[0], "WE"))
		texture->we_tex = mlx_load_png(components[1]);
	else if (!ft_strcmp(components[0], "EA"))
		texture->ea_tex = mlx_load_png(components[1]);
	else if (!ft_strcmp(components[0], "DO"))
		texture->door_tex = mlx_load_png(components[1]);
	else if (!ft_strcmp(components[0], "F"))
		texture->f_clr = rgb_to_uint(components[1]);
	else if (!ft_strcmp(components[0], "C"))
		texture->c_clr = rgb_to_uint(components[1]);
	if (!texture->no_tex || !texture->so_tex || !texture->we_tex
		|| !texture->ea_tex || !texture->door_tex)
	{
		ft_dbl_free(components);
		error_mssg(NOT_EXIST);
	}
	ft_dbl_free(components);
}

void	check_textures(my_mlx_t *mlx, char **layout)
{
	t_texture	*texture;
	char		**components = NULL;

	texture = malloc(sizeof(t_texture));
	init_texture(texture);
	int	i;

	i = -1;
	while (layout[++i] && i < 7)
	{
		components = ft_split_set(layout[i], "\t ");
		if (ft_dbl_strlen(components) != 2)
		{
			free(mlx);
			free(texture);
			ft_dbl_free(components);
			error_mssg(TEXTURE_ARG);
		}
		if (!is_valid_texture(components[0]))
		{
			free(mlx);
			free(texture);
			ft_dbl_free(components);
			error_mssg(TEXTURE_ARG);
		}
		fill_texture(texture, components);
	}
	mlx->texture = texture;
}
