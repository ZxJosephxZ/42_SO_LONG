# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 17:33:55 by joseph            #+#    #+#              #
#    Updated: 2023/10/20 12:05:43 by jpajuelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c ft_read_map.c ft_print_map.c ft_key_press.c ft_strlen.c ft_memset.c \
		ft_itoa.c ft_free.c ft_error.c ft_calloc.c ft_bzero.c ft_check_exit.c \
		ft_get_next_line.c ft_strjoin.c ft_strchr.c ft_flood_fill.c ft_duplicate.c \
		ft_parche.c ft_flood_fill_2.c ft_closeimg.c

MLX_DIR = minilibx
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MFLAGS = -ldl -lmlx -L${MLX_DIR} -framework OpenGL -framework AppKit -lz

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

OBJS = $(SRC:.c=.o)


all: $(NAME)

$(NAME):	$(OBJS)
			@make -C $(MLX_DIR)
			@$(CC) $(OBJS) -o $(NAME) $(MFLAGS)

clean:	
		@make -C $(MLX_DIR) -f $(MLX_MAKE) clean
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(OBJS) $(NAME)

re: fclean all
