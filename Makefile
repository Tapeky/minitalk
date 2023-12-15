# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 14:23:56 by tsadouk           #+#    #+#              #
#    Updated: 2023/12/13 17:21:03 by tsadouk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = printf
LIBFT_FLAGS = -L$(LIBFT_DIR) -lftprintf
INCLUDES = -I$(LIBFT_DIR)/includes

SRCS = client.c server.c
SRCS_BONUS = client_bonus.c server_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

TARGETS = server client
TARGETS_BONUS = server_bonus client_bonus

all: libft $(TARGETS)

$(TARGETS): %: %.o
	$(CC) $(CFLAGS) $^ $(LIBFT_FLAGS) -o $@

$(TARGETS_BONUS): %_bonus: %_bonus.o
	$(CC) $(CFLAGS) $^ $(LIBFT_FLAGS) -o $@

bonus: libft $(TARGETS_BONUS)

libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	
fclean: clean
	rm -f $(TARGETS) $(TARGETS_BONUS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus libft
