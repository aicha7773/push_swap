/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   again.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:05:24 by aatki             #+#    #+#             */
/*   Updated: 2023/01/29 04:11:23 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void the_one(t_pile **l)
{
    t_pile *b;
    b=NULL;
    indicer(*l);
    int i;
    int j;
    int middle;
	int offset;
	int end;
	int start;
    int size = ft_lstsize(*l);
    if(size <=10)
        offset=5;
    if(size <=150)
        offset=8;
    if(size > 150)
        offset=18;
    middle= size / 2;
    start=middle - offset;
    end=middle + offset;
    j=offset;
    i=offset;
    while(*l)
        {
            
            if((*l)->index <= middle && (*l)->index >= start)
            {
                push(l,&b);
                putstr("pb\n");
                rot(&b);
                putstr("rb\n");
                i++;
                
            }  
            if((*l)->index >= middle && (*l)->index <= end)
            {
                push(l,&b);
                putstr("pb\n");
                j--;
            }
            if(!*l)
                break;
            if(i== start)
            {
                 start-=offset;
                 i=0;
            }
            if(j == middle)
            {
                end+=offset;
                j=end;
            }
        }
    
    while (b)
		which_way(&b, l, max_list(b), 'b');
}

