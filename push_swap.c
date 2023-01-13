/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:00:01 by aatki             #+#    #+#             */
/*   Updated: 2023/01/13 15:22:49 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **v)
{
	int		num;
	t_pile	*t;
	t_pile	*g;
	int		*tab;

	g = NULL;
	num = check_input(v);
	t = in_pile(v, num);
	main_function(&t);
	tab = struct_to_tab(t);
	//if_trois(t);
}

int	main(int c, char **v)
{
	if (c > 1)
	{
		push_swap(v);
	}
}
