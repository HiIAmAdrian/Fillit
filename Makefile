# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adstan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 16:16:33 by adstan            #+#    #+#              #
#    Updated: 2018/01/29 19:32:50 by adstan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME2 = libt.a

NAME = fillit

SRC =	./lib/ft_memset.c \
		./lib/ft_bzero.c \
		./lib/ft_memcpy.c \
		./lib/ft_memccpy.c \
		./lib/ft_memmove.c \
		./lib/ft_memchr.c \
		./lib/ft_memcmp.c \
		./lib/ft_strlen.c \
		./lib/ft_strdup.c \
		./lib/ft_strcpy.c \
		./lib/ft_strncpy.c \
		./lib/ft_strcat.c \
		./lib/ft_strncat.c \
		./lib/ft_strlcat.c \
		./lib/ft_strchr.c \
		./lib/ft_strrchr.c \
		./lib/ft_strstr.c \
		./lib/ft_strnstr.c \
		./lib/ft_strcmp.c \
		./lib/ft_strncmp.c \
		./lib/ft_atoi.c \
		./lib/ft_isalpha.c \
		./lib/ft_isdigit.c \
		./lib/ft_isalnum.c \
		./lib/ft_isascii.c \
		./lib/ft_isprint.c \
		./lib/ft_toupper.c \
		./lib/ft_tolower.c \
		./lib/ft_memalloc.c \
		./lib/ft_memdel.c \
		./lib/ft_strnew.c \
		./lib/ft_strdel.c \
		./lib/ft_strclr.c \
		./lib/ft_striter.c \
		./lib/ft_striteri.c \
		./lib/ft_strmap.c \
		./lib/ft_strmapi.c \
		./lib/ft_strequ.c \
		./lib/ft_strnequ.c \
		./lib/ft_strsub.c \
		./lib/ft_strjoin.c \
		./lib/ft_strtrim.c \
		./lib/ft_strsplit.c \
		./lib/ft_itoa.c \
		./lib/ft_putchar.c \
		./lib/ft_putstr.c \
		./lib/ft_putendl.c \
		./lib/ft_putnbr.c \
		./lib/ft_putchar_fd.c \
		./lib/ft_putstr_fd.c \
		./lib/ft_putendl_fd.c \
		./lib/ft_putnbr_fd.c \
		./lib/ft_lstnew.c \
		./lib/ft_lstdelone.c \
		./lib/ft_lstdel.c \
		./lib/ft_lstadd.c \
		./lib/ft_lstiter.c \
		./lib/ft_lstmap.c \
		./lib/ft_isprime.c \
		./lib/ft_isperfect.c \
		./lib/ft_abs.c \
		./lib/ft_reverse.c \
		./lib/ft_power.c \
		./lib/ft_abs.c \
		./lib/ft_sqrt.c

SRC_FIL =	checker.c         \
			create_pieces.c   \
			fillit.c          \
			reader.c          \
			prints.c

OBJ = *.o

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME2) $(OBJ)
	@ranlib $(NAME2)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC_FIL) $(NAME2)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME2) $(NAME)

re: fclean all
