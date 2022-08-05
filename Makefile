# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamchur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 17:33:54 by hamchur           #+#    #+#              #
#    Updated: 2022/01/25 17:34:05 by hamchur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

LIB = libft/libft.a

HEADER = includes/push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = sources/push_swap.c \
			sources/operation_push.c \
			sources/operation_reverse.c \
			sources/operation_rotate.c \
			sources/operation_swap.c \
			sources/sort0.c \
			sources/sort1.c \
			sources/sort2.c \
			sources/sort3.c \
			sources/stack_add.c \
			sources/stack_errors.c \
			sources/stack_init.c

SRC_B = sources/checker.c \
			sources/operation_push.c \
			sources/operation_reverse.c \
			sources/operation_rotate.c \
			sources/operation_swap.c \
			sources/sort0.c \
			sources/sort1.c \
			sources/sort2.c \
			sources/sort3.c \
			sources/stack_add.c \
			sources/stack_errors.c \
			sources/stack_init.c

OBJ = $(SRC:.c=.o)

OBJ_B =  $(SRC_B:.c=.o)

all:	libft $(NAME)

libft:	
			@make -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ 

bonus:		libft $(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B)

clean:			
			@rm -rf $(OBJ) $(OBJ_B)
			make -C libft/ clean

fclean:		clean
			@make -C libft/ fclean
			rm -f $(NAME) $(NAME_B)

re:			fclean all

.PHONY: all  libft clean fclean re bonus
