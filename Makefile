# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 08:26:13 by srioboo-          #+#    #+#              #
#    Updated: 2025/03/26 15:55:27 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME = so_long

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

#auxiliary commands
RM = rm

SRCS = so_long.c 
OBJ = $(SRCS:.c=.o)

all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -Iinclude -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -I/usr/local/include -LMLX42/build -l:libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -I/usr/local/include -LMLX42/build -l:libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I/usr/local/include -LMLX42/build -l:libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/local/include -LMLX42/build -l:libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -O3 -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# test section
test: all
	./$(NAME)

tclean: clean
	$(RM) $(NAME)

# detect memory leaks
sane: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -fsanitize=address,undefined -g
	./$(NAME)

val: all
	valgrind --leak-check=full ./$(NAME)

vall: all
	valgrind --leak-check=full --verbose --track-origins=yes --log-file=leaks.txt ./$(NAME)

.PHONY: all clean fclean re sane val vall test tclean
