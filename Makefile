# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:08:47 by cmeunier          #+#    #+#              #
#    Updated: 2021/06/25 18:21:27 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philosopher

HEADER		=		incs/

COMPILER	=		gcc #on mac, to change later

FLAGS		=		-Wall -Wextra -Werror

LEAKS		=		-g3 -fsanitize=address -fsanitize=leak

SRC_PATH	=		srcs/

SRC_NAME	=		main.c					\
					parsing/parsing_main.c	\

SRC			=		$(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ			=		$(SRC:.c=.o)

all: 				$(NAME)

.c.o:
					$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME):			$(OBJ)
					$(CC) $(FLAGS) $(OBJ) -I$(HEADER) -o $(NAME) 
					@echo $(NAME) created

clean:
					/bin/rm -f  $(OBJ)
					@echo Objects and libraries cleaned

fclean:				clean
					@/bin/rm -f $(NAME)
					@echo $(NAME) deleted

re:					fclean all

.PHONY:				all clean fclean re