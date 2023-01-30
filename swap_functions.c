/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:54:56 by aatki             #+#    #+#             */
/*   Updated: 2023/01/30 19:45:44 by aatki            ###   ########.fr       */
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

t_pile    *ft_pop(t_pile **stack)
{
    t_pile    *node;

    node= NULL;
    if (!stack || !*stack)
        return (0);
    node = *stack;
    *stack = (*stack)->next;
    node->next = NULL;
    free(node);
    return (*stack);
}

int    push_test(t_pile **stack, int elem)
{
    t_pile    *new;

    if (!stack)
        return (0);
    new = ft_lstnew(elem);
    if (!new)
        return (0);
    new->next = *stack;
    *stack = new;
    return (1);
}

void	push(t_pile **a, t_pile **b)
{
	// t_pile	*tmp;
	// (void)bb;
	// tmp = ft_lstnew((*aa)->data);
	// ft_lstadd_front(bb, tmp);
	// ft_lstdelfront(aa);
	
	// t_pile *tmp;
	// tmp =(*aa)->next;
	// //(tmp)->next=*bb;

	// push_test(b, (*a)->data);
	// ft_pop(a);

	if(!*a)
		return;
	t_pile	*tmp;
	if(!*b)
	{
		 tmp = (*a)->next;
		(*a)->next = NULL;
		*b =*a;
		*a = tmp;
		return ;
	}
    tmp = (*a)->next;
    (*a)->next = *b;
    *b =*a;
    *a = tmp;


	// t_pile *b_head = *b;
	// t_pile *tmp = (*b)->next;
	// (*b)->next = *a;
	// *b = tmp;
	// *a = b_head;
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

void	rot(t_pile **a)
{
	// t_pile	*tmp ;
	// tmp = NULL;
	// imagination(a, &tmp);
	// imagination(&tmp, a);

	t_pile	*tmp = *a;
	t_pile	*tmp2 = *a;
	*a = (*a)->next;
	
	while(tmp2->next)
		tmp2=tmp2->next;
	tmp2->next=tmp;
	tmp->next = NULL;
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
