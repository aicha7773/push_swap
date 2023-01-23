/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_way2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:06:19 by aatki             #+#    #+#             */
/*   Updated: 2023/01/23 22:30:11 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	which_way(t_pile **l, t_pile **b, int pos, char c)
{
	int	size;
	int	i;

	//int	pos;
	if (!*l)
		return ;
	i = 0;
	size = ft_lstsize(*l);
	//pos = ft_pos(*l, val);
	if (pos < (size - i) / 2)
		ft_top(l, b, pos, c);
	else
		ft_buttom(l, b, pos, c);
	i++;
}

int	ft_pos(t_pile *lst, int val)
{
	int	i;
	int	indice;

	indice = 0;
	i = 0;
	while (lst)
	{
		if (lst->data == val)
		{
			indice = i;
		}
		i++;
		lst = lst->next;
	}
	return (indice);
}

void	ft_top(t_pile **l, t_pile **chank, int i, char c)
{
	c = 1;
	if (!*l)
		return ;
	if (!chank)
		return ;
	while (i)
	{
		rot(l);
		putstr("rb\n");
		i--;
	}
	push(l, chank);
	putstr("pa\n");
}

void	ft_buttom(t_pile **l, t_pile **chank, int i, char c)
{
	c = 1;
	if (!*l)
		return ;
	if (!chank)
		return ;
	i = ft_lstsize(*l) - i;
	while (i)
	{
		rev_rot(l);
		putstr("rrb\n");
		i--;
	}
	push(l, chank);
	putstr("pa\n");
}

// while (i < size)
// {
// 	which_way(&b, l, i, 'a');
// 	if (i == R)
// 		R += 15;
// 	i++;
// }