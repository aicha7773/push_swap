/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:00:01 by aatki             #+#    #+#             */
/*   Updated: 2023/01/20 16:27:50 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int c, char **v)
{
	t_pile	*t;

	check_input(v);
	t = in_pile(v);
	if (yes(t))
		return ;
	if (c == 3 && t->data < t->next->data)
		putstr("sa");
	if (c == 4)
		if_trois(t);
	else if (c > 4 && c <= 10)
		dix(&t);
	else if (c > 10)
		hundred(&t);
}

int	main(int c, char **v)
{
	if (c > 2)
	{
		push_swap(c, v);
	}
}
