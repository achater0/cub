/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_layout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:34:46 by mstaali           #+#    #+#             */
/*   Updated: 2024/09/27 18:54:04 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_map_character(char c)
{
	if (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E' || c == ' '
		|| c == '\n' || c == '\t' || c == 'O' || c == 'C')
		return (1);
	return (0);
}

void	is_map_valid(my_mlx_t *mlx, char *line)
{
	int	i;
	int	texture;

	if (!line)
	{
		free(mlx);
		error_mssg(EMPTY_FILE);
	}
	i = 0;
	texture = 0;
	while (line[i] && texture < 6)
	{
		if (line[i] == '\n' && line[i + 1] != '\n')
			texture++;
		i++;
	}
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			free(mlx);
			free(line);
			error_mssg(NEWLINE_MAP);
		}
		if (!is_map_character(line[i]))
		{
			free(mlx);
			free(line);
			error_mssg(MAP_CHAR);
		}
		i++;
	}
}

char	*read_from_file(my_mlx_t *mlx, char *av)
{
	int		fd;
	char	*tmp;
	char	*line;
	char	*new_line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		free(mlx);
		error_mssg(EMPTY_FILE);
	}
	line = get_next_line(fd);
	tmp = get_next_line(fd);
	while (tmp)
	{
		new_line = line;
		line = ft_strjoin(line, tmp);
		free(new_line);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return(line);
}

void	map_padding(my_mlx_t *mlx, char **layout)
{
	int	i;
	int	j;
	int	len;

	mlx->map = malloc((mlx->rows + 1) * sizeof(char *));
	if (!mlx->map)
		return ;
	i = -1;
	while (++i < (int)mlx->rows)
	{
		mlx->map[i] = malloc(mlx->cols + 1);
		len = ft_strlen(layout[i]);
		ft_strlcpy(mlx->map[i], layout[i], len + 1);
		j = len;
		while (j < (int)mlx->cols)
			mlx->map[i][j++] = '5';
		mlx->map[i][mlx->cols] = '\0';
	}
	mlx->map[mlx->rows] = NULL;
}

void	fill_map(my_mlx_t *mlx, char **layout)
{
	int		i;

	mlx->rows = ft_dbl_strlen(layout);
	mlx->cols = 0;
	i = 0;
	while (i < (int)mlx->rows)
	{
		if (ft_strlen(layout[i]) > mlx->cols)
			mlx->cols = ft_strlen(layout[i]);
		i++;
	}
	map_padding(mlx, layout);
}

void	free_textures(t_texture *texture)
{
	free(texture->no);
	free(texture->so);
	free(texture->we);
	free(texture->ea);
	free(texture);
}

void	get_layout(my_mlx_t *mlx, char *av)
{
	char	*line;
	char	**layout;

	line = read_from_file(mlx, av);
	is_map_valid(mlx, line);
	layout = ft_split(line, '\n');
	free(line);
	check_textures(mlx, layout);
	if (!is_surrounded_by_walls(layout + 6))
	{
		free_textures(mlx->texture);
		free(mlx);
		error_mssg(WALLS);
	}
	if (!player_exists(layout + 6))
	{
		free(mlx);
		free_textures(mlx->texture);
		error_mssg(PLAYER_NOT_FOUND);
	}
	fill_map(mlx, layout + 6);
}
