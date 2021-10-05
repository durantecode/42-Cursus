# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 13:00:07 by ldurante          #+#    #+#              #
#    Updated: 2021/10/05 18:30:14 by ldurante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES & OBJECTS #

SRCS = ft_printf.c \
		check_format.c \
		check_flags.c \
		type_c.c \
		type_s.c \
		type_p.c \
		type_diu.c \
		type_x.c \
		width_no_precision.c \
		width_precision.c \
		base_hex_functions.c \
		ft_uitoa.c \

OBJS = $(SRCS:.c=.o)

# RULES #

all: $(OBJS) 
				 
clean:
	 @rm -f $(OBJS)

.PHONY: all clean