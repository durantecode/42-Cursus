# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 00:05:22 by ldurante          #+#    #+#              #
#    Updated: 2021/09/07 21:34:31 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DECLARATIONS #

NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = includes
LIBFT = libft
RM = rm -rf
MAKE = make
DEBUG = -g3 -fsanitize=address
MAP = map

MLX = mlx
MLX_LINK = -lmlx -framework OpenGL -framework AppKit

# COLORS #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

# SOURCES & OBJECTS #

SRCS = srcs/main.c srcs/get_next_line.c srcs/map.c srcs/draw_map.c srcs/error.c srcs/image.c srcs/input.c
OBJS = $(SRCS:.c=.o)

# RULES # $(DEBUG)

all: $(NAME)
	
$(NAME): $(OBJS) 
		 $(MAKE) all -C $(LIBFT)
		 $(CC) $(FLAGS) $(OBJS) libft/libft.a $(MLX_LINK) -o $(NAME)
	 	 @echo "$(GREEN) **** SO_LONG COMPILED **** $(NO_COLOR)"
		
test: all
		@echo "$(YELLOW) **** RUN TEST SO_LONG **** $(NO_COLOR)"
		@read -p "Select map number: " map; \
		./so_long maps/map0$${map}.ber
		
normi:  
		norminette -R CheckForbiddenSourceHeaders srcs/*.c includes/*.h

clean:
		 $(RM) $(OBJS)
		 $(MAKE) clean -C $(LIBFT)
		 $(MAKE) clean -C $(MLX)
		 @echo "$(RED) **** CLEAN DONE **** $(NO_COLOR)"

fclean: clean
		 $(RM) $(LIBFT)/$(LIBFT).a
		 $(RM) $(NAME)
		 $(RM) libmlx.dylib
		 $(RM) so_long
		 @echo "$(RED) **** FCLEAN DONE **** $(NO_COLOR)"

re: fclean all

.PHONY: all re clean fclean test