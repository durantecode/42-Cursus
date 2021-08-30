# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 22:07:55 by ldurante          #+#    #+#              #
#    Updated: 2021/07/14 01:43:22 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DECLARATIONS #

NAME = pipex.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = includes
LIBFT = libft
RM = rm -f
AR = ar rcs
MAKE = make

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

# SOURCES & OBJECTS #

SRCS = srcs/main.c

OBJS = $(SRCS:.c=.o)

# RULES #

all: $(NAME)
	
$(NAME): $(OBJS) 
		 $(MAKE) all -C $(LIBFT)
		 cp libft/libft.a $(NAME)
		 $(AR) $(NAME) $(OBJS)
		 $(CC) $(FLAGS) -I $(HEADER) $(NAME) -o pipex
	 	 @echo "$(GREEN) **** PIPEX COMPILED **** $(NO_COLOR)"
		
test: 	all
		@echo "$(YELLOW) **** RUN TEST PIPEX **** $(NO_COLOR)"
		./pipex

clean:
		 $(RM) $(OBJS)
		 $(MAKE) clean -C $(LIBFT)
		 @echo "$(RED) **** CLEAN DONE **** $(NO_COLOR)"

fclean: clean
		 $(RM) $(LIBFT)/$(LIBFT).a
		 $(RM) $(NAME)
		 $(RM) pipex
		 @echo "$(RED) **** FCLEAN DONE **** $(NO_COLOR)"

re: fclean all

.PHONY: all re clean fclean test