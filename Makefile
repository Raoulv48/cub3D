# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rverscho <rverscho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/26 19:15:50 by rverscho      #+#    #+#                  #
#    Updated: 2020/07/15 18:43:57 by rverscho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

SRC := utils1.c utils2.c utils3.c utils4.c get_parser_string.c parser.c \
	parser2.c fill_map.c check_map.c init_struct1.c init_struct2.c \
	fill_textures.c fill_textures2.c hooks1.c hooks2.c hooks3.c image1.c \
	image2.c image3.c digital_differential_analysis.c sprite1.c sprite2.c \
	fill_sprite.c main.c screenshot.c

O_FILES := $(SRC:%=srcs/%)

SRC_BONUS := utils1.c utils2.c utils3.c utils4.c get_parser_string.c parser.c \
	parser2.c fill_map.c check_map.c init_struct1.c init_struct2.c \
	fill_textures.c fill_textures2.c hooks1.c hooks2.c hooks3.c image1.c \
	image2.c image3.c digital_differential_analysis.c sprite1.c sprite2.c \
	fill_sprite.c main.c screenshot.c

BO_FILES := $(SRC_BONUS:%=bonus/%)

MLX = minilibmlx
CC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(O_FILES)
	@echo "Compiling MLX"
	@make -C $(MLX)
	cp minilibmlx/libmlx.dylib ./
	$(CC) -L minilibmlx/ -l mlx -framework OpenGl -framework AppKit \
	libmlx.dylib -o $(NAME) $(O_FILES) -Ofast -march=native

bonus: $(NAME_BONUS)
$(NAME_BONUS): $(BO_FILES)
	@echo "Compiling MLX"
	@make -C $(MLX)
	cp minilibmlx/libmlx.dylib ./
	$(CC) -L minilibmlx/ -l mlx -framework OpenGl -framework AppKit \
	libmlx.dylib -o $(NAME_BONUS) $(BO_FILES)

%.o: %.c
	@echo "Compiling $<"
	@gcc -Wall -Werror -Wextra -I mlx -I inc -c $< -o $@

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME_BONUS)
	@make -C $(MLX) clean
	/bin/rm -f screenshot.bmp
	/bin/rm -f libmlx.dylib

re: fclean all
