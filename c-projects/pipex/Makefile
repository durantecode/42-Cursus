# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 22:07:55 by ldurante          #+#    #+#              #
#    Updated: 2021/10/01 02:33:08 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DECLARATIONS #

NAME = pipex
CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = includes
LIBFT = libft
RM = rm -f
MAKE = make

# COLORS #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
GREY = \033[2;37m
MAGENTA = \033[0;35m
CURSIVE = \033[3m
NO_COLOR = \033[0m

# SOURCES & OBJECTS #

SRCS = srcs/main.c

OBJS = $(SRCS:.c=.o)

# RULES #

all: $(NAME)
	
$(NAME): $(OBJS) 
		 @$(MAKE) -s all -C $(LIBFT)
	 	 @echo "$(GREY) **** Compiling Pipex... **** $(NO_COLOR)"
		 @$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)
		 @echo "$(GREEN) ✔️ $(NO_COLOR)"
		
test: 	all
		@echo "$(YELLOW) **** Running test Pipex **** $(NO_COLOR)"
		@./pipex

normi:  
		norminette -R CheckForbiddenSourceHeaders libft/*.c libft/*.h libft/ft_printf/*.c \
		libft/ft_printf/*.h srcs/*.c includes/*.h

clean:
		 @$(RM) $(OBJS)
		 @$(MAKE) clean -C $(LIBFT)
		 @echo "$(RED) **** Objects files removed **** $(NO_COLOR)"

fclean: clean
		 @$(RM) $(LIBFT)/$(LIBFT).a
		 @$(RM) $(NAME)
		 @echo "$(RED) **** Fclean done **** $(NO_COLOR)"

re: fclean all

.PHONY: all re clean fclean test