/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:54:56 by aatki             #+#    #+#             */
/*   Updated: 2023/02/05 21:34:39 by aatki            ###   ########.fr       */
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
	if(!*a)
		return;
		t_pile	*tmp;
	// (void)b;
	tmp = ft_lstnew((*a)->data);
	ft_lstadd_front(b, tmp);
	*a=(*a)->next;
	//ft_lstdelfront(a);
	// t_pile	*tmp;
	// if(!*b)
	// {
	// 	 tmp = (*a)->next;
	// 	(*a)->next = NULL;
	// 	*b =*a;
	// 	*a = tmp;
	// 	return ;
	// }
    // tmp = (*a)->next;
    // (*a)->next = *b;
    // *b =*a;
    // *a = tmp;
}

void	push_a_b(t_pile **aa, t_pile **bb)
{
	push(aa, bb);
	push(bb, aa);
}

void	imagination(t_pile **aa, t_pile **bb)
{
	t_pile	*tmp;

	(void)bb;
	tmp = ft_lstnew((*aa)->data);
	ft_lstadd_back(bb, tmp);
	ft_lstdelfront(aa);
}

// void	rot(t_pile **a)
// {
// 	t_pile	*tmp = *a;
// 	t_pile	*tmp2 = *a;
// 	*a = (*a)->next;
	
// 	while(tmp2->next)
// 		tmp2=tmp2->next;
// 	tmp2->next=tmp;
// 	tmp->next = NULL;
// }

void	rot(t_pile **a)
{
	t_pile	*tmp ;
	tmp = NULL;
	imagination(a, &tmp);
	imagination(&tmp, a);

	// t_pile	*tmp = *a;
	// t_pile	*tmp2 = *a;
	// *a = (*a)->next;
	
	// while(tmp2->next)
	// 	tmp2=tmp2->next;
	// tmp2->next=tmp;
	// tmp->next = NULL;
}

void	rot_a_b(t_pile **a, t_pile **b)
{
	rot(a);
	rot(b);
}

void	rev_rot(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*g;

	g = ft_lstlast(*a);
	if (!g)
		return ;
	tmp = ft_lstnew(g->data);
	if (!tmp)
		return ;
	ft_lstadd_front(a, tmp);
	ft_lstdelback(a);
}

void	rrev_rot(t_pile **a, t_pile **b)
{
	rev_rot(a);
	rev_rot(b);
}
