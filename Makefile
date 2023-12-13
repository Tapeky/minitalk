# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 14:23:56 by tsadouk           #+#    #+#              #
#    Updated: 2023/12/13 14:59:57 by tsadouk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_client.c ft_server.c

OBJS = $(SRCS:.c=.o)

TARGET1 = server 
TARGET2 = client

all: lib $(TARGET1) $(TARGET2)

$(TARGET1): ft_server.o
	$(CC) $(CFLAGS) $^ -L printf -lftprintf -o $@

$(TARGET2): ft_client.o
	$(CC) $(CFLAGS) $^ -L printf -lftprintf -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I printf/includes

lib:
	@make -C printf

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(TARGET1) $(TARGET2)
	@make -C printf fclean

re: fclean all

.PHONY: all clean re lib
