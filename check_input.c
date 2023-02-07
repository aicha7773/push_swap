/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:03:01 by aatki             #+#    #+#             */
/*   Updated: 2023/02/06 23:42:26 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_need(t_pile *l)
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((unsigned char)s1[i] < (unsigned char)s2[i])
		return (-1);
	else if ((unsigned char)s1[i] > (unsigned char)s2[i])
		return (1);
	else
		return (0);
}

void	check_input(char **f)
{
	int	i;

	i = 1;
	while (f[i])
	{
		if (!ft_strcmp(f[i], "2147483647") || !ft_strcmp(f[i], "-2147483648"))
			ft_error();
		ft_atoi(f[i]);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int					i;
	int					s;
	unsigned long long	a;

	i = 0;
	s = 1;
	a = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - '0';
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		ft_error();
	return (a * s);
}
