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

OBJ	= $(patsubst %.c,%.o,$(wildcard *.c))

.PHONY: silent show all clean fclean re

silent:
	@make all -s

debug:
	make all CFLAGS='$(CFLAGS) -g'

all: $(NAME)
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME)

$(NAME): $(OBJ)
	$(MAKE) all -C libft_1
	cp libft_1/libft.a ./$(NAME)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	-@$(MAKE) clean -C libft_1 -s

fclean: clean
	-@rm -f $(NAME)
	-@rm -f -r $(NAME).dSYM

re: fclean all
