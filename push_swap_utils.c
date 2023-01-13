/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:05:26 by aatki             #+#    #+#             */
/*   Updated: 2023/01/11 17:19:38 by aatki            ###   ########.fr       */
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

void	putstr(char *s, int j)
{
	int	i;

	i = -1;
	while (s[++i])
		write(j, &s[i], 1);
}

void	ft_error(char *s)
{
	(void)s;
	putstr("Error\n", 2);
	exit(1);
}

t_pile	*in_pile(char **v, int num)
{
	t_pile	*l;
	t_pile	*tmp;
	int		i;

	(void)num;
	i = 1;
	while (v[i])
	{
		tmp = ft_lstnew(ft_atoi(v[i]));
		ft_lstadd_back(&l, tmp);
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
		printf("%d\n", p->data);
		return ;
	}
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}
