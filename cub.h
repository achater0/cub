#ifndef CUB_H
# define CUB_H
# define BUFFER_SIZE 42

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "./MLX42/include/MLX42/MLX42.h"

# include "libft/libft.h"

typedef enum e_error {
	EXTENSION,
	INVALID_INPUT,
	MAP_CHAR,
	EMPTY_FILE,
	NEWLINE_MAP,
	TEXTURE_ARG,
	NOT_EXIST,
	PERMISSION,
	CHECK_FILE,
	COLORS,
	WALLS,
	PLAYER_NOT_FOUND
}	t_error;

typedef struct s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned int	f_clr;
	unsigned int	c_clr;
}	t_texture;

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
	unsigned int cols;
	unsigned int rows;
	int block_size;
	t_texture *texture;
} my_mlx_t;

void	main_fct(my_mlx_t *mlx);
void hook_fct(void *param);
void	draw_mlx(my_mlx_t *mlx);
void	ray_casting(my_mlx_t *mlx);
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	normalize_angle(double *angle);


void	error_mssg(int flag);
void	get_layout(my_mlx_t *mlx, char *av);
char	*get_next_line(int fd);
void	check_textures(my_mlx_t *mlx, char **layout);
int		is_surrounded_by_walls(char **layout);
int		player_exists(char **layout);


#endif
