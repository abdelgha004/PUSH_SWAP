# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 06:04:14 by aakourya          #+#    #+#              #
#    Updated: 2025/12/28 17:14:41 by aakourya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = cc
CFLAGS = -Wall -Wextra -Werror
AR     = ar -rcs
RM     = rm -f

NAME = libpushswap.a
SRC  = 	operations/push.c operations/swap.c operations/rotate.c operations/rev_rotate.c \
		utils/ft_atoi.c utils/ft_split.c utils/ft_substr.c utils/helpers.c \
		utils/ft_lstadd_back.c utils/ft_lstnew.c utils/ft_lstclear.c \
		init_stack.c
OBJ  = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re