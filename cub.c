/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:33:23 by achater           #+#    #+#             */
/*   Updated: 2024/08/26 19:03:45 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main()
{
	int i;
	int j;
	my_mlx_t *mlx;

	mlx = malloc(sizeof(my_mlx_t));
	mlx->map = malloc(sizeof(char *) * 10);
	i = 0;
	while (i < 10)
	{
		mlx->map[i] = malloc(sizeof(char) * 10);
		j = 0;
		while (j < 10)
		{
			if (i == 0 || i == 9)
				mlx->map[i][j] = '1';
			else if (j == 0 || j == 9)
				mlx->map[i][j] = '1';
			else
				mlx->map[i][j] = '0';
			j++;
		}
		i++;
	}
	mlx->map[5][5] = 'N';
	mlx->map[5][6] = '1';
	mlx->map[6][5] = '1';
	// create map
	// mlx->map[0] = "11111111111111111111111111111111111111111111111111111";
	// mlx->map[1] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[2] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[3] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[4] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[5] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[6] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[7] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[8] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[9] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[10] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[11] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[12] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[13] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[14] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[15] = "100000000100000000100000000100000000100000000100000001";
	// mlx->map[16] = "111111111111111111111111111111111111111111111111111111";
	main_fct(mlx);
	return (0);
}