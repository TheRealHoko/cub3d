# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 18:10:22 by jzeybel           #+#    #+#              #
#    Updated: 2021/03/25 18:38:02 by jzeybel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC  = gcc	

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src

PARSE_DIR = parser

SRC = main.c \
	  $(PARSE_DIR)/ft_parser.c \
	  $(PARSE_DIR)/ft_res_texture_color.c \
	  $(PARSE_DIR)/ft_checks.c \

TMP = tmp

INC = -I./inc \
	-I./lib/libft/inc

LIB = lib

LIBFT = -L $(LIB)/libft -lft

LIBMLX = -L $(LIB)/minilibx-linux -lmlx -lXext -lX11 -lm

DBRULE =

OBJ = $(addprefix $(TMP)/,$(SRC:.c=.o))

#if bug check rule all in make of libft
$(NAME) : $(OBJ)
	make -C $(LIB)/libft $(DBRULE)
	make -C $(LIB)/minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX)

all : $(NAME)

debug : CFLAGS += -g
debug : DBRULE += debug
debug : all

$(TMP)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(TMP)
	mkdir -p $(TMP)/$(PARSE_DIR)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

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
