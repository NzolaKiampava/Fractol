# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkiampav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 14:31:01 by nkiampav          #+#    #+#              #
#    Updated: 2024/08/19 15:37:43 by nkiampav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = fractol

# Compiler
CC = gcc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(HEADER_DIR)

# MiniLibX directory and libraries
MLX_DIR = ./minilibx-linux
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


$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
	@echo "Compiling Fractol...."
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)
	@echo "Fractol Ready."

$(LIBFT_DIR)/libft.a:
	@echo "Making Libft...."
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	@echo "Making Minilibx...."
	$(MAKE) -C $(MLX_DIR)

clean:
	@echo "Removing .0 object files...."
	rm -f $(OBJS)
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MLX_DIR) clean

fclean: clean
	@echo "Removing Fractol...."
	rm -f $(NAME)
	$(MAKE) -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
