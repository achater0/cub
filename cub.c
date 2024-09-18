/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:33:23 by achater           #+#    #+#             */
/*   Updated: 2024/09/18 14:34:16 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_extension(char *av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] != '.')
		i++;
	if (av[i] != '.')
		error_mssg(EXTENSION);
	if (!ft_strcmp(&av[i], ".cub"))
		return ;
	error_mssg(EXTENSION);
}

void f()
{
	system("leaks cub3D");
}

int main(int ac, char **av)
{
	unsigned int i;
	unsigned int j;
	my_mlx_t	*mlx;

	// atexit(f);
	if (ac != 2)
		error_mssg(INVALID_INPUT);
	else
	{
		check_extension(av[1]);
		mlx = malloc(sizeof(my_mlx_t));
		get_layout(mlx, av[1]);
		i = -1;
		printf("{cols : %d}\n", mlx->cols);
		printf("{rows : %d}\n", mlx->rows);
		while (++i < mlx->rows)
		{
			j = -1;
			while (++j < mlx->cols)
				printf("%c", mlx->map[i][j]);
			printf("\n");
		}

		mlx->block_size = 80;
		mlx->width = 1200;
		mlx->height = 1200;
		// mlx->map = malloc(sizeof(char *) * (mlx->height / mlx->block_size));
		// i = 0;
		// while (i < mlx->height / mlx->block_size)
		// {
		// 	mlx->map[i] = malloc(sizeof(char) * 10);
		// 	j = 0;
		// 	while (j < mlx->width / mlx->block_size)
		// 	{
		// 		if (i == 0 || i == 9)
		// 			mlx->map[i][j] = '1';
		// 		else if (j == 0 || j == 9)
		// 			mlx->map[i][j] = '1';
		// 		else
		// 			mlx->map[i][j] = '0';
		// 		j++;
		// 	}
		// 	i++;
		// }
		// // mlx->map[0][0] = '0';
		// mlx->map[5][5] = 'N';
		// mlx->map[5][6] = '1';
		// mlx->map[6][5] = '1';


		main_fct(mlx);
		// return (0);
	}
}
