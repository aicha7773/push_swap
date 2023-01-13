#include "push_swap.h"

void	if_trois(t_pile *l)
{
	int	a;
	int	b;
	int	c;

	a = l->data;
	b = l->next->data;
	c = l->next->next->data;
	//printf("a= %d b=%d c=%d", a, b, c);
	if (a < c && c < b)
	{
		putstr("sa\n", 1);
		putstr("ra\n", 1);
	}
	else if (b < c && c < a)
	{
		putstr("ra\n", 1);
	}
	else if (b < a && a < c)
	{
		putstr("sa\n", 1);
	}
	else if (c < b && b < a)
	{
		putstr("sa\n", 1);
		putstr("rra\n", 1);
	}
	else if (c < a && a < b)
	{
		putstr("rra\n", 1);
	}
}
