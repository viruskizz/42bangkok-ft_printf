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

SRC_DIR		= ./srcs
SRCS		= 	$(SRC_DIR)/ft_printf.c \
				$(SRC_DIR)/ft_printf_utils.c \
				$(SRC_DIR)/format_utils.c \
				$(SRC_DIR)/format_pcs.c \
				$(SRC_DIR)/conversion_type.c \
				$(SRC_DIR)/conversion_flag.c \
				$(SRC_DIR)/conversion_width.c \
				$(SRC_DIR)/conversion_c.c \
				$(SRC_DIR)/conversion_d.c \
				$(SRC_DIR)/conversion_s.c \
				$(SRC_DIR)/conversion_p.c \
				$(SRC_DIR)/conversion_u.c \
				$(SRC_DIR)/conversion_x.c

OBJS		= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MYUTILS)
	ar -rcs $(NAME) $(OBJS)

.c.o: 		
	$(CC) $(CFLAGS) -I $(SRC_DIR) -I $(LIBFT_DIR) -c $< -o $(<:.c=.o)

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

test: re
	@$(CC) main.c -lftprintf -L . -o runner.out
	@echo "\033[0;32m=== RUNNER ===\033[0m"
	@./runner.out

testmem: re
	@$(CC) $(CFLAGS) main.c -lftprintf -L . -o runner.out
	@echo "\033[0;32m=== RUNNER ===\033[0m"
	@valgrind -q --leak-check=full --track-origins=yes ./runner.out
	
.PHONY: all clean fclean re