/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:26 by aatki             #+#    #+#             */
/*   Updated: 2023/02/08 21:45:55 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
		i++;
	sub = (char *)malloc(sizeof(char) * (i + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
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
