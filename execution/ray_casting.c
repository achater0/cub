/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:48:43 by achater           #+#    #+#             */
/*   Updated: 2024/09/18 18:56:21 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	normalize_angle(double *angle)
{
	*angle = fmod(*angle, 360);
	if (*angle < 0)
		*angle += 360.0;
}

double	horizontal_distance(my_mlx_t *mlx, double Px, double Py, double a)
{
	double	x_ray;
	double	y_ray;
	double	ystep = 0;
	double	xstep;
	double	h_distance;
	double	Ax = 0.0;
	double	Ay = 0.0;
	double cos_a = cos(a * M_PI / 180);
	double sin_a = sin(a * M_PI / 180);
	double tan_a = tan(a * M_PI / 180);

	normalize_angle(&a);
	if (sin_a > 0)
		Ay = floor(Py / mlx->block_size) * mlx->block_size + mlx->block_size;
	else
		Ay = floor(Py / mlx->block_size) * mlx->block_size;
	Ax = Px - (Py - Ay) / tan_a;
	ystep = mlx->block_size;
	xstep = ystep / tan_a;
	if (sin_a <= 0)
		ystep *= -1;
	if (cos_a <= 0 && xstep > 0)
		xstep *= -1;
	if (cos_a > 0 && xstep < 0)
		xstep *= -1;
	x_ray = Ax;
	y_ray = Ay;
	while(x_ray >= 0 && y_ray >= 0 && x_ray < mlx->height && y_ray < mlx->width)
	{
		int map_x = (int)(x_ray / mlx->block_size);
		int map_y = (int)(y_ray / mlx->block_size);
		if (sin_a < 0)
			map_y = (int)((y_ray - 1) / mlx->block_size);
		if (map_x >= 0 && map_x < (int)mlx->cols && map_y >= 0 && map_y < (int)mlx->rows)
		{
			if (mlx->map[map_y][map_x] == '1')
				break;
		}
		x_ray += xstep;
		y_ray += ystep;
	}
	h_distance = sqrt(pow(x_ray - mlx->x, 2) + pow(y_ray - mlx->y, 2));
	return (h_distance);
}

double	vertical_distance(my_mlx_t *mlx, double Px, double Py, double a)
{
	double x_ray;
	double y_ray;
	double ystep;
	double xstep;
	double v_distance;
	double Ay = 0.0;
	double Ax= 0.0;
	double cos_a = cos(a * M_PI / 180);
	double sin_a = sin(a * M_PI / 180);
	double tan_a = tan(a * M_PI / 180);

	normalize_angle(&a);
	if (cos_a > 0)
		Ax = floor(Px / mlx->block_size) * mlx->block_size + mlx->block_size;
	else
		Ax = floor(Px / mlx->block_size) * mlx->block_size ;
	Ay = Py + (Ax - Px) * tan_a;
	xstep = mlx->block_size;
	ystep = xstep * tan_a;
	if (cos_a <= 0)
		xstep *= -1;
	if (sin_a <= 0 && ystep > 0)
		ystep *= -1;
	if (sin_a > 0 && ystep < 0)
		ystep *= -1;
	x_ray = Ax;
	y_ray = Ay;
	while(x_ray >= 0 && y_ray >= 0 && x_ray < mlx->height && y_ray < mlx->width)
	{
		int map_x = (int)(x_ray / mlx->block_size);
		int map_y = (int)(y_ray / mlx->block_size);
		if (cos_a < 0)
			map_x = (int)((x_ray - 1) / mlx->block_size);
		if (map_x >= 0 && map_x < (int)mlx->cols && map_y >= 0 && map_y < (int)mlx->rows)
		{
			if (mlx->map[map_y][map_x] == '1')
				break;
		}
		x_ray += xstep;
		y_ray += ystep;
	}
	v_distance = sqrt(pow(x_ray - mlx->x, 2) + pow(y_ray - mlx->y, 2));
	return (v_distance);
}


void	ray_casting(my_mlx_t *mlx)
{
	// normalize_angle(&mlx->angle);
	double	fov = 60;
	double	start_angle = mlx->angle - (fov / 2);
	double	step = (double)fov / mlx->width;
	double	screen_x = 0;
	double	Px = mlx->x;
	double	Py = mlx->y;
	double	h_distance;
	double	v_distance;
	double	distance;
	double	correct_distance;
	int 	ray_count = 0;

	normalize_angle(&start_angle);
	double a = start_angle;
	while(ray_count < mlx->width)
	{
		normalize_angle(&a);
		h_distance = horizontal_distance(mlx, Px, Py, a);
		v_distance = vertical_distance(mlx, Px, Py, a);
		distance = fmin(h_distance, v_distance);
		correct_distance = distance * cos((a - mlx->angle) * M_PI / 180);

    // Bresenham's line algorithm to draw the line from (start_x, start_y) to (end_x, end_y)
    	// double x_increment, y_increment;
    	// double x, y;
    	// double delta_x, delta_y;
    	// int steps, i;

    	// delta_x = distance * cos(a * M_PI / 180);
    	// delta_y = distance * sin(a * M_PI / 180);
    	// steps = (int)fmax(fabs(delta_x), fabs(delta_y));
    	// x_increment = delta_x / steps;
    	// y_increment = delta_y / steps;
    	// x = Px;
    	// y = Py;
    	// i = 0;
    	// while (i <= steps)
    	// {
    	//     if (x >= 0 && x < mlx->width && y >= 0 && y < mlx->width)
    	//         mlx_put_pixel(mlx->img, round(x), round(y), ft_pixel(255, 0, 0, 255));
    	//     else
    	//         break;
    	//     x += x_increment;
    	//     y += y_increment;
    	//     i++;
    	// }
		// wall randering

		double wall_height = (mlx->width / correct_distance) * 110;
		double wall_start = (mlx->width / 2) - (wall_height / 2);
		double wall_end = wall_start + wall_height;
		double y = wall_start - 1;
		// int x = 0;
		// while(x < wall_start)
		// {
		//     mlx_put_pixel(mlx->img, screen_x, x, ft_pixel(0, 0, 0, 255));
		//     x++;
		// }
		// x = wall_end;
		// while(x < mlx->width)
		// {
		//     mlx_put_pixel(mlx->img, screen_x, x, ft_pixel(0, 255, 255, 255));
		//     x++;
		// }
		while (++y < wall_end)
			if (y >= 0 && y < mlx->width)
				mlx_put_pixel(mlx->img, screen_x, y, ft_pixel(0, 255, 255, 255));
		a += step;
		ray_count++;
		screen_x++;
	}
}
