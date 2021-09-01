# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 00:05:22 by ldurante          #+#    #+#              #
#    Updated: 2021/09/01 16:47:07 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DECLARATIONS #

NAME = so_long.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = includes
LIBFT = libft
RM = rm -rf
MAKE = make

MLX = mlx
MLX_LINK = -Imlx -framework OpenGL -framework AppKit

# COLORS #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

# SOURCES & OBJECTS #

SRCS = srcs/main.c srcs/get_next_line.c srcs/map.c
OBJS = $(SRCS:.c=.o)

# RULES #

all: $(NAME)
	
$(NAME): $(OBJS) 
		 $(MAKE) all -C $(LIBFT)
		 $(MAKE) all -C $(MLX)
		 mv mlx/libmlx.dylib .
		 $(CC) $(FLAGS) $(OBJS) libft/libft.a libmlx.dylib $(MLX_LINK) -o so_long
	 	 @echo "$(GREEN) **** SO_LONG COMPILED **** $(NO_COLOR)"
		
test: 	all
		@echo "$(YELLOW) **** RUN TEST SO_LONG **** $(NO_COLOR)"
		./so_long maps/map01.ber

normi:  
		norminette -R CheckForbiddenSourceHeaders $(SRCS) $(HEADER)

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