# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lclay <lclay@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 22:12:27 by lclay             #+#    #+#              #
#    Updated: 2019/09/17 22:32:35 by lclay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_memcpy.c \
		ft_striteri.c \
		ft_memdel.c \
		ft_strjoin.c \
		ft_atoi.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_bzero.c \
		ft_memset.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_isalnum.c \
		ft_putchar.c \
		ft_strmapi.c \
		ft_isalpha.c \
		ft_putchar_fd.c \
		ft_strncat.c \
		ft_isascii.c \
		ft_putendl.c \
		ft_strncmp.c \
		ft_isdigit.c \
		ft_putendl_fd.c \
		ft_strncpy.c \
		ft_isprint.c \
		ft_putnbr.c \
		ft_strnequ.c \
		ft_itoa.c \
		ft_putnbr_fd.c \
		ft_strnew.c \
		ft_putstr.c \
		ft_strnstr.c \
		ft_putstr_fd.c \
		ft_strrchr.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strsplit.c \
		ft_strclr.c \
		ft_strstr.c \
		ft_strcmp.c \
		ft_strsub.c \
		ft_strcpy.c \
		ft_memalloc.c \
		ft_strdel.c \
		ft_strtrim.c \
		ft_memccpy.c \
		ft_strdup.c \
		ft_tolower.c \
		ft_memchr.c \
		ft_strequ.c \
		ft_toupper.c \
		ft_memcmp.c \
		ft_striter.c \

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	
clean:
	/bin/rm -f *.o
	/bin/rm -f *.gch
	/bin/rm -f *.out

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@
