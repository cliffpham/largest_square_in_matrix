# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpham <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 15:14:19 by cpham             #+#    #+#              #
#    Updated: 2019/04/16 15:21:55 by cpham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = bsq
SRC = *.c
INCLUDES = *.h

all: $(NAME)

$(NAME):
	@$(CC) $(SRC) $(FLAGS) -I $(INCLUDES) -o $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
