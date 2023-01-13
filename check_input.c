/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:03:01 by aatki             #+#    #+#             */
/*   Updated: 2023/01/07 13:42:37 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char **f)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (f[i])
	{
		if (f[i][j] == '-' || f[i][j] == '+')
			j++;
		while (f[i][j])
		{
			if (!(f[i][j] >= '0' && f[i][j] <= '9'))
				ft_error("there is an other character");
			j++;
		}
		j = 0;
		i++;
	}
	return (i - 1);
}

int	ft_max(unsigned long long a, int sign)
{
	if (a >= 9223372036854775807 && sign == 1)
		return (-1);
	else if (a > 9223372036854775807 && sign == -1)
		return (1);
	return ((int)a * sign);
}

int	ft_atoi(char *str)
{
	int					i;
	int					s;
	unsigned long long	a;

	i = 0;
	s = 1;
	a = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - '0';
		i++;
	}
	return (ft_max(a, s));
}
