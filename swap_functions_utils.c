/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:12:00 by aatki             #+#    #+#             */
/*   Updated: 2023/02/06 23:17:04 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_list(t_pile *l)
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

void	rot(t_pile **a)
{
	t_pile	*tmp;

	if (!*a || !a)
		return ;
	tmp = ft_lstnew((*a)->data);
	ft_lstadd_back(a, tmp);
	ft_lstdelfront(a);
}

void	rot_a_b(t_pile **a, t_pile **b)
{
	rot(a);
	rot(b);
}

void	rev_rot(t_pile **a)
{
	t_pile	*tmp;

	if (!*a || !a)
		return ;
	tmp = ft_lstnew(ft_lstlastint(*a));
	if (!tmp)
		return ;
	ft_lstadd_front(a, tmp);
	ft_lstdelback(a);
}

void	rrev_rot(t_pile **a, t_pile **b)
{
	rev_rot(a);
	rev_rot(b);
}
