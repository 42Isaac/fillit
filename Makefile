# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iperez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 05:28:22 by iperez            #+#    #+#              #
#    Updated: 2019/06/17 05:28:25 by iperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit
CFLAGS		= -Wall -Werror -Wextra

INCLUDES	= $(wildcard *.c)

.PHONY: silent show all clean fclean re

silent:
	@make all -s

debug:
	make all CFLAGS='$(CFLAGS) -g'

all:
	gcc $(CFLAGS) $(INCLUDES) libft_1/libft.a -o $(NAME)

clean:
	-@rm -f $(NAME)
	-@rm -r $(NAME).dSYM

re: fclean all
