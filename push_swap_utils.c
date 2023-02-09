/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:05:26 by aatki             #+#    #+#             */
/*   Updated: 2023/02/09 18:16:59 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

t_pile	*in_pile(char **v)
{
	int		i;
	t_pile	*l;
	char	**spl;
	int		j;

	l = NULL;
	i = 1;
	while (v[i])
	{
		j = 0;
		spl = ft_split(v[i], ' ');
		while (spl[j])
		{
			ft_lstadd_back(&l, ft_lstnew(ft_atoi(spl[j])));
			j++;
		}
		ft_freee(spl, j);
		i++;
	}
	return (l);
}

// t_pile	*in_pile(char **v)
// {
// 	int		i;
// 	t_pile	*l;

// 	l = NULL;
// 	i = 1;
// 	while (v[i])
// 	{
// 		ft_lstadd_back(&l, ft_lstnew(ft_atoi(v[i])));
// 		i++;
// 	}
// 	return (l);
// }

void	ft_free(t_pile *t)
{
	t_pile	*tmp;

	if (!t)
		return ;
	while (t)
	{
		tmp = t;
		t = t->next;
		free(tmp);
	}
}

void	for_norm(t_pile **l, t_pile **b, int *tab, t_hanks *t)
{
	t->i = 0;
	while (*l && t->i < 2 * t->offset)
	{
		if ((*l)->data >= tab[t->start] && (*l)->data <= tab[t->end])
		{
			which_way(l, b, 0, 'a');
			if ((*b)->data <= tab[t->middle])
			{
				rot(b);
				putstr("rb\n");
			}
			t->i++;
		}
		else
		{
			rot(l);
			putstr("ra\n");
		}
	}
}
