/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:25:59 by aatki             #+#    #+#             */
/*   Updated: 2023/02/06 22:57:19 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker(t_pile **a)
{
	t_pile	*b;
	char	*v;

	b = NULL;
	while (1)
	{
		v = get_next_line(0);
		if (v == NULL)
			break ;
		if (!ft_strcmp(v, "sa\n"))
			swap(*a);
		else if (!ft_strcmp(v, "sb\n"))
			swap(b);
		else if (!ft_strcmp(v, "pa\n"))
			push(&b, a);
		else if (!ft_strcmp(v, "pb\n"))
			push(a, &b);
		else if (!ft_strcmp(v, "ra\n"))
			rot(a);
		else if (!ft_strcmp(v, "rb\n"))
			rot(&b);
		else if (!ft_strcmp(v, "rra\n"))
			rev_rot(a);
		else if (!ft_strcmp(v, "rrb\n"))
			rev_rot(&b);
		else if (!ft_strcmp(v, "ss\n"))
			swap_a_b(*a, b);
		else if (!ft_strcmp(v, "rr\n"))
			rot_a_b(a, &b);
		else if (!ft_strcmp(v, "rrr\n"))
			rrev_rot(a, &b);
		else
			ft_error();
		free(v);
	}
	ft_free(b);
	if (no_need(*a))
		putstr("OK\n");
	else
		putstr("KO\n");
}
