/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_the_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:06:46 by aatki             #+#    #+#             */
/*   Updated: 2023/01/28 21:23:00 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_end(int data,int *tab,int size,int end)
{
    int middle = size/2;
    int i=0;
    if(end > size)
        end=size-1;
    while(i < size)
        {
            if(data >= tab[middle] && data <= tab[end])
                return 1;
            i++;
        }
        return 0;
}

int ft_start(int data,int *tab,int size,int start)
{
    int middle = size / 2;
    int i=0;
   if(start < 0)
    start=0;
    while(i < size)
    {
        if(data <= tab[middle] && data >= tab[start])
            return 1;
        i++;
    }
        return 0;
}

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
   
   int *tab=struct_to_tab(*l);
   trier_tab(tab,size);
   middle= size / 2;
    start=middle - offset;
    end=middle + offset;
    j=offset;
    i=offset;
    t_pile *tmp=*l;
   while(tmp)
   {
        if(ft_start(tmp->data,tab,size,start))
        {
          
            push(&tmp,&b);
            putstr("pb\n");
            rot(&b);
            putstr("rb\n");
            i--;
        }
        else
        tmp=tmp->next;
        if(!*l)
            break;
        if(ft_end(tmp->data,tab,size,end))
        {
            push(&tmp,&b);
            putstr("pb\n");
            j--;
        }
        else
        {
              tmp=tmp->next;
        }
        if(i== 0)
        {
            start-=offset;
           i=offset;
        }
        if(j==0)
        {
            end+=offset;
           j=offset;
        }
   }
    while (b)
		which_way(&b, l, max_list(b), 'b');
}
