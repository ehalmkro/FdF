# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:34:36 by ehalmkro          #+#    #+#              #
#    Updated: 2020/02/08 14:53:16 by ehalmkro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
SRC_DIR = src/
SRC_FILES = main.c color.c events.c extras.c line_draw.c matrix.c mouse_events.c \
	pointlist.c read_write.c tools.c window.c wu.c wu_utils.c
SOURCES = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIB = Libft/
MLIB = /usr/local/lib
MFLAGS = -lmlx -I /usr/local/include -L/usr/local/lib -framework OpenGL -framework Appkit
FLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRC_FILES:.c=.o)

all: $(NAME)
$(NAME):
				@make -C $(LIB)
				@gcc $(FLAGS) -c $(SOURCES)
				@gcc -o $(NAME) $(OBJECTS) -L $(LIB) -lft -L $(MLIB) $(MFLAGS)
clean:
				@rm -f $(OBJECTS)
				@make -C $(LIB) clean
fclean: clean
				@rm -f $(NAME)
				@make -C $(LIB) fclean
re: fclean all
