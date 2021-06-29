# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 16:59:01 by ldurante          #+#    #+#              #
#    Updated: 2021/06/29 22:30:44 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DECLARATIONS #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
HEADER = libft.h
CC = gcc
RM = rm -f
AR = ar rcs
RED = \033[0;31m
GREEN = \033[0;32m
NO_COLOR = \033[0m

# MANDATORY FUNCTIONS #

SRCS_M = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		 ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
		 ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		 ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
		 ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \

# BONUS FUNCTIONS #

SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		 ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

$(NAME):	$(SRCS_M)
			$(CC) $(FLAGS) -I $(HEADER) -c $(SRCS_M)
			$(AR) $(NAME) $(OBJS_M)

bonus: 		$(NAME)
			$(CC) $(FLAGS) -I $(HEADER) -c $(SRCS_B)
			$(AR) $(NAME) $(OBJS_B)

all: $(NAME)
	 
clean:
	$(RM) $(OBJS_M) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus re clean fclean
