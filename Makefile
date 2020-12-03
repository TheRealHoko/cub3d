# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 18:10:22 by jzeybel           #+#    #+#              #
#    Updated: 2020/12/03 17:45:11 by jzeybel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC  = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_isdigit.c ft_memchr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_strlen.c ft_tolower.c ft_bzero.c ft_memcmp.c ft_putendl_fd.c \
	  ft_strchr.c ft_strncmp.c ft_toupper.c ft_calloc.c ft_isprint.c \
	  ft_memcpy.c ft_strdup.c ft_strnstr.c ft_isalnum.c ft_memmove.c \
	  ft_putnbr_fd.c ft_strjoin.c ft_strrchr.c ft_isalpha.c ft_memset.c \
	  ft_strlcat.c ft_strtrim.c ft_isascii.c ft_memccpy.c ft_strlcpy.c \
	  ft_substr.c ft_strmapi.c ft_itoa.c ft_split.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c

HEADERS = libft.h

OBJ = $(SRC:.c=.o)

OBJ_BON = $(BONUS:.c=.o)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

bonus : $(NAME) $(OBJ_BON)
	ar rcs $(NAME) $(OBJ_BON)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(OBJ_BON)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : $(NAME) all bonus clean fclean re 
