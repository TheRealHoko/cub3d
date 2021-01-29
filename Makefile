# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 18:10:22 by jzeybel           #+#    #+#              #
#    Updated: 2021/01/25 17:37:53 by jzeybel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC  = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = std/ft_atoll.c \
	  std/ft_calloc.c \
	  std/ft_lltoa.c \
	  std/ft_ulltoa_base.c \
	  ctype/ft_isdigit.c \
	  ctype/ft_isdigit_one.c \
	  ctype/ft_tolower.c \
	  ctype/ft_toupper.c \
	  ctype/ft_isprint.c \
	  ctype/ft_isalnum.c \
	  ctype/ft_isalpha.c \
	  ctype/ft_isascii.c \
	  put/ft_putchar_fd.c \
	  put/ft_putstr_fd.c \
	  put/ft_putendl_fd.c \
	  put/ft_putnbr_fd.c \
	  put/ft_putbase_fd.c \
	  str/ft_memchr.c \
	  str/ft_strlen.c \
	  str/ft_split.c \
	  str/ft_bzero.c \
	  str/ft_memcmp.c \
	  str/ft_strchr.c \
	  str/ft_strncmp.c \
	  str/ft_memcpy.c \
	  str/ft_strdup.c \
	  str/ft_strnstr.c \
	  str/ft_memmove.c \
	  str/ft_strjoin.c \
	  str/ft_strrchr.c \
	  str/ft_memset.c \
	  str/ft_strlcat.c \
	  str/ft_strtrim.c \
	  str/ft_memccpy.c \
	  str/ft_strlcpy.c \
	  str/ft_substr.c \
	  str/ft_strmapi.c \
	  lst/ft_lstnew.c \
	  lst/ft_lstadd_front.c \
	  lst/ft_lstsize.c \
	  lst/ft_lstlast.c \
	  lst/ft_lstadd_back.c \
	  lst/ft_lstiter.c \
	  lst/ft_lstdelone.c \
	  lst/ft_lstclear.c \
	  lst/ft_lstmap.c

HEADERS = libft.h

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

debug : CFLAGS += -g -fsanitize=address
debug : all

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

redebug : fclean debug

.PHONY :  all debug redebug clean fclean re 
