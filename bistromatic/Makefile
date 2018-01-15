# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 16:08:22 by ztisnes           #+#    #+#              #
#    Updated: 2018/01/14 16:57:25 by ztisnes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a bistro.a

INC_DIR := includes
SRC_DIR := srcs

HEADER	= libft.h bistro.h

FLAGS	= -c -Wall -Wextra -Werror

INCLS	:= $(INC_DIR)
SRCS	= ($(SRC_DIR)/(ft_atoi.c ft_bzero.c ft_isalnum.c ft_handle_error.c \
ft_isdigit.c ft_isprint.c ft_iswhitespace.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c \
ft_putnbr.c ft_putnstr.c ft_putstr_fd.c ft_putstr.c ft_strcat.c ft_strchr.c \
ft_strclr.c ft_strcmp.c ft_strcmp_wlen.c ft_strcpy.c ft_strdel.c ft_strdup.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_isalnum.c\
ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_ullitoa_base \
get_next_line.c is_numstr.c queue.c stack.c addition.c division.c subtract.c \
multiply.c modulo.c input_output.c exp_parser.c evaluate_expression.c))

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -I $(HEADER)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
