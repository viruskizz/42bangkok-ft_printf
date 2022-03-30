# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 17:47:41 by araiva            #+#    #+#              #
#    Updated: 2022/03/30 17:47:42 by araiva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB	 = ar -rcs
RM = /bin/rm -f
BUILD_DIR = ./build
SRC_DIRS = ./
INCS_DIR = ./

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_itoa.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_substr.c \
		ft_toupper.c \
		my_printlen.c \
		my_strrev.c \
		my_ith.c \
		my_memsize.c \
		my_strcat.c \
		my_strtoupper.c \
		my_realloc.c


OBJS = $(SRCS:%=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR)/$(NAME)

$(BUILD_DIR)/$(NAME): $(OBJS) $(INCS)
	ar -rcs	$(NAME) $(OBJS)

$(BUILD_DIR)/%.c.o: %.c	
	mkdir -p $(dir $@)	
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:		
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
