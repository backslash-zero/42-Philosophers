# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:08:47 by cmeunier          #+#    #+#              #
#    Updated: 2021/07/06 15:21:26 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philosopher

HEADER		=		incs/

COMPILER	=		clang

FLAGS		=		-Wall -Wextra -Werror

THREADING	=		-pthread

LEAKS		=		-g3 -fsanitize=address

LEAKS_THRD	=		-g3 -fsanitize=thread

SRC_PATH	=		srcs/

SRC_NAME	=		main.c									\
					debug/debug.c							\
					errors/error_1.c						\
					parsing/parsing_create_forks.c			\
					parsing/parsing_create_philosophers.c	\
					parsing/parsing_getargs.c				\
					parsing/parsing_main.c					\
					parsing/parsing_utils_1.c				\
					threading/philo_actions.c				\
					threading/philo_algo_1.c				\
					threading/philo_murders.c				\
					threading/threads.c						\
					utils/free.c							\
					utils/time.c							\
					utils/utils_1.c							\


SRC			=		$(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ			=		$(SRC:.c=.o)

all: 				$(NAME)

.c.o:
					$(COMPILER) $(FLAGS) $(THREADING) -c $< -o $@

$(NAME):			$(OBJ)
					$(COMPILER) $(FLAGS) $(THREADING) $(OBJ) -I$(HEADER) -o $(NAME) 
					@echo $(NAME) created

check_leaks:		$(OBJ)
					$(COMPILER) $(FLAGS) $(THREADING) $(LEAKS) $(OBJ) -I$(HEADER) -o $(NAME) 
					@echo $(NAME) created with fsanitize

check_threads:		$(OBJ)
					$(COMPILER) $(FLAGS) $(THREADING) $(LEAKS_THRD) $(OBJ) -I$(HEADER) -o $(NAME) 
					@echo $(NAME) created with fsanitize checking threads

clean:
					/bin/rm -f  $(OBJ)
					@echo Objects and libraries cleaned

fclean:				clean
					@/bin/rm -f $(NAME)
					@echo $(NAME) deleted

re:					fclean all

.PHONY:				all clean fclean re