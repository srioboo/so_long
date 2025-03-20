# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 08:26:13 by srioboo-          #+#    #+#              #
#    Updated: 2025/03/20 16:50:01 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME = so_long

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I/usr/include -Imlx-linux
LIB = -Lmlx-linux -lmlx_Linux -lXext -lX11 -lm -lz

#auxiliary commands
RM = rm

SRCS = so_long.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

# $(NAME): $(OBJ)
#	$(CC) $(OBJ) $(INCLUDE) $(LIB) -o $(NAME)

# %.o: %.c
#	$(CC) $(CFLAGS) $(INCLUDE) -03 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx-linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx-linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# test section
test: all
	./$(NAME)

.PHONY: all clean fclean re test