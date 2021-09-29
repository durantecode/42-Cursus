# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 13:06:54 by ldurante          #+#    #+#              #
#    Updated: 2021/09/30 01:17:39 by ldurante         ###   ########.fr        #
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

# Generates "n" random integers between -10000 and 10000 and copies them into nums.tmp #

nums: all 
		@touch moves.tmp nums.tmp
		@echo "$(YELLOW) **** Generate random numbers **** $(NO_COLOR)"
		@read -p "How many numbers: " n; \
		seq -10000 10000 | sort -R | head -n $${n} | tr '\n' ' ' > nums.tmp

push:
		@./push_swap $(shell cat nums.tmp) > moves.tmp
		@cat moves.tmp
		@echo "$(GREEN) \nMOVEMENTS: $(NO_COLOR)";
		@cat moves.tmp | wc -l | tr -d " ";
		@echo "$(RED) \nCHECKER: $(NO_COLOR)";
		@./push_swap $(shell cat nums.tmp) | ./checker $(shell cat nums.tmp);
		@rm moves.tmp
		@rm nums.tmp
	 
normi:  
		norminette -R CheckForbiddenSourceHeaders libft/*.c libft/*.h srcs/*.c includes/*.h 

clean:
		 $(RM) $(OBJS)
		 $(RM) moves.tmp
		 $(RM) nums.tmp
		 $(MAKE) clean -C $(LIBFT)
		 @echo "$(RED) **** CLEAN DONE **** $(NO_COLOR)"

fclean: clean
		 $(RM) $(LIBFT)/$(LIBFT).a
		 $(RM) $(NAME)
		 @echo "$(RED) **** FCLEAN DONE **** $(NO_COLOR)"

re: fclean all

.PHONY: all re clean fclean nums push normi