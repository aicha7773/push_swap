/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_the_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:06:46 by aatki             #+#    #+#             */
/*   Updated: 2023/02/05 22:24:31 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pos(t_pile *p,int d)
{
    int i = 0;

    t_pile *l;
    
    l=p;
    while(l)
    {
        if(l->data == d)
            return (i);
        l = l->next;
        i++;
    }
    return (-1);
}

void	the_ona(t_pile **l)
{
    //real safe spot
	int		i;
	t_pile	*tmp;
	t_pile	*b;
	int		size;
    int j;

    size = ft_lstsize(*l);
    if(size <= 100)
    {
        i = 15;
        j = 15;
    }
    if(size > 100)
    {
        i = 40;
        j = 40;
    }
	tmp = *l;
	b = NULL;
    indicer(*l);
    // affiche(*l);
	while (*l)
	{
        while (j && *l)
        {
            if ((*l)->index < i)
            {
                //(*l)=(*l)->next;
                which_way(l,&b,pos(*l,(*l)->data),'a');
                j--;
            }
            else
            {
                rot(l);
                putstr("ra\n");
            }
        }
         if(size <= 100)
         {
            i += 15;
            j += 15;
         }
        if(size > 100)
        {
            i += 40;
            j += 40;
        }
        if (i > size)
            i = size;
        if(ft_lstsize(*l))
        if(no_need(*l))
            break;
	}
   // indicer(*l);
    while (b)
		which_way(&b, l, max_list(b), 'b');
    indicer(*l);
   // affiche(*l);
}
