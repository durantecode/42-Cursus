# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 22:07:55 by ldurante          #+#    #+#              #
#    Updated: 2021/10/15 16:59:17 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DECLARATIONS #

NAME = pipex
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
MAKE = make
DEBUG = -g3 -fsanitize=address

# COLORS #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
GREY = \033[2;37m
MAGENTA = \033[0;35m
CURSIVE = \033[3m
NO_COLOR = \033[0m

# SOURCES & OBJECTS #

SRCS = srcs/main.c srcs/pipex.c
SRCS_UTILS = srcs_utils/ft_putchar_fd.c srcs_utils/ft_putendl_fd.c srcs_utils/ft_putstr_fd.c srcs_utils/ft_split.c \
			 srcs_utils/ft_strjoin.c srcs_utils/ft_strncmp.c srcs_utils/ft_strlen.c srcs_utils/ft_strdup.c

OBJS = $(SRCS:.c=.o)
OBJS_UTILS = $(SRCS_UTILS:.c=.o)

# RULES #

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_UTILS)
		 @echo "$(MAGENTA) **** Creating Objects... **** $(NO_COLOR)"
	 	 @echo "$(GREEN) ✔ $(NO_COLOR)"
	 	 @$(CC) $(FLAGS) $(OBJS) $(OBJS_UTILS) -o $(NAME)
		 @echo "$(GREY) **** Compiling Pipex... **** $(NO_COLOR)"
	 	 @echo "$(GREEN) ✔ $(NO_COLOR)"
		
test:   all
		@echo "$(YELLOW) **** Running test Pipex **** $(NO_COLOR)"
		./pipex file1 "ls -l" "wc -l" file2

normi:  
		norminette -R CheckForbiddenSourceHeaders srcs/*.c srcs_utils/*.c includes/*.h

clean:
		@clear
		@$(RM) $(OBJS) $(OBJS_UTILS)
		@echo "$(RED) **** Objects files removed **** $(NO_COLOR)"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(RED) **** Fclean done **** $(NO_COLOR)"

re: fclean all

.PHONY: all re clean fclean print test

.SILENT: $(OBJS) $(OBJS_UTILS)