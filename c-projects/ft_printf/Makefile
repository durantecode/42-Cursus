# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 13:00:07 by ldurante          #+#    #+#              #
#    Updated: 2021/06/23 01:29:11 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DECLARATIONS #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADER = includes
LIBFT = libft
RM = rm -f
RM_F = rm -rf
AR = ar rcs
MAKE = make

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

# SOURCES & OBJECTS #

SOURCES = ft_printf.c check_format.c check_flags.c s_type.c c_type.c diu_type.c \
		p_type.c x_type.c base_hex_functions.c width_no_preci.c width_precission.c \
		ft_uitoa.c

OBJECTS = $(SOURCES:.c=.o)

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJECTS))

# RULES #

all: $(NAME)

$(NAME): $(OBJS) 
		 $(MAKE) all -C $(LIBFT)
		 cp libft/libft.a $(NAME)
		 $(AR) $(NAME) $(OBJS)
		 @echo "$(GREEN) **** MAKE DONE **** $(NO_COLOR)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)/ft_printf.h
		 		 mkdir -p objs
		 		 $(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<
				 
test: 	all
		$(CC) -c main.c
		$(CC) main.o $(NAME)
		@echo "$(YELLOW) **** RUN TEST MAIN **** $(NO_COLOR)"
		./a.out | cat -e
		$(RM) main.o a.out

clean:
		 $(RM) $(OBJS)
		 $(RM_F) $(OBJS_DIR)
		 $(MAKE) clean -C $(LIBFT)
		 @echo "$(RED) **** CLEAN DONE **** $(NO_COLOR)"

fclean: clean
		 $(RM) $(LIBFT)/$(LIBFT).a
		 $(RM) $(NAME)
		 @echo "$(RED) **** FCLEAN DONE **** $(NO_COLOR)"

re: fclean all

.PHONY: all re clean fclean test