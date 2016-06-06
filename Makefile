# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shazan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/12 15:17:40 by shazan            #+#    #+#              #
#    Updated: 2015/10/09 13:24:13 by shazan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc -Wall -Wextra -Werror -O3
SRC = main.c draw.c fdf.c get_next_line.c bresenham.c
OBJ = $(SRC:.c=.o)
LIB = ./libft/
MLX = -lmlx -framework AppKit -framework OpenGL

all: Lib $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./libft/ -lft $(MLX)

Lib: 
	make -C $(LIB)

clean:
	rm -f $(OBJ)
	cd $(LIB) ; make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIB) ; make fclean

re: fclean all

.PHONY: all clean fclean re
