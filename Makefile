# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merdal <merdal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:05:43 by merdal            #+#    #+#              #
#    Updated: 2024/02/01 14:13:39 by merdal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	:= server
CLIENT	:= client
SRC		:= ./client.c ./server.c
CFLAGS	:= -Wall -Wextra -Werror
CC		:= gcc
INCLUDE	:= -I./lib/libft/libft.a -I./lib/printf/libftprintf.a 
LIBS	:= -L./lib/libft -L./lib/printf -lft -lftprintf

.PHONY: all clean fclean server client

all: $(SERVER) $(CLIENT) clean

%.o: %.c
	@make -C ./lib/libft
	@make -C ./lib/printf
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ && printf "Compiled $<\n"

$(SERVER): server.o
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBS) -o $@

$(CLIENT): client.o
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBS) -o $@

clean:
	@make -C ./lib/libft clean
	@make -C ./lib/printf clean
	rm -f *.o && printf "Cleaned\n"

fclean: clean
	@make -C ./lib/libft fclean
	@make -C ./lib/printf fclean
	rm -f $(SERVER) $(CLIENT) && printf "Cleaned everything\n"

re: fclean all