/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:13:04 by achater           #+#    #+#             */
/*   Updated: 2024/10/25 10:14:29 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	normalize_angle(double *angle)
{
	*angle = fmod(*angle, 360);
	if (*angle < 0)
		*angle += 360.0;
}

void	ray_h_helper(my_mlx_t *mlx, double *ax, double *ay, double a)
{
	double			xstep;
	double			ystep;
	unsigned int	m_x;
	unsigned int	m_y;

	ystep = mlx->b_size;
	xstep = ystep / tan(a * M_PI / 180);
	(sin(a * M_PI / 180) <= 0 && ystep > 0) && (ystep *= -1);
	(cos(a * M_PI / 180) <= 0 && xstep > 0) && (xstep *= -1);
	(cos(a * M_PI / 180) > 0 && xstep < 0) && (xstep *= -1);
	while (*ax >= 0 && *ay >= 0 && *ax < (mlx->cols * mlx->b_size)
		&& *ay < (mlx->rows * mlx->b_size))
	{
		1 && (m_x = (int)(*ax / mlx->b_size), m_y = (int)(*ay / mlx->b_size));
		if (m_x >= 0 && m_x < mlx->cols && m_y >= 0 && m_y < mlx->rows)
		{
			if (mlx->map[m_y][m_x] == '1')
				break ;
		}
		1 && (*ax += xstep, *ay += ystep);
	}
}

void	ray_v_helper(my_mlx_t *mlx, double *ax, double *ay, double a)
{
	double			xstep;
	double			ystep;
	unsigned int	m_x;
	unsigned int	m_y;

	xstep = mlx->b_size;
	ystep = xstep * tan(a * M_PI / 180);
	(cos(a * M_PI / 180) <= 0) && (xstep *= -1);
	(sin(a * M_PI / 180) <= 0 && ystep > 0) && (ystep *= -1);
	(sin(a * M_PI / 180) > 0 && ystep < 0) && (ystep *= -1);
	while (*ax >= 0 && *ay >= 0 && *ax < (mlx->cols * mlx->b_size)
		&& *ay < (mlx->rows * mlx->b_size))
	{
		1 && (m_x = (int)(*ax / mlx->b_size), m_y = (int)(*ay / mlx->b_size));
		if (m_x >= 0 && m_x < mlx->cols && m_y >= 0 && m_y < mlx->rows)
		{
			if (mlx->map[m_y][m_x] == '1')
				break ;
		}
		1 && (*ax += xstep, *ay += ystep);
	}
}

double	horizontal_distance(my_mlx_t *mlx, double Px, double Py, double a)
{
	double	ax;
	double	ay;
	double	h_distance;

	normalize_angle(&a);
	if (sin(a * M_PI / 180) > 0)
		ay = floor(Py / mlx->b_size) * mlx->b_size + mlx->b_size;
	else
		ay = floor(Py / mlx->b_size) * mlx->b_size - 0.0001;
	ax = Px - (Py - ay) / tan(a * M_PI / 180);
	ray_h_helper(mlx, &ax, &ay, a);
	h_distance = sqrt(pow(ax - mlx->x, 2) + pow(ay - mlx->y, 2));
	mlx->x_h = ax;
	mlx->y_h = ay;
	return (h_distance);
}

double	vertical_distance(my_mlx_t *mlx, double Px, double Py, double a)
{
	double	ax;
	double	ay;
	double	v_distance;

	normalize_angle(&a);
	if (cos(a * M_PI / 180) > 0)
		ax = floor(Px / mlx->b_size) * mlx->b_size + mlx->b_size;
	else
		ax = floor(Px / mlx->b_size) * mlx->b_size - 0.0001;
	ay = Py + (ax - Px) * tan(a * M_PI / 180);
	ray_v_helper(mlx, &ax, &ay, a);
	v_distance = sqrt(pow(ax - mlx->x, 2) + pow(ay - mlx->y, 2));
	mlx->x_v = ax;
	mlx->y_v = ay;
	return (v_distance);
}

double	find_right_dist(my_mlx_t *mlx, double a)
{
	double	h_distance;
	double	v_distance;
	double	distance;

	h_distance = horizontal_distance(mlx, mlx->x, mlx->y, a);
	v_distance = vertical_distance(mlx, mlx->x, mlx->y, a);
	if (h_distance < v_distance)
	{
		distance = h_distance;
		mlx->wall_inter = mlx->x_h;
		mlx->wall_inter_x = mlx->x_h;
		mlx->wall_inter_y = mlx->y_h;
		mlx->is_vertical = 0;
	}
	else
	{
		distance = v_distance;
		mlx->wall_inter = mlx->y_v;
		mlx->wall_inter_x = mlx->x_v;
		mlx->wall_inter_y = mlx->y_v;
		mlx->is_vertical = 1;
	}
	return (distance * cos((a - mlx->angle) * M_PI / 180));
}

void	painting(my_mlx_t *mlx, double screen_x)
{
	double			y;
	int				tex_x;
	int				tex_y;
	unsigned int	pixel_color;
	int				x;

	y = mlx->wall_start - 1;
	x = -1;
	get_which_texture_side(mlx, mlx->wall_inter_x, mlx->wall_inter_y);
	tex_x = get_text_x(mlx, mlx->wall_inter);
	while (++x < mlx->wall_start)
		mlx_put_pixel(mlx->img, screen_x, x, mlx->texture->c_clr);
	while (++y < mlx->wall_end)
	{
		tex_y = get_tex_y(mlx, y, mlx->wall_height);
		pixel_color = get_texture_color(mlx->curr_texture, tex_x, tex_y);
		if (y >= 0 && y < mlx->height)
			adjust_color(mlx->img, screen_x, y, pixel_color);
	}
	y--;
	while (++y < mlx->height)
		mlx_put_pixel(mlx->img, screen_x, y, mlx->texture->f_clr);
}

void	ray_casting(my_mlx_t *mlx)
{
	double	step;
	double	screen_x;
	double	c_distance;
	int		ray_count;
	double	a ;

	normalize_angle(&a);
	ray_count = -1;
	step = 60.0 / mlx->width;
	a = mlx->angle - 30;
	screen_x = 0;
	while (++ray_count < mlx->width)
	{
		normalize_angle(&a);
		c_distance = find_right_dist(mlx, a);
		mlx->wall_height = (mlx->height / c_distance) * (mlx->b_size + 40);
		mlx->wall_start = (mlx->height / 2) - (mlx->wall_height / 2);
		mlx->wall_end = mlx->wall_start + mlx->wall_height;
		(mlx->wall_start < 0.0) && (mlx->wall_start = 0.0);
		(mlx->wall_end > mlx->height) && (mlx->wall_end = mlx->height);
		painting(mlx, screen_x);
		1 && (a += step, screen_x++);
	}
}
