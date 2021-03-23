#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 17:16:43 by mchudik           #+#    #+#              #
#    Updated: 2018/11/20 19:10:31 by mchudik          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

NAME = libft.a

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_putchar.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strnew.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_itoa.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstmap.c	\
		ft_lstiter.c \
		ft_lstadd.c \
		ft_lstnew.c \
		ft_strsub.c \
		ft_strsplit.c \
		ft_is_flag.c \
		ft_number_len.c \
		ft_len.c \
		ft_swap.c \
		ft_sqrt.c \
		ft_recursive_factorial.c \
		ft_words.c \
		get_next_line.c

HEADER_DIR = includes

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):

	$(CC) $(CFLAGS) $(SRC) -I$(HEADER_DIR)

	ar rc $(NAME) *.o

	ranlib $(NAME)

clean:

	/bin/rm -f *.o

fclean: clean

	/bin/rm -f $(NAME)

re: fclean all