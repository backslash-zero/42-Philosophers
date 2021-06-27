# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celestin <celestin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:08:47 by cmeunier          #+#    #+#              #
#    Updated: 2021/06/26 17:37:00 by celestin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philosopher

HEADER		=		incs/

COMPILER	=		gcc

FLAGS		=		-Wall -Wextra -Werror

THREADING	=		-lpthread

LEAKS		=		-g3 -fsanitize=address -fsanitize=leak

SRC_PATH	=		srcs/

SRC_NAME	=		main.c					\
					parsing/parsing_main.c	\

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