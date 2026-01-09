# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 06:04:14 by aakourya          #+#    #+#              #
#    Updated: 2026/01/09 14:29:19 by aakourya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = cc
CFLAGS = -Wall -Wextra -Werror
RM     = rm -f

NAME = push_swap
BONUS = checker

SRC  = 	operations/push.c operations/swap.c operations/rotate.c operations/rev_rotate.c \
		utils/ft_atol.c utils/ft_split.c utils/ft_substr.c utils/helpers.c \
		utils/ft_lstadd_back.c utils/ft_lstnew.c utils/ft_lstclear.c \
		stack/init_stack.c stack/stack_utils.c

PUSH_SRC = $(SRC) \
		sort/sort_helpers.c sort/sort.c sort/sort_small.c \
		sort/sort_medium.c sort/sort_large.c main.c
PUSH_OBJ = $(PUSH_SRC:.c=.o)

CHECKER_SRC = $(SRC) \
		CHECKER/checker.c CHECKER/checker_utils.c CHECKER/get_next_line/get_next_line.c \
		CHECKER/get_next_line/get_next_line_utils.c
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

all: $(NAME)

$(NAME): $(PUSH_OBJ)
	$(CC) $(CFLAGS) $(PUSH_OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) -o $(BONUS)

clean:
	$(RM) $(PUSH_OBJ) $(CHECKER_OBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re