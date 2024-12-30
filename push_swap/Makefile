# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 15:09:35 by yel-haya          #+#    #+#              #
#    Updated: 2024/12/30 08:01:41 by yel-haya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BON_NAME = checker
LIB = libft/libft.a
PRI = printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = helpers.c push_swap.c instructions.c error_check.c helper1.c helper2.c helper3.c helper4.c instructions1.c instructions2.c
BONUS = checker_src/checker_bonus.c checker_src/checker_helpers_bonus.c \
checker_src/get_next_line/get_next_line_bonus.c checker_src/get_next_line/get_next_line_utils_bonus.c \
checker_src/instructions_bonus.c checker_src/error_check_bonus.c checker_src/helper3_bonus.c checker_src/helper4_bonus.c \
checker_src/instructions1_bonus.c checker_src/instructions2_bonus.c checker_src/helpers_bonus.c
libs = ./printf/libftprintf.a ./libft/libft.a

OBJ = $(SRC:.c=.o)
OBJB = $(BONUS:.c=.o)


$(NAME): $(libs) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB) $(PRI)

$(OBJ): %.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJB): %.o: %.c checker_src/get_next_line/get_next_line_bonus.h checker_src/checker_bonus.h push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(BON_NAME)

bonus: $(BON_NAME)

$(libs): 
	@make -C libft
	@make -C printf

$(BON_NAME): $(libs) $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(BON_NAME) $(LIB) $(PRI)

clean:
	@make clean -C libft
	@make clean -C printf
	rm -f $(OBJ) $(OBJB)

fclean: clean
	@make fclean -C libft
	@make fclean -C printf
	rm -f $(NAME) $(BON_NAME)

re: fclean all
.PHONY: clean all fclean re
