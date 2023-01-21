/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:49:39 by aatki             #+#    #+#             */
/*   Updated: 2023/01/21 21:22:37 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trier2(int *T)
{
	int i, j, k, c;
	for (i = 1; i < 12; i++)
	{
		if (T[i] < T[i - 1])
		{
			j = 0;
			while (T[j] < T[i])
				j++;
			c = T[i];
			k = i - 1;
			while (k >= j)
			{
				T[k + 1] = T[k];
				k--;
			}
			T[j] = c;
		}
	}
}

void	ten_to_ten(t_pile **l)
{
	int		i;
	t_pile	*tmp;
	t_pile	*b;
	int		*tab;
	int		d;

	d = 0;
	i = 10;
	tmp = *l;
	b = NULL;
	tab = struct_to_tab(*l);
	trier2(tab);
	// while (*l)
	// {
	//tmp = *l;
	printf("%d", (*l)->data);
	while (d <= 12)
	{
		if ((*l)->data < tab[i])
			push(l, &b);
		else
			rev_rot(l);
		i += 10;
		if (i > 12)
			i = 12;
		d++;
	}
	// }
	dix(&b);
	*l = b;
	affiche(*l);
}
