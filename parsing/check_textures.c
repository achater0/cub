/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:58:19 by mstaali           #+#    #+#             */
/*   Updated: 2024/09/17 10:50:41 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_texture(t_texture *texture)
{
	texture->no = NULL;
	texture->so = NULL;
	texture->we = NULL;
	texture->ea = NULL;
	texture->c_clr = 0;	
	texture->f_clr = 0;
}

int	is_valid_texture(char *component)
{
	if (!ft_strcmp(component, "NO") || !ft_strcmp(component, "SO")
		|| !ft_strcmp(component, "WE") || !ft_strcmp(component, "EA")
		|| !ft_strcmp(component, "F") || !ft_strcmp(component, "C"))
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
		texture->no = ft_strdup(components[1]);
	else if (!ft_strcmp(components[0], "SO"))
		texture->so = ft_strdup(components[1]);
	else if (!ft_strcmp(components[0], "WE"))
		texture->we = ft_strdup(components[1]);
	else if (!ft_strcmp(components[0], "EA"))
		texture->ea = ft_strdup(components[1]);
	else if (!ft_strcmp(components[0], "F"))
		texture->f_clr = rgb_to_uint(components[1]);
	else if (!ft_strcmp(components[0], "C"))
		texture->c_clr = rgb_to_uint(components[1]);
	ft_dbl_free(components);
}

void	check_paths(my_mlx_t *mlx, t_texture *texture, char **path)
{
	if (!ft_strcmp(path[0], "NO") || !ft_strcmp(path[0], "SO")
		|| !ft_strcmp(path[0], "EA") || !ft_strcmp(path[0], "WE"))
	{
		if (access(path[1], F_OK) == 0)
			return ;
		else
		{
			free(mlx);
			free(texture);
			ft_dbl_free(path);
			if (errno == ENOENT)
				error_mssg(NOT_EXIST);
			else if (errno == EACCES)
				error_mssg(PERMISSION);
			else
				error_mssg(CHECK_FILE);
		}
	}
}

void	check_textures(my_mlx_t *mlx, char **layout)
{
	t_texture	*texture;
	char		**components = NULL;

	texture = malloc(sizeof(t_texture));
	init_texture(texture);
	int	i;

	i = -1;
	while (layout[++i] && i < 6)
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
		check_paths(mlx, texture, components);
		fill_texture(texture, components);
	}
	mlx->texture = texture;
}
