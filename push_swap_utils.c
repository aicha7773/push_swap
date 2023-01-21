/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:05:26 by aatki             #+#    #+#             */
/*   Updated: 2023/01/21 09:13:59 by aatki            ###   ########.fr       */
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

void	putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	ft_error(void)
{
	int		i;
	char	*s;

	s = "Error\n";
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	exit(1);
}

t_pile	*in_pile(char **v)
{
	int		i;
	t_pile	*l;

	l = NULL;
	i = 1;
	while (v[i])
	{
		ft_lstadd_back(&l, ft_lstnew(ft_atoi(v[i])));
		i++;
	}
	return (l);
}

void	affiche(t_pile *p)
{
	if (!p)
		return ;
	if (!p->next)
	{
		printf("%d  %d\n", p->data, p->index);
		return ;
	}
	while (p)
	{
		printf("%d  %d\n", p->data, p->index);
		p = p->next;
	}
}
