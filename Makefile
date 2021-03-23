#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 18:13:57 by mchudik           #+#    #+#              #
#    Updated: 2019/04/17 18:55:38 by mchudik          ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = fractol
SRC = src/main.c \
		src/barnsley.c \
		src/drav.c \
		src/keys.c \
		src/mouse.c \
		src/julia.c \
		src/mandelbrot.c \
		src/other_fractals.c \
		src/barnsley2.c \
		src/menu.c
OUT = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OUT)
	make -C ./libft
	gcc $(FLAGC) -o $(NAME) $(OUT) $(MLX) ./libft/libft.a
	@echo 'Compilated!'

clean:
	rm -f $(OUT)
	make -C ./libft clean

fclean:
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
