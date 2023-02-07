/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   an_other_other_try.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:25:06 by aatki             #+#    #+#             */
/*   Updated: 2023/02/07 02:19:06 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct t_hankss
{
	int	size;
	int	offset;
	int	start;
	int	end;
	int	middle;
	int	i;
}		t_hanks;

void	for_norm(t_pile **l, t_pile **b, int *tab, t_hanks *t)
{
	t->i = 0;
	while (*l && t->i < 2 * t->offset)
	{
		if ((*l)->data >= tab[t->start] && (*l)->data <= tab[t->end])
		{
			which_way(l, b, 0, 'a');
			if ((*b)->data <= tab[t->middle])
			{
				rot(b);
				putstr("rb\n");
			}
			t->i++;
		}
		else
		{
			rot(l);
			putstr("ra\n");
		}
	}
}

void	main_function(t_pile **l)
{
	t_hanks	t;
	int		*tab;
	t_pile	*b;

	b = NULL;
	t.size = ft_lstsize(*l);
	tab = struct_to_tab(*l);
	t.middle = t.size / 2;
	t.offset = t.size / 6;
	if (t.size > 150)
		t.offset = t.size / 15;
	t.start = t.middle - t.offset;
	t.end = t.middle + t.offset - 1;
	while (*l)
	{
		for_norm(l, &b, tab, &t);
		t.start -= t.offset;
		t.end += t.offset;
		if (t.end >= t.size)
			t.end = t.size - 1;
		if (t.start < 0)
			t.start = 0;
	}
	please(l, &b);
	free(tab);
}

int	exitt(t_pile *p, int val)
{
	t_pile	*b;

	b = p;
	while (b)
	{
		if (b->data == val)
			return (1);
		b = b->next;
	}
	return (0);
}

void	for_norm2(t_pile **b, t_pile **a, int *tab, t_hanks t)
{
	t.end = 0;
	while (t.i > -1)
	{
		if (t.end-- > 0 && !exitt(*b, tab[t.i]))
		{
			rev_rot(a);
			putstr("rra\n");
			t.i--;
			continue ;
		}
		if ((*b)->data == tab[t.i])
		{
			push(b, a);
			putstr("pa\n");
			t.i--;
		}
		else if (t.end++ == 0 || (t.end > 0 && (*b)->data > ft_lstlastint(*a)))
		{
			push(b, a);
			rot(a);
			putstr("pa\nra\n");
		}
		else
			which_way2(b, pos(*b, tab[t.i]));
	}
}

void	please(t_pile **a, t_pile **b)
{
	int		size;
	int		*tab;
	t_hanks	t;

	size = ft_lstsize(*b);
	tab = struct_to_tab(*b);
	trier_tab(tab, size);
	t.i = size - 1;
	while (*b)
	{
		for_norm2(b, a, tab, t);
	}
	free(tab);
}
