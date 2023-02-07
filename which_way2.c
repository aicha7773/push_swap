/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_way2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:19:04 by aatki             #+#    #+#             */
/*   Updated: 2023/02/06 23:49:20 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	which_way2(t_pile **l, int pos)
{
	int	size;

	if (!*l || pos == -1)
		return ;
	size = ft_lstsize(*l);
	if (pos > size / 2)
	{
		rev_rot(l);
		putstr("rrb\n");
	}
	else if (pos <= size / 2)
	{
		rot(l);
		putstr("rb\n");
	}
}

int	dupp(t_pile *o, int d)
{
	t_pile	*l;

	l = o;
	if (!l)
		return (1);
	while (l)
	{
		if (l->data == d)
			return (0);
		l = l->next;
	}
	return (1);
}

void	duplicated(t_pile *o)
{
	t_pile	*c;
	t_pile	*l;
	t_pile	*tmp;

	c = NULL;
	l = o;
	while (l)
	{
		if (!dupp(c, l->data))
			ft_error();
		tmp = ft_lstnew(l->data);
		ft_lstadd_back(&c, tmp);
		l = l->next;
	}
	ft_free(c);
}

int	pos(t_pile *p, int d)
{
	int		i;
	t_pile	*l;

	i = 0;
	l = p;
	while (l)
	{
		if (l->data == d)
			return (i);
		l = l->next;
		i++;
	}
	return (-1);
}
