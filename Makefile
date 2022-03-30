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
RM 			= /bin/rm -f

INCS_DIR	= ./includes
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

BUILD_DIR	= build
SRC_DIR		= ./srcs
SRCS		= 	ft_printf.c \
				ft_printf_utils.c \
				format_utils.c \
				conversion_type.c \
				conversion_flag.c \
				conversion_width.c \
				conversion_pcs.c \
				misc/conversion_c.c \
				misc/conversion_d.c \
				misc/conversion_s.c \
				misc/conversion_p.c \
				misc/conversion_u.c \
				misc/conversion_x.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS)
	@echo "Done!"

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

bonus: all

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

test: re
	@$(CC) main.c -lftprintf -L . -I $(INCS_DIR) -o runner.out
	@echo "\033[0;32m=== RUNNER ===\033[0m"
	@./runner.out

testmem: re
	@$(CC) $(CFLAGS) main.c -lftprintf -L . -I $(INCS_DIR) -o runner.out
	@echo "\033[0;32m=== RUNNER ===\033[0m"
	@valgrind -q --leak-check=full --track-origins=yes ./runner.out
	
.PHONY: all clean fclean re