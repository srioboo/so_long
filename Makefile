# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 08:26:13 by srioboo-          #+#    #+#              #
#    Updated: 2025/03/19 17:34:38 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME = so_long

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = 
LIB = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

#auxiliary commands
RM = rm

SRCS = so_long.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# test section
test: all
	./$(NAME)

.PHONY: all clean fclean re test