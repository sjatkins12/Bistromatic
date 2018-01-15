# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 16:08:22 by ztisnes           #+#    #+#              #
#    Updated: 2018/01/15 03:24:04 by ztisnes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM = bistromatic
FLAGS = -Wall -Werror -Wextra -g
CC = gcc
OBJSRC = $(patsubst %, %.o, $(SRC))
OBJINC = $(patsubst %, %.o, $(INC))

#LS SOURCE
SRC += srcs/addition
SRC += srcs/division
SRC += srcs/evaluate_expression
SRC += srcs/exp_parser
SRC += srcs/input_output
SRC += srcs/modulo
SRC += srcs/multiply
SRC += srcs/queue
SRC += srcs/stack
SRC += srcs/subtract

#GENERAL LIBFT FUNCTIONS
INC += srcs/libft/ft_atoi
INC += srcs/libft/ft_bzero
INC += srcs/libft/ft_handle_error
INC += srcs/libft/ft_isalnum
INC += srcs/libft/ft_isalpha
INC += srcs/libft/ft_isascii
INC += srcs/libft/ft_isdigit
INC += srcs/libft/ft_isprint
INC += srcs/libft/ft_itoa
INC += srcs/libft/ft_lstadd
INC += srcs/libft/ft_lstappend
INC += srcs/libft/ft_lstdel
INC += srcs/libft/ft_lstdelone
INC += srcs/libft/ft_lstiter
INC += srcs/libft/ft_lstmap
INC += srcs/libft/ft_lstnew
INC += srcs/libft/ft_memalloc
INC += srcs/libft/ft_memccpy
INC += srcs/libft/ft_memchr
INC += srcs/libft/ft_memcpy
INC += srcs/libft/ft_memdel
INC += srcs/libft/ft_memmove
INC += srcs/libft/ft_memset
INC += srcs/libft/ft_putchar_fd
INC += srcs/libft/ft_putchar
INC += srcs/libft/ft_putendl_fd
INC += srcs/libft/ft_putendl
INC += srcs/libft/ft_putnbr_fd
INC += srcs/libft/ft_putnbr
INC += srcs/libft/ft_putnstr
INC += srcs/libft/ft_putstr_fd
INC += srcs/libft/ft_putstr
INC += srcs/libft/ft_strcat
INC += srcs/libft/ft_strchr
INC += srcs/libft/ft_strclr
INC += srcs/libft/ft_strcmp_wlen
INC += srcs/libft/ft_strcmp
INC += srcs/libft/ft_strcpy
INC += srcs/libft/ft_strdel
INC += srcs/libft/ft_strdup
INC += srcs/libft/ft_strequ
INC += srcs/libft/ft_striter
INC += srcs/libft/ft_striteri
INC += srcs/libft/ft_strjoin
INC += srcs/libft/ft_strlcat
INC += srcs/libft/ft_strlen
INC += srcs/libft/ft_strmap
INC += srcs/libft/ft_strmapi
INC += srcs/libft/ft_strncat
INC += srcs/libft/ft_strncmp
INC += srcs/libft/ft_strncpy
INC += srcs/libft/ft_strequ
INC += srcs/libft/ft_strnew
INC += srcs/libft/ft_strnjoin
INC += srcs/libft/ft_strnstr
INC += srcs/libft/ft_strrchr
INC += srcs/libft/ft_strsplit
INC += srcs/libft/ft_strstr
INC += srcs/libft/ft_strsub
INC += srcs/libft/ft_strtrim
INC += srcs/libft/ft_tolower_str
INC += srcs/libft/ft_tolower
INC += srcs/libft/ft_toupper
INC += srcs/libft/ft_ullitoa_base
INC += srcs/libft/get_next_line
INC += srcs/libft/is_numstr

all: $(PROGRAM)

$(PROGRAM): $(OBJINC) $(OBJSRC)
	@ echo "Compiling calc program"
	@ $(CC) $(FLAGS) $(OBJINC) $(OBJSRC) -o $(PROGRAM)

%.o: %.c
	@ echo "Compiling $<..."
	@ $(CC) $(FLAGS) -c $< -o $@

clean:
	@ /bin/rm -f $(OBJSRC)
	@ /bin/rm -f $(OBJINC)
	@ echo "Cleaning folders of object files..."

fclean: clean
	@ /bin/rm -f $(PROGRAM)
	@ echo "Removing files and binary..."

re: fclean all
	@ echo "Program Remade"

.PHONY:	all clean fclean re
