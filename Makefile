# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 18:10:22 by jzeybel           #+#    #+#              #
#    Updated: 2021/02/15 22:13:58 by jzeybel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC  = gcc	

CFLAGS = -Wall -Wextra -Werror

SRC = main.c

LIB = libft/libft.a

DBRULE =

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	make -C libft $(DBRULE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

all : $(NAME)

debug : CFLAGS += -g -fsanitize=address
debug : DBRULE += redebug
debug : all

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make -C libft/ clean

fclean : clean
	rm -f $(NAME)
	make -C libft/ fclean

re : fclean $(NAME)

redebug : fclean debug

.PHONY :  all debug clean fclean re redebug
