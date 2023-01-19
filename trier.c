/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trier.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:26 by aatki             #+#    #+#             */
/*   Updated: 2023/01/18 18:30:29 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	yes(t_pile *l)
{
	if (!l)
		return (1);
	while (l->next)
	{
		if (l->data > l->next->data)
			return (0);
		l = l->next;
		if (l == NULL)
			break ;
	}
	return (1);
}

int	*struct_to_tab(t_pile *l)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * ft_lstsize(l));
	if (!l)
		return (NULL);
	i = 0;
	while (l->next)
	{
		tab[i] = l->data;
		i++;
		l = l->next;
		if (l == NULL)
			break ;
	}
	return (tab);
}

void	indicer(t_pile *l)
{
	int	*tab;
	int	i;

	tab = struct_to_tab(l);
	trier_tab(tab);
	i = 0;
	while (l)
	{
		while (tab[i])
		{
			if (l->data == tab[i])
				l->index = i;
			i++;
		}
		printf("test\n");
		i = 0;
		l = l->next;
	}
}

void	trier_tab(int *tab)
{
	int	i;
	int	swap;

	i = 0;
	while (i < 2)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
		}
		i++;
	}
}

void	trier(t_pile *l)
{
	t_pile	*save;

	save = l;
	while (l)
	{
		if (!l->next)
			l = save;
		if (yes(save))
			break ;
		if (l->data > l->next->data)
		{
			swap(l);
			write(1, "swap a\n", 7);
			l = save;
		}
		l = l->next;
	}
}
