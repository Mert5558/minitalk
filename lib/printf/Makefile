# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merdal <merdal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 14:18:08 by merdal            #+#    #+#              #
#    Updated: 2023/11/27 13:51:07 by merdal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES = \
	ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_print_char.c ft_print_int.c ft_print_str.c \
	ft_print_unsigned.c ft_print_x_hex.c ft_print_xx_hex.c ft_print_ptr.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re