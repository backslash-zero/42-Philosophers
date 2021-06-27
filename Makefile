# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:08:47 by cmeunier          #+#    #+#              #
#    Updated: 2021/06/27 16:34:05 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philosopher

HEADER		=		incs/

COMPILER	=		gcc

FLAGS		=		-Wall -Wextra -Werror

THREADING	=		-pthread

LEAKS		=		-g3 -fsanitize=address -fsanitize=leak

SRC_PATH	=		srcs/

SRC_NAME	=		main.c						\
					debug/debug.c				\
					errors/error_1.c			\
					parsing/parsing_main.c		\
					parsing/parsing_getargs.c	\
					parsing/parsing_utils_1.c		\
					utils/utils_1.c				\


SRC			=		$(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ			=		$(SRC:.c=.o)

all: 				$(NAME)

.c.o:
					$(COMPILER) $(FLAGS) $(THREADING) -c $< -o $@

$(NAME):			$(OBJ)
					$(COMPILER) $(FLAGS) $(THREADING) $(OBJ) -I$(HEADER) -o $(NAME) 
					@echo $(NAME) created

clean:
					/bin/rm -f  $(OBJ)
					@echo Objects and libraries cleaned

fclean:				clean
					@/bin/rm -f $(NAME)
					@echo $(NAME) deleted

re:					fclean all

.PHONY:				all clean fclean re