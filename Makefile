CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

MLX42_LIB = MLX42/build/libmlx42.a
LIBS = -L /Users/achater/.brew/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit -fsanitize=address -g

NAME = cub3D

SRCS = cub.c ./execution/draw.c ./execution/hooks.c

OBJS = $(SRCS:.c=.o)

all: pre $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42_LIB) $(LIBS) -o $(NAME)

%.o: %.c cub.h
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

pre:
	cd MLX42 && cmake -B build && cmake --build build

re: fclean all
