/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:18:52 by aatki             #+#    #+#             */
/*   Updated: 2023/02/06 23:20:55 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = (*lst);
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

t_pile	*ft_lstnew(int content)
{
	t_pile	*l;

	l = malloc(sizeof(t_pile));
	if (!l)
		return (NULL);
	l->data = content;
	l->next = NULL;
	return (l);
}

void	ft_lstadd_front(t_pile **lst, t_pile *new)
{
	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstdelfront(t_pile **lst)
{
	t_pile	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	tmp = tmp->next;
	free(*lst);
	*lst = tmp;
}
