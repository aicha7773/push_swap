/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   an_other_other_try.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:25:06 by aatki             #+#    #+#             */
/*   Updated: 2023/02/07 01:41:04 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_norm(t_pile **l, t_pile **b, int offset, int start, int end,
		int middle, int *tab)
{
	int	i;

	i = 0;
	while (*l && i < 2 * offset)
	{
		if ((*l)->data >= tab[start] && (*l)->data <= tab[end])
		{
			which_way(l, b, 0, 'a');
			if (!*l)
				break ;
			if ((*b)->data <= tab[middle])
			{
				rot(b);
				putstr("rb\n");
			}
			i++;
		}
		else
		{
			rot(l);
			putstr("ra\n");
		}
		indicer(*l);
		if (no_need(*l))
			break ;
	}
}

void	main_function(t_pile **l)
{
	int		size;
	int		middle;
	int		offset;
	int		start;
	int		end;
	int		*tab;
	t_pile	*b;

	b = NULL;
	size = ft_lstsize(*l);
	tab = struct_to_tab(*l);
	trier_tab(tab, size);
	middle = size / 2;
	offset = 0;
	if (size <= 10)
		offset = size / 5;
	else if (size <= 150)
		offset = size / 6;
	else if (size > 150)
		offset = size / 15;
	start = middle - offset;
	end = middle + offset - 1;
	while (*l)
	{
		for_norm(l, &b, offset, start, end, middle, tab);
		start -= offset;
		end += offset;
		if (end >= size)
			end = size - 1;
		if (start < 0)
			start = 0;
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

void	for_norm2(t_pile **b, t_pile **a, int *tab, int i)
{
	int	count;

	count = 0;
	while (i > -1)
	{
		if (count-- > 0 && !exitt(*b, tab[i]))
		{
			rev_rot(a);
			putstr("rra\n");
			i--;
			continue ;
		}
		if ((*b)->data == tab[i])
		{
			push(b, a);
			putstr("pa\n");
			i--;
		}
		else if (count++ == 0 || (count > 0 && (*b)->data > ft_lstlastint(*a)))
		{
			push(b, a);
			rot(a);
			putstr("pa\nra\n");
		}
		else
			which_way2(b, pos(*b, tab[i]));
	}
}

void	please(t_pile **a, t_pile **b)
{
	int size;
	int *tab;
	int i;

	size = ft_lstsize(*b);
	tab = struct_to_tab(*b);
	trier_tab(tab, size);
	i = size - 1;
	while (*b)
	{
		for_norm2(b, a, tab, i);
	}
	free(tab);
}