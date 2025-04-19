# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 08:26:13 by srioboo-          #+#    #+#              #
#    Updated: 2025/04/19 11:34:30 by srioboo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME	= so_long

# compiler
CC 		= cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42
LIBFT	:= ./libft

HEADERS	= -I ./include -I $(LIBMLX)/include \
		-I $(LIBFT)/src -I $(LIBFT)/get_next_line -I $(LIBFT)/ft_printf
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBSFT	= $(LIBFT)/libft.a
SRCS	= so_long.c \
	so_draw.c \
	so_scene.c \
	so_player.c \
	so_mngmt.c \
	so_wall.c \
	so_ocean.c \
	so_door.c \
	so_fish.c
OBJS	= $(SRCS:.c=.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	
libft:
	@make -C $(LIBFT) full

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBSFT) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: fclean all

libft-clean:
	@make -C ./libft fclean

full-clean: libft-clean fclean

# test section
test: all
	./$(NAME)

tclean: clean
	$(RM) $(NAME)

# detect memory leaks
sane: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -fsanitize=address,undefined -g
	./$(NAME)

val: all
	valgrind --leak-check=full ./$(NAME)

vall: all
	valgrind --leak-check=full --verbose --track-origins=yes --log-file=leaks.txt ./$(NAME)

.PHONY: all clean fclean re sane val vall test tclean libmlx libft libft-clean full-clean
