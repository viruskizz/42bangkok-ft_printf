# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 00:08:16 by araiva            #+#    #+#              #
#    Updated: 2022/03/24 00:08:18 by araiva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

INCS_DIR	= ./includes
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
# LFLAGS		= -L $(LIBFT_DIR) -l ft

SRC_DIR		= ./srcs
SRCS		= $(SRC_DIR)/ft_printf.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -rcs $(NAME) $(OBJS)

.c.o: 		
	$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $(<:.c=.o)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

bonus: all

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re