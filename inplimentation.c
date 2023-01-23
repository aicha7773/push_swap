/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inplimentation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:29:29 by aatki             #+#    #+#             */
/*   Updated: 2023/01/23 17:02:15 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_pile *l, int j)
{
	if (!l)
		return (0);
	while (l)
	{
		if (l->data >= j - 20 && l->data <= j)
		{
			printf("here j=%d data=%d\n", j, l->data);
			return (1);
		}
		l = l->next;
	}
	return (0);
}

void	just(t_pile **l, int j)
{
	int		top;
	t_pile	*b;

	b = NULL;
	while (check(*l, j))
	{
		top = scan_top(*l, j);
		ft_top(l, &b, top, 'a');
	}
	affiche(b);
	printf("after\n");
}

void	main_function(t_pile **l)
{
	just(l, 20);
	just(l, 40);
	just(l, 80);
	just(l, 100);
}

int	scan_top(t_pile *l, int j)
{
	int	i;

	i = 0;
	if (!l)
		return (0);
	while (l)
	{
		if (l->data >= j - 19 && l->data <= j)
			return (i);
		l = l->next;
		i++;
	}
	return (i);
}

int	scan_buttom(t_pile *l, int j)
{
	int	i;
	int	ret;

	i = 0;
	if (!l)
		return (0);
	while (l)
	{
		if (l->data >= j && l->data <= j + 20)
		{
			ret = i;
		}
		l = l->next;
		i++;
	}
	return (ret);
}
