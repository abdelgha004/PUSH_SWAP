# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 06:04:14 by aakourya          #+#    #+#              #
#    Updated: 2025/12/24 11:54:25 by aakourya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = cc
CFLAGS = -Wall -Wextra -Werror
AR     = ar -rcs
RM     = rm -f

NAME = libpushswap.a
SRC  = operations/push.c operations/swap.c operations/rotate.c operations/rev_rotate.c
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