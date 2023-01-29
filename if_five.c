/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:40:26 by aatki             #+#    #+#             */
/*   Updated: 2023/01/27 12:55:48 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_list(t_pile *l)
{
	int	i;
	int	ret;
	int	min;

	i = 0;
	min = l->data;
	ret = 0;
	while (l)
	{
		if (l->data > min)
		{
			min = l->data;
			ret = i;
		}
		i++;
		l = l->next;
	}
	return (ret);
}

void  if_five(t_pile *l)
{
	t_pile *b;

	b=NULL;
	which_way(&l,&b,min_list(l),'a');
	which_way(&l,&b,min_list(l),'a');
	if_three(l);
	push(&b,&l);
	push(&b,&l);
	putstr("pa\npa\n");
}
