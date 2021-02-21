# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 18:10:22 by jzeybel           #+#    #+#              #
#    Updated: 2021/02/16 18:29:59 by jzeybel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC  = gcc	

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src

PARSE_DIR = parser

SRC = main.c \
	  $(PARSE_DIR)/parser.c

TMP = tmp

INC = inc

LIB = lib

LIBFT = -L $(LIB)/libft -lft

LIBMLX = -L $(LIB)/minilibx-linux -lmlx -lXext -lX11 -lm

DBRULE =

OBJ = $(addprefix $(TMP)/,$(SRC:.c=.o))

$(NAME) : $(OBJ)
	make -C $(LIB)/libft $(DBRULE)
	make -C $(LIB)/minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX)

all : $(NAME)

debug : CFLAGS += -g -fsanitize=address
debug : DBRULE += redebug
debug : all

$(TMP)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(TMP)
	$(CC) -g -I $(INC) -o $@ -c $<

norm :
	norminette $(SRC_DIR)/
	norminette $(INC)/

clean :
	rm -f $(OBJ)
	rm -rf $(TMP)
	make -C $(LIB)/libft clean
	make -C $(LIB)/minilibx-linux clean

fclean : clean
	rm -f $(NAME)
	make clean

re : fclean $(NAME)

redebug : fclean debug

.PHONY :  all clean fclean re
