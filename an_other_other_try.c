/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   an_other_other_try.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:25:06 by aatki             #+#    #+#             */
/*   Updated: 2023/01/23 16:36:30 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	autre(t_pile **l)
{
	int		size;
	int		n;
	int		middle;
	int		offset;
	int		start;
	int		end;
	int		*tab;
	t_pile	*b;
	int		i;

	b = NULL;
	size = ft_lstsize(*l);
	tab = struct_to_tab(*l);
	trier2(tab, size);
	middle = size / 2;
	if (size <= 10)
		n = 5;
	else if (size <= 150)
		n = 8;
	if (size >= 150)
		n = 18;
	offset = size / n;
	start = middle - offset;
	end = middle + offset;
	i = middle;
	while (*l)
	{
		while (i < end)
		{
			which_way(l, &b, i, 'a');
			indicer(*l);
			end = middle + 1;
			i++;
		}
		while (i < end)
		{
			which_way(l, &b, i, 'a');
			indicer(*l);
			start = middle + 1;
			i++;
		}
	}
}
