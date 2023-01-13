#include "push_swap.h"

void	main_function(t_pile **l)
{
	t_pile	*lr;
	int		top;
	t_pile	*tmp;
	int		j;

	//t_pile	*chunk1;
	//int		buttom=0;
	// t_pile	*chunk2;
	// t_pile	*chunk3;
	// t_pile	*chunk4;
	// t_pile	*chunk5;
	lr = *l;
	j = 0;
	tmp = malloc(sizeof(t_pile) * 20);
	while (lr)
	{
		while (j < 100)
		{
			if (j == 20 || j == 40 || j == 60 || j == 80 || j == 100)
				break ;
			top = scan_top(*l, j);
			//buttom = scan_buttom(*l, j);
			//if (top <= 101 - buttom)
			/////////////////////////////ft_top(l, &tmp, top);
			// else
			// 	ft_buttom(l, &tmp, buttom);
			printf("%d    %d\n ", j, j % 20);
			j++;
		}
		j = 0;
		// chunk1 = tmp;
		// free(tmp);
		//tmp = chunk2;
		// if (j == 40)
		// {
		// 	chunk2 = tmp;
		// 	free(tmp);
		// 	tmp = chunk3;
		// }
		// if (j == 60)
		// {
		// 	chunk3 = tmp;
		// 	free(tmp);
		// 	tmp = chunk4;
		// }
		// if (j == 80)
		// {
		// 	chunk4 = tmp;
		// 	free(tmp);
		// 	tmp = chunk5;
		// }
	}
	lr = lr->next;
	// chunk5 = tmp;
	// free(tmp);
}

int	scan_top(t_pile *l, int j)
{
	int	i;

	i = 0;
	if (!l)
		return (0);
	while (l)
	{
		if (l->data >= j && l->data <= j + 20)
		{
			return (i);
		}
		l = l->next;
		i++;
	}
	return (i);
}

void	ft_top(t_pile **l, t_pile **chank, int i)
{
	if (!*l)
		return ;
	if (!chank)
		return ;
	while (i)
	{
		rot(l);
		putstr("ra\n", 1);
		i--;
	}
	push(l, chank);
	putstr("pa", 1);
}

int	scan_buttom(t_pile *l, int j)
{
	int	i;
	int	ret;

	i = 0;
	if (!l)
		return (0);
	while (l)
	{
		if (l->data >= j && l->data <= j + 20)
		{
			ret = i;
		}
		l = l->next;
		i++;
	}
	return (ret);
}

void	ft_buttom(t_pile **l, t_pile **chank, int i)
{
	if (!*l)
		return ;
	if (!chank)
		return ;
	while (i)
	{
		rot(l);
		putstr("rra\n", 1);
		i--;
	}
	push(l, chank);
	putstr("pa", 1);
}
