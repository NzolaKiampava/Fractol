# Name of the executable
NAME = fractol

# Compiler
CC = gcc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(HEADER_DIR)

# MiniLibX directory and libraries
MLX_DIR = ./minilibx
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Libft directory and library
LIBFT_DIR = ./libft
LIBFT = -L$(LIBFT_DIR) -lft

# header
HEADER_DIR = ./header

# Source files
SRCS =	fractol.c \
	fractal_type.c \
	guide_msg.c \
	util.c \
	generate_fractal.c \
	event_func.c
	
# Object files
OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

