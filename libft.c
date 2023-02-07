/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:29:58 by aatki             #+#    #+#             */
/*   Updated: 2023/02/06 23:19:38 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelback(t_pile **lst)
{
	t_pile	*tmp;

	tmp = *lst;
	if (!*lst)
		return ;
	if (!(*lst)->next)
	{
		free(*lst);
		return ;
	}
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

void	ft_lstiter(t_pile *lst, void (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}

t_pile	*ft_lstlast(t_pile *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_pile *p)
{
	t_pile	*lst;
	int		i;

	lst = p;
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_lstlastint(t_pile *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst->data);
}
