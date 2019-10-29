#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 01:16:19 by smaksymy          #+#    #+#              #
#    Updated: 2017/10/26 10:35:58 by smaksymy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= wolf3d

SRC    = src/color.c \
	src/init.c \
	src/load.c \
	src/init_start.c \
	src/main.c \
	src/make_map.c \
	src/make_map2.c \
	src/minimap.c \
	src/ray.c \
	src/texture.c

SUBMAKE = ./libft

CD = cd ..

MAKE = make

OBJECT = $(SRC:.c=.o)

CC  = gcc

FLAGS   = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

LIB = -L./libft -lft -I.

all : $(NAME)

$(NAME): $(OBJECT)
	cd $(SUBMAKE) && $(MAKE) && $(CD)
	$(CC) $(FLAGS) -o $(NAME) $(MLX_FLAGS) $(OBJECT) $(LIB)

clean :
	rm -rf src/*.o
	rm -rf libft/*.o

fclean : clean
	rm -rf wolf3d
	rm -rf libft/libft.a

re : fclean all