# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 16:11:19 by ehalmkro          #+#    #+#              #
#    Updated: 2020/01/31 15:05:27 by ehalmkro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_bzero.c ft_memset.c\
ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_memchr.c\
ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_toupper.c\
ft_tolower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
ft_isprint.c ft_atoi.c ft_strlen.c ft_strcmp.c ft_strncmp.c\
ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strstr.c ft_strnstr.c\
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strequ.c\
ft_strnequ.c ft_strjoin.c ft_strsub.c ft_strtrim.c ft_itoa.c\
ft_strmapi.c ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c\
ft_lstdel.c ft_lstmap.c ft_swap.c ft_wordcount.c ft_wordlength.c\
ft_count_if.c ft_strsplit.c ft_lstaddback.c get_next_line.c ft_fswap.c
OBJECTS = $(subst .c,.o, $(SRC))
FLAGS = -Wall -Werror -Wextra

all: $(NAME)
$(NAME):
		gcc -c $(FLAGS) $(SRC)
		ar rc $(NAME) $(OBJECTS)
		ranlib $(NAME)
clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all
