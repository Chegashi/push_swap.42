# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 16:23:40 by mochegri          #+#    #+#              #
#    Updated: 2021/03/27 18:13:12 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

flags = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = ft_checker.c 

MAND = $(SRCS)

$(NAME): $(SRCS)
	@gcc $(flags) -c $(SRCS) -o checker

all : $(NAME)

clean:
	@rm -f $(SRC:.c=.o) $(MAND:.c=.o) checker

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

checker: re
	./checker

# push_swap : re
# 	./push_swap
