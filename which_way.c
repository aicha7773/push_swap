/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:29:54 by aatki             #+#    #+#             */
/*   Updated: 2023/01/23 23:22:53 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	which_way(t_pile **l, t_pile **b, int pos, char c)
{
	int	size;
	int	i;

	if (!*l)
		return ;
	i = 0;
	size = ft_lstsize(*l);
	if (pos < size / 2)
		ft_top(l, b, pos, c);
	else
		ft_buttom(l, b, pos, c);
	i++;
}

void	ft_top(t_pile **l, t_pile **chank, int i, char c)
{
	if (!*l)
		return ;
	if (!chank)
		return ;
	while (i)
	{
		rot(l);
		putstr("r");
		write(1, &c, 1);
		write(1, "\n", 1);
		i--;
	}
	push(l, chank);
	putstr("p");
	if (c == 'b')
		write(1, "a\n", 2);
	else if (c == 'a')
		write(1, "b\n", 2);
}

void	ft_buttom(t_pile **l, t_pile **chank, int i, char c)
{
	if (!*l)
		return ;
	if (!chank)
		return ;
	i = ft_lstsize(*l) - i;
	while (i)
	{
		rev_rot(l);
		putstr("rr");
		write(1, &c, 1);
		write(1, "\n", 1);
		i--;
	}
	push(l, chank);
	putstr("p");
	if (c == 'b')
		write(1, "a\n", 2);
	else if (c == 'a')
		write(1, "b\n", 2);
}
