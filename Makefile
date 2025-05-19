# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 08:26:13 by srioboo-          #+#    #+#              #
#    Updated: 2025/05/19 17:51:10 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME	= so_long

# compiler
CC 		= cc
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42
LIBFT	:= ./libft
DEBUG	= -fdiagnostics-color=always -g

HEADERS	= -I $(LIBMLX)/include \
		-I $(LIBFT)/src -I $(LIBFT)/get_next_line -I $(LIBFT)/ft_printf
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBSFT	= $(LIBFT)/libft.a
SRCS	= so_long.c \
		so_map.c \
		so_map_validate.c \
		so_scene.c \
		so_player.c \
		so_mngmt.c \
		so_utils.c \
		so_objects.c \
		so_fish.c
OBJS	= $(SRCS:.c=.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -s -j4
	
libft:
	@make -C $(LIBFT) -s full

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBSFT) $(LIBS) $(HEADERS) -o $(NAME)

debug: $(OBJS)
	@$(CC) $(OBJS) $(LIBSFT) $(LIBS) $(HEADERS) $(DEBUG) -o main

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: fclean all

libft-clean:
	@make -C ./libft -s full-clean

full-clean: libft-clean fclean

# test section - make test MAP=something
test: all
	./$(NAME) $(MAP)

tclean: clean
	@$(RM) $(NAME)

# Default for testing
MAP = ./maps/map0.ber

# detect memory leaks
sane: all
	$(CC) $(OBJS) $(LIBSFT) $(LIBS) $(HEADERS) -o $(NAME) -fsanitize=address,undefined -g
	./$(NAME) $(MAP)

val: all
# valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) $(MAP)
	valgrind --leak-check=full ./$(NAME) $(MAP)

# Clean, compile and launch valgrind with suppresions logs removed
fval: full-clean all
	valgrind --leak-check=full --track-origins=yes ./$(NAME) $(MAP)

fval-s: full-clean all
	valgrind --leak-check=full --track-origins=yes --suppressions=valgrind.supp ./$(NAME) $(MAP)

vall: all
	valgrind --leak-check=full --verbose --track-origins=yes --log-file=leaks.txt ./$(NAME) $(MAP)

# geneare a valgrind logs with suppresion anotations
val-log: full-clean all
	valgrind --leak-check=full --gen-suppressions=all --log-file=suppressions.txt ./$(NAME) $(MAP)

.PHONY: all clean fclean re sane val vall test tclean libmlx libft libft-clean full-clean debug
