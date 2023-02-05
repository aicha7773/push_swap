/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   an_other_other_try.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:25:06 by aatki             #+#    #+#             */
/*   Updated: 2023/02/05 23:14:15 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_one(t_pile **l)
{
	
	int		size;
	int		middle;
	int		offset;
	int		start;
	int		end;
	int		*tab;
	t_pile	*b;
	int		i;

	b = NULL;
	size = ft_lstsize(*l);
	tab = struct_to_tab(*l);
	trier_tab(tab, size);
	middle = size / 2;
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
		i = 0;
		while (*l && i < 2 * offset)
		{
			if((*l)->data >= tab[start] && (*l)->data <= tab[end])
			{
				which_way(l, &b, 0, 'a');
					if(!*l)
						break;
				if(b->data <= tab[middle])
				{
					rot(&b);
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
			if(no_need(*l))
				break;
		}
		start -= offset;
		end +=  offset;
		if(end >= size)
			end = size - 1;	
		if(start < 0)
			start = 0;
	}
	please(l,&b);
}

int exitt(t_pile *p,int val)
{
	t_pile *b; 
	b = p;
	while(b)
	{
		if(b->data == val)
		return 1;
		b=b->next;
	}
	return 0;
}

void please(t_pile **a,t_pile **b)
{
	int size;
	int *tab;
	size = ft_lstsize(*b);
	tab = struct_to_tab(*b);
	trier_tab(tab, size);
	int i=size - 1;
	int count = 0;

	while(*b)
	{
		while(i > -1)
		{
			if(count > 0 && !exitt(*b,tab[i]))
			{
				rev_rot(a);
				putstr("rra\n");
				i--;
				count--;
				continue;
			}
			if((*b)->data==tab[i])
			{
				push(b,a);
				putstr("pa\n");
				i--;
			}
			else if(count == 0 || (count > 0 && (*b)->data > ft_lstlastint(*a)))
			{
				push(b,a);
				putstr("pa\n");
				rot(a);
				putstr("ra\n");
				count++;
			}
			else
				which_way2(b,pos(*b,tab[i]));
		}
	}
}
