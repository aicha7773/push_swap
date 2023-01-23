/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:00:01 by aatki             #+#    #+#             */
/*   Updated: 2023/01/23 20:35:57 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int c, char **v)
{
	t_pile	*t;

	check_input(v);
	t = in_pile(v);
	if (!duplicated(t))
		return ;
	if (yes(t))
		return ;
	if (c == 3 && t->data < t->next->data)
		putstr("sa");
	if (c == 4)
	{
		if_trois(t);
		return ;
	}
	simple(&t);
	//autre(&t);
	// else if (c > 4 && c <= 10)
	// 	dix(&t);
	// else if (c > 10)
	//ten_to_ten(&t);
	//hundred(&t);
}

int	main(int c, char **v)
{
	if (c > 2)
	{
		push_swap(c, v);
	}
}
