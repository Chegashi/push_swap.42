# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abort <abort@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 16:23:40 by mochegri          #+#    #+#              #
#    Updated: 2021/04/21 05:37:52 by abort            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

flags = -Wall -Wextra -Werror

SRCS =	libft/libft.c \
		libft/ft_split.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		ft_operation_1.c \
		ft_operation_2.c 

MAND = $(SRCS)

$(NAME): $(SRCS)
	@gcc $(flags) -c $(SRCS)
	@ar -rc push_swap.a *.o
	@ranlib push_swap.a
	@gcc $(flags) ft_checker.c push_swap.a -o checker
	@gcc $(flags) ft_push_swap.c push_swap.a -o push_swap
	@rm *.o

all : $(NAME)

clean:
	@rm -f $(SRC:.c=.o) $(MAND:.c=.o) checker

fclean:	clean
	@rm -rf checker
	@rm -rf push_swap
	@rm -rf push_swap.a

re:		fclean all

checker: re
	

# push_swap : re
# 	./push_swap
