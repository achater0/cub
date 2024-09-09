

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
	double angle;
	double x;
	double y;
	int width;
	int height;
	int block_size;
} my_mlx_t;

void	main_fct(my_mlx_t *mlx);
void hook_fct(void *param);
void	draw_mlx(my_mlx_t *mlx);
void	ray_casting(my_mlx_t *mlx);
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	normalize_angle(double *angle);












# endif
