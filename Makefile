# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:34:36 by ehalmkro          #+#    #+#              #
#    Updated: 2020/01/03 12:49:22 by ehalmkro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
SRC = main.c pointlist.c draw_window.c
LIB = Libft/
MLIB = /usr/local/lib
MFLAGS = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRC:.c=.o)

all: $(NAME)
$(NAME):
				make -C $(LIB) > /dev/null
				gcc $(FLAGS) -c $(SRC) > /dev/null
				gcc -o $(NAME) $(OBJECTS) -L $(LIB) -lft -L $(MLIB) $(MFLAGS)  > /dev/null 
clean:
				rm -f $(OBJECTS) > /dev/null
				make -C $(LIB) clean > /dev/null
fclean: clean
				rm -f $(NAME) > /dev/null
				make -C $(LIB) fclean > /dev/null
re: fclean all
