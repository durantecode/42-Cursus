# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 13:06:54 by ldurante          #+#    #+#              #
#    Updated: 2021/09/21 22:04:17 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DECLARATIONS #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = includes
LIBFT = libft
RM = rm -rf
MAKE = make
DEBUG = -g3 -fsanitize=address

# COLORS #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

# TESTS #

1 = 2 1 3 6 5 8
2 = 68 39 1 0 104 56 9 188
3 = 123 23 45 73 23 78 1 79 90 56 789 654 342

# SOURCES & OBJECTS #

SRCS =  srcs/main.c srcs/push.c srcs/swap.c srcs/rotate.c srcs/rev_rotate.c srcs/error.c
		
OBJS = $(SRCS:.c=.o)

# RULES #

all: $(NAME)
	
$(NAME): $(OBJS)
		 $(MAKE) all -C $(LIBFT)
		 $(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)
	 	 @echo "$(GREEN) **** PUSH_SWAP COMPILED **** $(NO_COLOR)"
		
test: all
		@echo "$(YELLOW) **** RUN TEST PUSH_SWAP **** $(NO_COLOR)"
		@read -p "Select test number: " test; \
		make test_$${test} \
		
test_1: all	
		./push_swap $(1)
test_2: all
		./push_swap $(2)
test_3: all	
		./push_swap $(3)
test_4: all
		./push_swap $(4)
test_5: all	
		./push_swap $(5)
test_6: all
		./push_swap $(6)

normi:  
		norminette -R CheckForbiddenSourceHeaders libft/*.c libft/*.h srcs/*.c includes/*.h 

clean:
		 $(RM) $(OBJS)
		 $(MAKE) clean -C $(LIBFT)
		 @echo "$(RED) **** CLEAN DONE **** $(NO_COLOR)"

fclean: clean
		 $(RM) $(LIBFT)/$(LIBFT).a
		 $(RM) $(NAME)
		 @echo "$(RED) **** FCLEAN DONE **** $(NO_COLOR)"

re: fclean all

.PHONY: all re clean fclean test normi