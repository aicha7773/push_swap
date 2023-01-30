/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_the_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:06:46 by aatki             #+#    #+#             */
/*   Updated: 2023/01/30 19:58:25 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pos(t_pile *l,int d)
{
    int i = 0;

    while(l)
    {
        if(l->data == d)
            break;
        l = l->next;
        i++;
    }
    return i;
}

int in_zone(t_pile *l,int data,int min,int max)
{

    while(l)
    {
        if(l->data == data && l->index >=min && l->index <=max)
            return 1;
        l=l->next;
    }
    return 0;
}

void	the_one(t_pile **l)
{
    //real safe spot
	int		i;
	t_pile	*tmp;
	t_pile	*b;
	int		size;
    int j;

    size = ft_lstsize(*l);
    if(size <= 100)
	    i = 14;
    if(size > 100)
        i = 40;
    j = 14;
	tmp = *l;
	b = NULL;
    int d;
    indicer(*l);
    // affiche(*l);
	while (*l)
	{
        tmp = *l;
        while (j && tmp)
        {
            if (tmp->index < i)
            {
                d=tmp->data;
                tmp=tmp->next;
                which_way(l,&b,pos(*l,d),'a');
                j--;
            }
            else
            tmp = tmp->next;
        }
        j += 14;
        i += 14;
        if (i > size)
            i = size;
        if(no_need(*l))
            break; 
	}
   // indicer(*l);
    while (b)
		which_way(&b, l, max_list(b), 'b');
        indicer(*l);
   // affiche(*l);
    
    
}
