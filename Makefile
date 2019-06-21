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

INCLUDES	= $(wildcard *.c) libft_1/libft.a

.PHONY: silent show all clean fclean re

silent:
	@make all -s

debug:
	make all CFLAGS='$(CFLAGS) -g'

all:
	$(MAKE) all -C libft_1
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME)

clean:
	-@$(MAKE) clean -C libft_1 -s
	-@rm -f $(NAME)
	-@rm -f -r $(NAME).dSYM

re: clean all
