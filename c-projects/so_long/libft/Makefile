# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 16:59:01 by ldurante          #+#    #+#              #
#    Updated: 2021/10/18 20:24:01 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DECLARATIONS #

NAME = libft.a
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

# COLORS #

RED = \033[0;31m
GREEN = \033[0;32m
MAGENTA = \033[0;35m
NO_COLOR = \033[0m

# SOURCES & OBJECTS #

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		 ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
		 ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		 ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
		 ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
		 ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		 ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		 get_next_line.c \

SRCS_PF = ft_printf/ft_printf.c ft_printf/check_format.c ft_printf/check_flags.c ft_printf/type_c.c \
		  ft_printf/type_s.c ft_printf/type_p.c ft_printf/type_diu.c ft_printf/type_x.c ft_printf/width_no_precision.c \
		  ft_printf/width_precision.c ft_printf/base_hex_functions.c ft_printf/ft_uitoa.c \

OBJS = $(SRCS:.c=.o)
OBJS_PF = $(SRCS_PF:.c=.o)

# RULES #

all: $(OBJS) $(OBJS_PF)
		 @echo "$(MAGENTA) **** Compiling Libft... **** $(NO_COLOR)"
		 @$(AR) $(NAME) $(OBJS) $(OBJS_PF)
		 @echo "$(GREEN) ✔ $(NO_COLOR)"

clean:
		@$(RM) $(OBJS) $(OBJS_PF)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus re clean fclean
