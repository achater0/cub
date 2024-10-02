CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -fsanitize=address -g

MLX42_LIB = MLX42/build/libmlx42.a
LIBS = -L /Users/achater/.brew/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit

NAME = cub3D

SRCS = cub.c ./execution/draw.c ./execution/hooks.c ./execution/ray_casting.c parsing/error_handle.c parsing/get_layout.c \
	parsing/get_next_line.c parsing/check_textures.c parsing/extract_map.c execution/mini_map.c parsing/textures.c \
	execution/doors_handler.c parsing/frames.c
OBJS = $(SRCS:.c=.o)

all: libft_make pre $(NAME)

libft_make:
	$(MAKE) -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42_LIB) libft/libft.a $(LIBS) -o $(NAME)

%.o: %.c cub.h
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	cd MLX42 && rm -rf build
	$(MAKE) -C libft fclean
pre:
	cd MLX42 && cmake -B build && cmake --build build

re: fclean all

.PHONY: all clean fclean re pre libft_make