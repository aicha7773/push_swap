/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_way2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:19:04 by aatki             #+#    #+#             */
/*   Updated: 2023/02/05 23:07:39 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	which_way2(t_pile **l,int pos)
{
	int	size;

	if (!*l || pos == -1)
		return ;
	size = ft_lstsize(*l);
	if (pos > size / 2)	
	{
		rev_rot(l);
		putstr("rrb\n");
	}
	else if (pos <= size / 2)
	{
		rot(l);
		putstr("rb\n");
	}
}
