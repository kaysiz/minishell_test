# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 13:21:25 by ksiziva           #+#    #+#              #
#    Updated: 2018/09/14 13:21:27 by ksiziva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
PATH_SRC = ./
PATH_OBJ = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =  main.c \
	   ft_env.c \
	   ft_echo.c \
	   ft_setenv.c \
	   ft_unsetenv.c
OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	@$(CC) $(CFLAGS) -I libft/ -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) libft/libft.a
	@echo "$(NAME) created"

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
