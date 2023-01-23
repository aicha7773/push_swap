/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:14:38 by aatki             #+#    #+#             */
/*   Updated: 2023/01/22 21:19:41 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hundred(t_pile **l)
{
	int		i;
	int		*tab;
	t_pile	*b;
	t_pile	*tmp;
	int		d;

	i = 0;
	b = NULL;
	tmp = *l;
	tab = struct_to_tab(*l);
	trier_tab(tab);
	affichetab(tab, 8);
	while (tmp)
	{
		d = tmp->data;
		push(&tmp, &b);
		putstr("pa\n");
		if (tab[i] != d)
		{
			rev_rot(&b);
			putstr("rb\n");
		}
		//printf("i = %d\n", i);
		i++;
	}
	// affiche(b);
	// printf("apres\n");
	// affiche(tmp);
}

void	affichetab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
