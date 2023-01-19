# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:33:49 by aatki             #+#    #+#              #
#    Updated: 2023/01/19 16:44:06 by aatki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

CC = cc

SRC = check_input.c push_swap.c push_swap_utils.c swap_functions.c libft.c trier.c swap3.c inplimentation.c dix.c

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBS)

fclean: clean
	rm -rf $(NAME)

re : fclean all