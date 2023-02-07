/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:31 by aatki             #+#    #+#             */
/*   Updated: 2023/02/06 23:03:23 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_three(t_pile *l)
{
	int	a;
	int	b;
	int	c;

	a = l->data;
	b = l->next->data;
	c = l->next->next->data;
	if (a < c && c < b)
	{
		putstr("sa\n");
		putstr("ra\n");
	}
	else if (c < b && b < a)
	{
		putstr("sa\n");
		putstr("rra\n");
	}
	else if (b < c && c < a)
		putstr("ra\n");
	else if (b < a && a < c)
		putstr("sa\n");
	else if (c < a && a < b)
		putstr("rra\n");
}
