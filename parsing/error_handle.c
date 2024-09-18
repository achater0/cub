/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:52:06 by mstaali           #+#    #+#             */
/*   Updated: 2024/09/15 21:10:13 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	error_mssg(int flag)
{
	ft_putstr_fd("\n\033[1;31mError:\033[0m ", STDERR_FILENO);
	if (flag == EXTENSION)
		ft_putstr_fd("Incorrect file extension\nUsage: ./cub3D <path_to_map_file.cub>\n\n", STDERR_FILENO);
	if (flag == INVALID_INPUT)
		ft_putstr_fd("Invalid input\nUsage: ./cub3D <path_to_map_file.cub>\n\n", STDERR_FILENO);
	if (flag == EMPTY_FILE)
		ft_putstr_fd("File empty\n\n", STDERR_FILENO);
	if (flag == NEWLINE_MAP)
		ft_putstr_fd("Map contains newline\n\n", STDERR_FILENO);
	if (flag == MAP_CHAR)
		ft_putstr_fd("Unrecognized map character\n\n", STDERR_FILENO);
	if (flag == TEXTURE_ARG)
		ft_putstr_fd("Invalid texture arguments\n\n", STDERR_FILENO);
	if (flag == NOT_EXIST)
		ft_putstr_fd("Texture file does not exist\n\n", STDERR_FILENO);
	if (flag == PERMISSION)
		ft_putstr_fd("Permission denied\n\n", STDERR_FILENO);
	if (flag == CHECK_FILE)
		ft_putstr_fd("Path for file is not checked\n\n", STDERR_FILENO);
	if (flag == COLORS)
		ft_putstr_fd("Invalid color pattern\n\n", STDERR_FILENO);
	if (flag == WALLS)
		ft_putstr_fd("Map is not surrounded by walls\n\n", STDERR_FILENO);
	if (flag == PLAYER_NOT_FOUND)
		ft_putstr_fd("Player not found in map\n\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
