/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:39:53 by aatki             #+#    #+#             */
/*   Updated: 2023/02/03 16:40:30 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int main(int c,char **v)
{
    t_pile  *t;

    if( c > 1)
    {
        check_input(v);
        t = in_pile(v);
        duplicated(t);
        checker(t);
        ft_free(t);
        
        system("leaks checker");
    }
}
