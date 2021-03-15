# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 17:22:52 by ksiren            #+#    #+#              #
#    Updated: 2021/03/15 17:19:37 by ksiren           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RM = rm -f

SRC = srcs/main.c srcs/map_funcs.c srcs/drawings.c

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

INCL = srcs/cub.h


OBJ = $(SRC:.c=.o)

GOBJ = $(GNL:.c=.o)


%.o: %.c $(INCL)
		$(CC) $(CFLAGS) -I ./mlx/mlx.h -c $< -o $@

$(NAME): $(OBJ)
		make -C ./mlx/
		make -C ./libft/
		make -C ./get_next_line/
		$(CC) $(GNL) -L./mlx -framework OpenGL -framework AppKit -lmlx -L./libft -lft $(OBJ) -o $(NAME)

all: $(NAME)

bonus: $(NAME)
		$(CC) $(CFLAGS) $(BONUS)
		ar rc $(NAME) $(OBJBNS)

clean:
		make clean -C ./libft
		make clean -C ./mlx
		make clean -C ./get_next_line/
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
