

#ifndef CUB_H
#define CUB_H


#include <unistd.h>
#include <stdlib.h>
#include<math.h>
#include <stdio.h>
#include "./MLX42/include/MLX42/MLX42.h"


typedef struct my_mlx_s
{
	mlx_t *mlx;
	mlx_image_t *img;
	char **map;
	int angle;
	double x;
	double y;
} my_mlx_t;

void	main_fct(my_mlx_t *mlx);
void hook_fct(void *param);
void	draw_mlx(my_mlx_t *mlx);














# endif
