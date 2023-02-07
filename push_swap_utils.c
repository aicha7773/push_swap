/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:05:26 by aatki             #+#    #+#             */
/*   Updated: 2023/02/06 23:23:49 by aatki            ###   ########.fr       */
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

	l = NULL;
	i = 1;
	while (v[i])
	{
		ft_lstadd_back(&l, ft_lstnew(ft_atoi(v[i])));
		i++;
	}
	return (l);
}

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
