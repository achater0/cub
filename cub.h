#ifndef CUB_H
# define CUB_H
# define BUFFER_SIZE 42
# define TEXTURE_WIDTH 160
# define TEXTURE_HEIGHT 160

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
	PLAYER_NOT_FOUND,
	DOORS,
	FRAMES
}	t_error;

typedef struct s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*door;
	unsigned int	f_clr;
	unsigned int	c_clr;
	mlx_texture_t	*no_tex;
	mlx_texture_t	*so_tex;
	mlx_texture_t	*we_tex;
	mlx_texture_t	*ea_tex;
	mlx_texture_t	*door_tex;
}	t_texture;

typedef struct my_mlx_s
{
	mlx_t *mlx;
	mlx_image_t 	*img;
	mlx_image_t		**sprite_frames;
	mlx_texture_t	**sprite_textures;
	int				num_frames;
	int				curr_frame;
	int				is_animated;
	double			last_frame_time;
	char **map;
	double angle;
	double x;
	double y;
	int width;
	int height;
	unsigned int cols;
	unsigned int rows;
	int block_size;
	int	is_vertical;
	mlx_texture_t	*curr_texture;
	double x_h;
	double y_h;
	double x_v;
	double y_v;
	double			wall_inter_x;
	double			wall_inter_y;
	double			wall_inter;
	t_texture		*texture;
	int	door;
	int v_door;
	int h_door;
	int	hidden;
}	my_mlx_t;

void			main_fct(my_mlx_t *mlx);
void 			hook_fct(void *param);
void			draw_mlx(my_mlx_t *mlx);
void			ray_casting(my_mlx_t *mlx);
int32_t 		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void			normalize_angle(double *angle);
void 			draw_player(my_mlx_t *mlx,int x, int y, int radius, int color);
void			draw_mini_map(my_mlx_t *mlx);
void 			color_the_block(mlx_image_t *img,int i, int j, int width, int height, int color);
void			open_close_door(my_mlx_t *mlx);


void			error_mssg(int flag);
void			get_layout(my_mlx_t *mlx, char *av);
char			*get_next_line(int fd);
void			check_textures(my_mlx_t *mlx, char **layout);
int				is_surrounded_by_walls(char **layout);
int				player_exists(char **layout);
void			get_which_texture_side(my_mlx_t *mlx, double ray_x, double ray_y);
unsigned int	get_texture_color(mlx_texture_t *tex, unsigned int x, unsigned int y);
void			adjust_color(mlx_image_t *image, unsigned int x, unsigned int y, unsigned int c);
double			get_text_x(my_mlx_t *mlx, double wall_inter);
double			get_tex_y(my_mlx_t *mlx, double y, double wall_height);
int				is_valid_doors(char **layout);
void			load_sprite_frames(my_mlx_t *mlx);
void			animate_sprite(my_mlx_t *mlx);
void			draw_sprite(my_mlx_t *mlx, mlx_image_t *sprite_frame, mlx_texture_t *sprite_texture);
#endif
