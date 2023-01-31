/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:00:01 by aatki             #+#    #+#             */
/*   Updated: 2023/01/31 18:02:13 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int c, char **v)
{
	t_pile	*t;

	check_input(v);
	t = in_pile(v);
	duplicated(t);
	// t_pile *b=NULL;
	// b=NULL;
	// rot(&t);
	// //affiche(b);
	// printf("heeeeere\n");
	// affiche(t);


	if (no_need(t))
		return ;
	if (c == 3 && t->data < t->next->data)
		putstr("sa");
	if (c == 4)
		if_three(t);
	if(c == 6)
		if_five(t);
	if (c > 6)
		the_one(&t);

}

int	main(int c, char **v)
{
	if (c > 1)
		push_swap(c, v);
}
