/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:29:54 by aatki             #+#    #+#             */
/*   Updated: 2023/01/21 12:13:50 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dix(t_pile **l)
{
	int		size;
	t_pile	*b;
	int		i;
	int		max;

	b = NULL;
	i = 0;
	size = ft_lstsize(*l);
	while (*l)
	{
		max = ft_max(*l);
		if (max < (size - i) / 2)
			ft_top(l, &b, max);
		else
			ft_buttom(l, &b, max);
		i++;
	}
	while (b)
		push(&b, l);
	//affiche(*l);
}

int	ft_max(t_pile *lst)
{
	int	i;
	int	indice;
	int	max;

	indice = 0;
	i = 0;
	max = lst->data;
	while (lst)
	{
		if (lst->data > max)
		{
			max = lst->data;
			indice = i;
		}
		i++;
		lst = lst->next;
	}
	return (indice);
}

void	ft_top(t_pile **l, t_pile **chank, int i)
{
	int	j;

	if (!*l)
		return ;
	if (!chank)
		return ;
	j = 0;
	while (j < i)
	{
		rot(l);
		putstr("ra\n");
		j++;
	}
	push(l, chank);
	putstr("pa\n");
}

void	ft_buttom(t_pile **l, t_pile **chank, int i)
{
	int	j;

	if (!*l)
		return ;
	if (!chank)
		return ;
	j = 0;
	while (j < i)
	{
		rot(l);
		putstr("rra\n");
		j++;
	}
	push(l, chank);
	putstr("pa\n");
}
