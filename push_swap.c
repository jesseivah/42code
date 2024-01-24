/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:43:21 by jebitrus          #+#    #+#             */
/*   Updated: 2024/01/03 15:43:27 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_for_dup(char **argv, int x)
{
	int			i;
	int			j;
	long long	a;
	long long	b;

	i = x;
	while (argv[i])
	{
		a = ft_atoll(argv[i]);
		if (a < -2147483648 || a > 2147483647)
			return (-1);
		j = x;
		while (argv[j])
		{
			b = ft_atoll(argv[j]);
			if (b < -2147483648 || b > 2147483647)
				return (-1);
			if (i != j && a == b)
				return (-1);
			j ++;
		}
		i ++;
	}
	return (0);
}

static int	parse_for_type(char *str)
{
	int		digits;
	int		i;

	i = 0;
	digits = 0;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		i ++;
		digits ++;
	}
	if (str[i] == '\0' && digits > 0)
		return (0);
	else
		return (-1);
}

int	ft_parse(char **argv, int x)
{
	int	i;

	i = x;
	while (argv[i])
	{
		if (parse_for_type(argv[i]) < 0)
			return (-1);
		i ++;
	}
	if (parse_for_dup(argv, x) < 0)
		return (-1);
	return (0);
}

t_stack	**store_in_stack(t_stack **a, char **argv, int x)
{
	int			i;
	long long	c;

	i = x;
	a = malloc(sizeof(t_stack **));
	if (!a)
		return (0);
	*a = NULL;
	while (argv[i])
	{
		c = ft_atoll(argv[i]);
		if (c >= -2147483648 && c <= 2147483647)
		{
			ft_stkadd_back(a, ft_stknew(c));
			i ++;
		}
		else
		{
			clear_stack(a);
			return (0);
		}
	}
	return (a);
}
