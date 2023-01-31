# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatki <aatki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:33:49 by aatki             #+#    #+#              #
#    Updated: 2023/01/31 17:53:29 by aatki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

CC = cc

SRC = check_input.c\
	push_swap_utils.c\
	swap_functions.c\
	libft.c\
	tools.c\
	swap3.c\
	if_five.c\
	which_way.c\
	the_last.c\
	not_the_last.c\

SRCB= ./bonus/main.c\
		./bonus/checker_bonus.c\
		./bonus/get_next_line.c\
		./bonus/get_next_line_utils.c

OBJS = ${SRC:.c=.o}

OBJSB = ${SRCB:.c=.o}

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) push_swap.c $(SRC) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) :
	$(CC) $(CFLAGS) $(SRCB) $(SRC) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all bonus
