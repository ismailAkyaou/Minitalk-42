# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 14:06:05 by iakyaou           #+#    #+#              #
#    Updated: 2023/02/28 20:29:25 by iakyaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = minitalk.h
NAME = minitalk

SERVER_SURS = server.c ft_putnum.c
SERVER_OBJ = $(SERVER_SURS:.c=.o)

SERVER_SURS_BONUS = server_bonus.c ft_putnum.c
SERVER_OBJ_BONUS = $(SERVER_SURS_BONUS:.c=.o)

CLIENT_SURS = client.c ft_atoi.c
CLIENT_OBJ = $(CLIENT_SURS:.c=.o)

CLIENT_SURS_BONUS = client_bonus.c ft_atoi.c
CLIENT_OBJ_BONUS = $(CLIENT_SURS_BONUS:.c=.o)

all: $(NAME) 

$(NAME): server client

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $<

server : $(SERVER_OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o server

client : $(CLIENT_OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o client
		
bonus: server_bonus client_bonus

server_bonus: $(SERVER_OBJ_BONUS) $(INCLUDE)
	$(CC) $(CFLAGS) $(SERVER_OBJ_BONUS) -o server_bonus

client_bonus:  $(CLIENT_OBJ_BONUS) $(INCLUDE)
	$(CC) $(CFLAGS) $(CLIENT_OBJ_BONUS) -o client_bonus


clean:
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)
	$(RM) $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS)

fclean: clean
	$(RM) server client
	$(RM) server_bonus client_bonus

re: fclean all

.PHONY: all fclean re clean bonus $(NAME)