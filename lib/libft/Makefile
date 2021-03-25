# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 18:10:22 by jzeybel           #+#    #+#              #
#    Updated: 2021/03/25 18:38:38 by jzeybel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC  = gcc

CFLAGS = -Wall -Wextra -Werror

TMP = tmp

SRC_DIR = src

SRC = math/ft_pow.c \
	  std/ft_atoll.c \
	  std/ft_calloc.c \
	  std/ft_lltoa.c \
	  std/ft_ulltoa_base.c \
	  ctype/ft_isdigit.c \
	  ctype/ft_isrange.c \
	  ctype/ft_tolower.c \
	  ctype/ft_toupper.c \
	  ctype/ft_isprint.c \
	  ctype/ft_isalnum.c \
	  ctype/ft_isalpha.c \
	  ctype/ft_isascii.c \
	  ctype/ft_ischarset.c \
	  put/ft_putchar_fd.c \
	  put/ft_putstr_fd.c \
	  put/ft_putendl_fd.c \
	  put/ft_putnbr_fd.c \
	  put/ft_putbase_fd.c \
	  str/ft_tablen.c \
	  str/ft_freetab.c \
	  str/ft_memchr.c \
	  str/ft_strlen.c \
	  str/ft_split.c \
	  str/ft_bzero.c \
	  str/ft_memcmp.c \
	  str/ft_strchr.c \
	  str/ft_strchri.c \
	  str/ft_strncmp.c \
	  str/ft_strisset.c \
	  str/ft_memcpy.c \
	  str/ft_strdup.c \
	  str/ft_strnstr.c \
	  str/ft_memmove.c \
	  str/ft_strjoin.c \
	  str/ft_strjoinfree.c \
	  str/ft_strrchr.c \
	  str/ft_memset.c \
	  str/ft_strlcat.c \
	  str/ft_strtrim.c \
	  str/ft_memccpy.c \
	  str/ft_strlcpy.c \
	  str/ft_substr.c \
	  str/ft_substrfree.c \
	  str/ft_foreach.c \
	  str/get_next_line.c \
	  str/ft_getdelim.c \
	  lst/ft_lstnew.c \
	  lst/ft_lstadd_front.c \
	  lst/ft_lstsize.c \
	  lst/ft_lstlast.c \
	  lst/ft_lstadd_back.c \
	  lst/ft_lstiter.c \
	  lst/ft_lstdelone.c \
	  lst/ft_lstclear.c \
	  lst/ft_lstmap.c \
	  lst/ft_del.c \
	  lst/ft_lstprint.c \

OBJ = $(addprefix $(TMP)/,$(SRC:.c=.o))

$(NAME) : mktmp $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

mktmp :
	mkdir -p $(TMP)/math
	mkdir -p $(TMP)/ctype
	mkdir -p $(TMP)/lst
	mkdir -p $(TMP)/put
	mkdir -p $(TMP)/str
	mkdir -p $(TMP)/std

debug : CFLAGS += -g
debug : all

$(TMP)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I./inc -c $< -o $@

clean :
	rm -rf $(TMP)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

redebug : fclean debug

.PHONY :  all debug clean fclean re redebug
