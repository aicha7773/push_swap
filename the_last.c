/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:44:24 by aatki             #+#    #+#             */
/*   Updated: 2023/02/01 20:03:34 by aatki            ###   ########.fr       */
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

int	ft_pos(t_pile *lst, int val)
{
	int	i;
	int	indice;

	indice = 0;
	i = 0;
	while (lst)
	{
		if (lst->index == val)
		{
			indice = i;
		}
		i++;
		lst = lst->next;
	}
	return (indice);
}

void	main_function(t_pile **l)
{
	int		i;
	t_pile	*b;
	int		r;
	int		size;
	int		count;

	i = 0;
	count = 0;                                                                                                                          
	size = ft_lstsize(*l);
	b = NULL;
	r = 20;
	indicer(*l);
	//affiche(*l);
	while (*l )
	{
		if ((*l)->index > count + 20)
		{
			push(l, &b);
			putstr("pb\n");
			count ++;
		}
		else if ((*l)->index < count)
		{
			push(l, &b);
			putstr("pb\n");
			rot(&b);
			putstr("rb\n");
			count++;
		}
		else
		{
			rot(l);
			putstr("ra\n");
			count++;
		}
		// if(no_need(*l))
		// 	   break;
	}
	
	// while (i < size)
	// {
	// 	which_way(l, &b, ft_pos(*l, i), 'a');
	// 	// if (i == r)
	// 	// 	r += 15;
	// 	i++;
	// }
	//indicer(*l);
	//affiche(*l);
	while (b)
		which_way(&b, l, max_list(b), 'b');
	// if (yes(*l))
	// 	printf("\n\nfkvbkggtgbhrtbk\n\n");
}
