/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:48:43 by achater           #+#    #+#             */
/*   Updated: 2024/10/12 10:39:27 by achater          ###   ########.fr       */
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
		Ay = floor(Py / mlx->b_size) * mlx->b_size + mlx->b_size;
	else
		Ay = floor(Py / mlx->b_size) * mlx->b_size;
	Ax = Px - (Py - Ay) / tan_a;
	ystep = mlx->b_size;
	xstep = ystep / tan_a;
	if (sin_a <= 0)
		ystep *= -1;
	if (cos_a <= 0 && xstep > 0)
		xstep *= -1;
	if (cos_a > 0 && xstep < 0)
		xstep *= -1;
	x_ray = Ax;
	y_ray = Ay;
	while(x_ray >= 0 && y_ray >= 0 && x_ray < (mlx->cols * mlx->b_size) && y_ray < (mlx->rows * mlx->b_size))
	{
		int map_x = (int)(x_ray / mlx->b_size);
		int map_y = (int)(y_ray / mlx->b_size);
		if (sin_a < 0)
			map_y = floor(((y_ray - 1) / mlx->b_size));
		if (map_x >= 0 && map_x < (int)mlx->cols && map_y >= 0 && map_y < (int)mlx->rows)
		{
			if (mlx->map[map_y][map_x] == '1' || mlx->map[map_y][map_x] == 'C')
			{
				if(mlx->map[map_y][map_x] == 'C')
					mlx->h_door = 1;
				else
					mlx->h_door = 0;
				break;
			}
		}
		x_ray += xstep;
		y_ray += ystep;
	}
	h_distance = sqrt(pow(x_ray - mlx->x, 2) + pow(y_ray - mlx->y, 2));
	mlx->x_h = x_ray;
	mlx->y_h = y_ray;
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
		Ax = floor(Px / mlx->b_size) * mlx->b_size + mlx->b_size;
	else
		Ax = floor(Px / mlx->b_size) * mlx->b_size ;
	Ay = Py + (Ax - Px) * tan_a;
	xstep = mlx->b_size;
	ystep = xstep * tan_a;
	if (cos_a <= 0)
		xstep *= -1;
	if (sin_a <= 0 && ystep > 0)
		ystep *= -1;
	if (sin_a > 0 && ystep < 0)
		ystep *= -1;
	x_ray = Ax;
	y_ray = Ay;
	while(x_ray >= 0 && y_ray >= 0 && x_ray < (mlx->cols * mlx->b_size) && y_ray < (mlx->rows * mlx->b_size))
	{
		int map_x = (int)(x_ray / mlx->b_size);
		int map_y = (int)(y_ray / mlx->b_size);
		if (cos_a < 0)
			map_x = floor(((x_ray - 1) / mlx->b_size));
		if (map_x >= 0 && map_x < (int)mlx->cols && map_y >= 0 && map_y < (int)mlx->rows)
		{
			if (mlx->map[map_y][map_x] == '1' || mlx->map[map_y][map_x] == 'C')
			{
				if(mlx->map[map_y][map_x] == 'C')
					mlx->v_door = 1;
				else
					mlx->v_door = 0;
				break;
			}
		}
		x_ray += xstep;
		y_ray += ystep;
	}
	v_distance = sqrt(pow(x_ray - mlx->x, 2) + pow(y_ray - mlx->y, 2));
	mlx->x_v = x_ray;
	mlx->y_v = y_ray;
	return (v_distance);
}


void	ray_casting(my_mlx_t *mlx)
{
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
		if (h_distance < v_distance)
		{
			distance = h_distance;
			mlx->wall_inter = mlx->x_h;
			mlx->wall_inter_x = mlx->x_h;
			mlx->wall_inter_y = mlx->y_h;
			mlx->is_vertical = 0;
			mlx->door = mlx->h_door;
		}
		else
		{
			distance = v_distance;
			mlx->wall_inter = mlx->y_v;
			mlx->wall_inter_x = mlx->x_v;
			mlx->wall_inter_y = mlx->y_v;
			mlx->is_vertical = 1;
			mlx->door = mlx->v_door;
		}
		correct_distance = distance * cos((a - mlx->angle) * M_PI / 180);
		double wall_height = (mlx->height / correct_distance) * (mlx->b_size + 40);
		double wall_start = (mlx->height / 2) - (wall_height / 2);
		if (wall_start < 0.0)
			wall_start = 0.0;
		double wall_end = wall_start + wall_height;
		if (wall_end > mlx->height)
			wall_end = mlx->height;
		double y = wall_start - 1;
		int				tex_x;
		int				tex_y;
		unsigned int	pixel_color;

		if (mlx->door == 1)
			mlx->curr_texture = mlx->texture->door_tex;
		else
			get_which_texture_side(mlx, mlx->wall_inter_x, mlx->wall_inter_y);
		tex_x = get_text_x(mlx, mlx->wall_inter);
		int x = 0;
		while(x < wall_start)
		{
			mlx_put_pixel(mlx->img, screen_x, x, mlx->texture->c_clr);
			x++;
		}
		while (++y < wall_end)
		{
			tex_y = get_tex_y(mlx, y, wall_height);
			pixel_color = get_texture_color(mlx->curr_texture , tex_x, tex_y);
			if (y >= 0 && y < mlx->height)
				adjust_color(mlx->img, screen_x, y, pixel_color);
		}
		while(y < mlx->height)
		{
			mlx_put_pixel(mlx->img, screen_x, y, mlx->texture->f_clr);
		    y++;
		}
		a += step;
		ray_count++;
		screen_x++;
	}
}
