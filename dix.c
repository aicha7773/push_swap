/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:29:54 by aatki             #+#    #+#             */
/*   Updated: 2023/01/19 16:17:34 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dix(t_pile **l)
{
	int		size;
	t_pile	*b;
	int		i;
	int		min;

	b = NULL;
	i = 0;
	size = ft_lstsize(*l);
	while (*l)
	{
		min = ft_min(*l);
		if (min < (size - i) / 2)
			ft_top(l, &b, min);
		else
			ft_buttom(l, &b, min);
		i++;
	}
	affiche(b);
	while (b)
		push(&b, l);
	printf("apres\n");
	affiche(*l);
}

int	ft_min(t_pile *lst)
{
	int	i;
	int	indice;
	int	min;

	i = 0;
	min = lst->data;
	while (lst)
	{
		if (lst->data < min)
		{
			min = lst->data;
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
	putstr("pa");
}
