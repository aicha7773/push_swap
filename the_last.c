/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:44:24 by aatki             #+#    #+#             */
/*   Updated: 2023/01/23 23:22:35 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maxx(t_pile *l)
{
	int	i;
	int	ret;
	int	max;

	i = 0;
	max = l->data;
	ret = 0;
	while (l)
	{
		if (l->data > max)
		{
			max = l->data;
			ret = i;
		}
		i++;
		l = l->next;
	}
	return (ret);
}

int	ft_pos(t_pile *lst, int val)
{
	int	i;
	int	indice;

	indice = 0;
	i = 0;
	while (lst)
	{
		if (lst->index == val)
		{
			indice = i;
		}
		i++;
		lst = lst->next;
	}
	return (indice);
}

void	simple(t_pile **l)
{
	int		i;
	t_pile	*b;
	int		R;
	int		size;

	i = 0;
	b = NULL;
	R = 15;
	indicer(*l);
	// while (i < R && *l)
	// {
	// 	if ((*l)->index < R)
	// 	{
	// 		push(l, &b);
	// 		putstr("pb\n");
	// 		i++;
	// 	}
	// 	else
	// 	{
	// 		rot(l);
	// 		putstr("ra\n");
	// 	}
	// 	if (i == R)
	// 		R += 15;
	// }
	size = ft_lstsize(*l);
	while (i < size)
	{
		which_way(l, &b, ft_pos(*l, i), 'a');
		// if (i == R)
		// 	R += 15;
		i++;
	}
	indicer(*l);
	// affiche(*l);
	while (b)
		which_way(&b, l, maxx(b), 'b');
	// if (yes(*l))
	// 	printf("\n\nfkvbkggtgbhrtbk\n\n");
}
