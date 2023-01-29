# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatki <aatki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:33:49 by aatki             #+#    #+#              #
#    Updated: 2023/01/29 04:15:49 by aatki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

CC = cc

SRC = check_input.c\
	push_swap.c\
	push_swap_utils.c\
	swap_functions.c\
	libft.c\
	tools.c\
	swap3.c\
	if_five.c\
	which_way.c\
	the_last.c\
	not_the_last.c\
	

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBS)

fclean: clean
	rm -rf $(NAME)

re : fclean all
