/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:26 by aatki             #+#    #+#             */
/*   Updated: 2023/02/07 02:07:10 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*struct_to_tab(t_pile *p)
{
	int		*tab;
	int		i;
	int		s;
	t_pile	*l;

	l = p;
	i = 0;
	s = ft_lstsize(l);
	tab = malloc(sizeof(int) * (s));
	if (!l)
		return (NULL);
	while (i < s)
	{
		tab[i] = l->data;
		i++;
		l = l->next;
	}
	trier_tab(tab, s);
	return (tab);
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

void	indicer(t_pile *l)
{
	int	*tab;
	int	i;
	int	size;

	if (!l)
		return ;
	size = ft_lstsize(l);
	tab = struct_to_tab(l);
	trier_tab(tab, size);
	i = 0;
	while (l)
	{
		while (i < size)
		{
			if (l->data == tab[i])
			{
				l->index = i;
				i = 0;
				break ;
			}
			i++;
		}
		l = l->next;
	}
	free(tab);
}

void	trier_tab(int *T, int size)
{
	int	i;
	int	j;
	int	k;
	int	c;

	i = 1;
	while (i < size)
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
		i++;
	}
}

void	trier_tabbb(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		i++;
	}
}
