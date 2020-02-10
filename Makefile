# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:34:36 by ehalmkro          #+#    #+#              #
#    Updated: 2020/02/10 16:17:48 by ehalmkro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
SRC_DIR = src/
SRC_FILES = main.c color.c events.c extras.c line_draw.c matrix.c events_mouse.c \
	pointlist.c read_write.c tools.c window.c wu.c wu_utils.c
SOURCES = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIB = Libft/
MLIB = minilibx/
MFLAGS = -lmlx -I ./minilibx -L./minilibx -framework OpenGL -framework Appkit
FLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRC_FILES:.c=.o)

all: $(NAME)
$(NAME):
				@make -C $(LIB)
				@make -C $(MLIB)
				@gcc $(FLAGS) -c $(SOURCES)
				@gcc -o $(NAME) $(OBJECTS) -L $(LIB) -lft -L $(MLIB) $(MFLAGS)
clean:
				@rm -f $(OBJECTS)
				@make -C $(LIB) clean
				@make -C $(MLIB) clean
fclean: clean
				@rm -f $(NAME)
				@make -C $(LIB) fclean
				@make -C $(MLIB) fclean
re: fclean all
