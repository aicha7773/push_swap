/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:54:56 by aatki             #+#    #+#             */
/*   Updated: 2023/02/06 23:12:58 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *l)
{
	int	swap;

	if (l && l->next)
	{
		swap = l->data;
		l->data = l->next->data;
		l->next->data = swap;
	}
}

void	swap_a_b(t_pile *a, t_pile *b)
{
	swap(a);
	swap(b);
}

void	push(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (!*a || !a)
		return ;
	tmp = ft_lstnew((*a)->data);
	ft_lstadd_front(b, tmp);
	ft_lstdelfront(a);
}

void	push_a_b(t_pile **aa, t_pile **bb)
{
	push(aa, bb);
	push(bb, aa);
}
