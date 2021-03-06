# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 18:10:22 by jzeybel           #+#    #+#              #
#    Updated: 2021/05/09 13:12:00 by jzeybel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC  = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src

PARSE_DIR = parser

ENGINE_DIR = engine

MINIMAP_DIR = minimap

HOOKS_DIR = hooks

SRC = main.c \
	  $(PARSE_DIR)/ft_parser.c \
	  $(PARSE_DIR)/ft_res_texture_color.c \
	  $(PARSE_DIR)/ft_checks.c \
	  $(PARSE_DIR)/ft_error.c \
	  $(ENGINE_DIR)/ray.c \
	  $(ENGINE_DIR)/colors.c \
	  $(ENGINE_DIR)/line.c \
	  $(HOOKS_DIR)/hooks.c \
	  $(MINIMAP_DIR)/ft_minimap.c

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

all : DBRULE += all
all : $(NAME)

debug : CFLAGS += -g
debug : DBRULE += debug
debug : all

$(TMP)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(TMP)/$(PARSE_DIR)
	mkdir -p $(TMP)/$(ENGINE_DIR)
	mkdir -p $(TMP)/$(MINIMAP_DIR)
	mkdir -p $(TMP)/$(HOOKS_DIR)
	$(CC) $(CFLAGS) $(INC) -O3 -o $@ -c $<

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
