# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:34:36 by ehalmkro          #+#    #+#              #
#    Updated: 2019/12/18 17:36:41 by ehalmkro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
SRC = main.c
LIB = Libft/
FLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRC:.c=.o)

all: $(NAME)
$(NAME):
				make -C Libft
				gcc $(FLAGS) -c $(SRC)
				gcc -o $(NAME) $(OBJECTS) -L $(LIB) -lft
clean:
				rm -f $(OBJECTS)
				make -C libft clean
fclean: clean
				rm -f $(NAME)
				make -C libft fclean
re: fclean all
