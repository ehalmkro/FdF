# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 16:11:19 by ehalmkro          #+#    #+#              #
#    Updated: 2020/02/08 15:07:21 by ehalmkro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_bzero.c get_next_line.c ft_strsub.c ft_strnew.c ft_strjoin.c ft_strdup.c \
		ft_strdel.c ft_strchr.c ft_putendl.c ft_fswap.c ft_atoi.c \
		ft_memset.c ft_strlen.c ft_strcpy.c ft_strcat.c
OBJECTS = $(subst .c,.o, $(SRC))
FLAGS = -Wall -Werror -Wextra

all: $(NAME)
$(NAME):
		@gcc -c $(FLAGS) $(SRC)
		@ar rc $(NAME) $(OBJECTS)
		@ranlib $(NAME)
clean:
		@rm -f $(OBJECTS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
