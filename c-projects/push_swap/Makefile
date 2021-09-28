# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 13:06:54 by ldurante          #+#    #+#              #
#    Updated: 2021/09/28 22:40:28 by ldurante         ###   ########.fr        #
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
DEBUG = -g -fsanitize=address
TOUCH = touch moves.tmp nums.tmp

# COLORS #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

# SOURCES & OBJECTS #

SRCS =  srcs/main.c srcs/push_swap.c srcs/push.c srcs/swap.c srcs/rotate.c srcs/rev_rotate.c \
		srcs/simplify_stack.c srcs/sort_big.c srcs/sort_small.c srcs/error.c srcs/print_stack.c 
		
OBJS = $(SRCS:.c=.o)

# RULES #

all: $(NAME)
	
$(NAME): $(OBJS)
		 $(MAKE) all -C $(LIBFT)
		 $(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)
	 	 @echo "$(GREEN) **** PUSH_SWAP COMPILED **** $(NO_COLOR)"
		
test: all
		@echo "$(YELLOW) **** RUN TEST PUSH_SWAP **** $(NO_COLOR)"
		@read -p "Select test 100 or 500: " test; \
		make test_$${test} \

test_100: all 
		$(TOUCH)
		@seq -1000 1000 | sort -R | head -n 100 | tr '\n' ' ' > nums.tmp
		@./push_swap $(shell cat nums.tmp) > moves.tmp
		@echo "$(GREEN) \nMovements: $(NO_COLOR)";
		@cat moves.tmp | wc -l | tr -d " ";
		@echo "$(RED) \nChecker: $(NO_COLOR)";
		@./push_swap $(shell cat nums.tmp) | ./checker $(shell cat nums.tmp)
		@rm moves.tmp
		@rm nums.tmp

test_500: all
		touch moves.tmp nums.tmp
		@seq -1000 1000 | sort -R | head -n 500 | tr '\n' ' ' > nums.tmp
		@./push_swap $(shell cat nums.tmp) > moves.tmp
		@echo "$(GREEN) \nMovements: $(NO_COLOR)";
		@cat moves.tmp | wc -l | tr -d " ";
		@echo "$(RED) \nChecker: $(NO_COLOR)";
		@./push_swap $(shell cat nums.tmp) | ./checker $(shell cat nums.tmp)
		@rm moves.tmp
		@rm nums.tmp
			 
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

.PHONY: all re clean fclean test test_100 test_500 normi