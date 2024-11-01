/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:58:19 by mstaali           #+#    #+#             */
/*   Updated: 2024/10/17 00:30:14 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_valid_texture(char *component)
{
	if (!ft_strcmp(component, "NO") || !ft_strcmp(component, "SO")
		|| !ft_strcmp(component, "WE") || !ft_strcmp(component, "EA")
		|| !ft_strcmp(component, "F") || !ft_strcmp(component, "C")
		|| !ft_strcmp(component, "DO"))
		return (1);
	return (0);
}

void	assign_tex(t_texture *texture, char **components)
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
}

void	fill_texture(my_mlx_t *mlx, char **layout)
{
	int			i;
	t_texture	*texture;
	char		**components;

	i = -1;
	texture = malloc(sizeof(t_texture));
	while (layout[++i] && i < 7)
	{
		components = ft_split_set(layout[i], "\t ");
		assign_tex(texture, components);
		if (!texture->no_tex || !texture->so_tex || !texture->we_tex
			|| !texture->ea_tex || !texture->door_tex)
			error_mssg(NOT_EXIST);
		ft_dbl_free(components);
		components = NULL;
	}
	mlx->texture = texture;
}

void	check_textures(my_mlx_t *mlx, char **layout)
{
	char		**components;
	int			i;

	i = -1;
	components = NULL;
	while (layout[++i] && i < 7)
	{
		components = ft_split_set(layout[i], "\t ");
		if (!components || ft_dbl_strlen(components) != 2)
		{
			ft_dbl_free(components);
			free(mlx);
			error_mssg(TEXTURE_ARG);
		}
		if (!is_valid_texture(components[0]))
		{
			ft_dbl_free(components);
			free(mlx);
			error_mssg(TEXTURE_ARG);
		}
		ft_dbl_free(components);
		components = NULL;
	}
	fill_texture(mlx, layout);
}
