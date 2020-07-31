# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lclay <lclay@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/06 19:19:28 by lclay             #+#    #+#              #
#    Updated: 2020/03/15 15:33:06 by lclay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME = libftprintf.a

#Compiling flags
CC = gcc
FLAGS = -Wall -Wextra -Werror

#Folders
SRCS_DIR = srcs/
LIBFT_DIR = libft/
INCL_DIR = includes/
OBJS_DIR = objs/

#Source files and object files
SRCS_FILES = 	ft_printf.c\
				char.c\
				int.c\
				int2.c\
				string.c\
				udecimalint.c\
				float.c\
				float2.c\
				float3.c\
				hex.c\
				hex2.c\
				octal.c\
				octal2.c\
				pointer.c\
				percent.c\
				utils.c\
				utils2.c\
				length.c\
				parse.c\
				mem.c

OBJS_FILES = $(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.c=.o))

#Paths
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

#Colors
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#all rule
all: $(NAME)

$(NAME): $(OBJS_FILES)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS_FILES)
	@ranlib $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCL_DIR)/ft_printf.h
	@mkdir -p objs
	@$(CC) $(FLAGS) -I $(INCL_DIR) -o $@ -c $<

clean:
	@rm -f $(OBJS_FILES)
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C ./$(LIBFT_DIR) fclean

re: fclean all
