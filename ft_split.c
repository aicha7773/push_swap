/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:46:22 by aatki             #+#    #+#             */
/*   Updated: 2023/02/09 15:54:35 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compt1(char const *s, char c)
{
	int	i;
	int	cmpt;

	i = 0;
	cmpt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[0] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			cmpt++;
		i++;
	}
	return (cmpt);
}

static int	word(char const *s, char c)
{
	int	k;

	k = 0;
	if (!s)
		return (0);
	while (s[k] && s[k] != c)
	{
		k++;
	}
	return (k);
}

char	**ft_freee(char **p, int len)
{
	int	i;

	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	char	**p;
	int		len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = compt1(s, c);
	p = malloc(sizeof(char *) * (len + 1));
	if (!p)
		return (NULL);
	while (*s && i < len)
	{
		while (*s == c)
			s++;
		p[i] = ft_substr(s, 0, word(s, c));
		if (!p[i])
			return (ft_freee(p, i));
		s += word(s, c);
		i++;
	}
	p[i] = NULL;
	return (p);
}
