
#include "push_swap.h"

void	ft_lstadd_front(t_pile **lst, t_pile *new)
{
	if (new)
	{
		if (!lst)
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
	if (!(*lst)->next)
	{
		free(*lst);
		return ;
	}
	tmp = *lst;
	tmp = tmp->next;
	free(*lst);
	*lst = tmp;
}

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

int	ft_lstsize(t_pile *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
