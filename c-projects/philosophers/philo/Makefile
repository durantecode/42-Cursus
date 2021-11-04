# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 12:11:44 by ldurante          #+#    #+#              #
#    Updated: 2021/11/03 14:19:45 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DECLARATIONS #

NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra
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

SRCS = srcs/main.c srcs/threads.c

# SRCS_UTILS = srcs_utils/ft_putchar_fd.c srcs_utils/ft_putendl_fd.c srcs_utils/ft_putstr_fd.c srcs_utils/ft_split.c \
			 srcs_utils/ft_strjoin.c srcs_utils/ft_strncmp.c srcs_utils/ft_strlen.c srcs_utils/ft_strdup.c

OBJS = $(SRCS:.c=.o)
OBJS_UTILS = $(SRCS_UTILS:.c=.o)

# RULES #

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_UTILS)
	@$(MAKE) -s all -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_UTILS) libft/libft.a -lpthread -o $(NAME)
	@echo "$(GREY) Philo compiled $(GREEN) ✔✔✔ $(NO_COLOR)"

test: all
	@echo "$(YELLOW) **** Running test Philo **** $(NO_COLOR)"
	./philo 5 400 200 200 5

normi:
	norminette -R CheckForbiddenSourceHeaders srcs/*.c srcs_utils/*.c includes/*.h

clean:
	@clear
	@$(RM) $(OBJS) $(OBJS_UTILS)
	@$(MAKE) clean -C libft
	@echo "$(RED) **** Object files removed **** $(NO_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) libft/libft.a
	@echo "$(RED) **** Fclean done **** $(NO_COLOR)"

re: fclean all

.PHONY: all re clean fclean test

.SILENT: $(OBJS) $(OBJS_UTILS)