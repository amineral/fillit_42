# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srupp <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 22:23:08 by srupp             #+#    #+#              #
#    Updated: 2020/01/21 22:23:13 by srupp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

NAME = fillit

SRCS =	fillit.c \
		lets_fill_it.c \
		field.c \
		other_func.c \
		other_other_func.c \
		validation.c \
		solve.c 

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
		gcc -Wall -Wextra -Werror -o $(NAME) $^

$(OBJS): %.o : %.c fillit.h
		gcc -Wall -Wextra -Werror -I . -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
