#include "push_swap.h"

int	yes(t_pile *l)
{
	if (!l)
		return (1);
	while (l->next)
	{
		if (l->data > l->next->data)
			return (0);
		l = l->next;
		if (l == NULL)
			break ;
	}
	return (1);
}

int	*struct_to_tab(t_pile *l)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * ft_lstsize(l));
	if (!l)
		return (NULL);
	i = 0;
	while (l->next)
	{
		tab[i] = l->data;
		i++;
		l = l->next;
		if (l == NULL)
			break ;
	}
	return (tab);
}

void	indices(int *tab, t_pile *l)
{
	int	*tab2;
	int	i;

	tab2 = malloc(sizeof(int) * sizeof(tab));
	i = 0;
	while (l->next)
	{
		tab[i] = l->data;
		i++;
		l = l->next;
		if (l == NULL)
			break ;
	}
}

void	trier_tab(int *tab)
{
	int	i;
	int	swap;

	i = 0;
	while (tab[i])
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		i++;
	}
}

void	trier(t_pile *l)
{
	t_pile	*save;

	save = l;
	while (l)
	{
		if (!l->next)
			l = save;
		if (yes(save))
			break ;
		if (l->data > l->next->data)
		{
			swap(l);
			write(1, "swap a\n", 7);
			l = save;
		}
		l = l->next;
	}
}
