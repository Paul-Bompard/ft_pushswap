# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbompard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/12 10:33:25 by pbompard          #+#    #+#              #
#    Updated: 2016/05/12 10:33:26 by pbompard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC = gcc

#--------------Name-------------------------#
NAME = push_swap

#--------------Sources----------------------#
SRC = main.c

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

HEAD = ./includes

#--------------Actions----------------------#
all: $(NAME)

$(NAME):
	@$(CC) $(SRC) $(CFLAGS) -I $(HEAD) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re