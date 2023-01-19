/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:03:01 by aatki             #+#    #+#             */
/*   Updated: 2023/01/19 17:54:39 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
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
		if (!ft_strncmp(f[i], "2147483647", 10) || !ft_strncmp(f[i],
				"-2147483648", 11))
			exit(0);
		ft_atoi(f[i]);
		i++;
	}
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
	if (!(str[i] >= '0' && str[i] <= '9'))
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - '0';
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		ft_error();
	return (ft_max(a, s));
}
