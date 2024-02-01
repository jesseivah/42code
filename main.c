/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:36:06 by jebitrus          #+#    #+#             */
/*   Updated: 2024/01/03 15:40:11 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* max nval binary digits*/
static int	max_bin_digits(t_stack *stack)
{
	int			max;
	int			n;
	t_stack		*current;

	n = 0;
	if (!stack)
		return (0);
	current = stack;
	max = current->nval;
	while (current)
	{
		if (current->nval > max)
			max = current->nval;
		current = current->next;
	}
	while (max > 0)
	{
		max = max >> 1;
		n ++;
	}
	return (n);
}

static void	ft_pushswap(t_stack **a, t_stack **b)
{
	int	max;

	normalize(a);
	if (ft_stksize(*a) <= 5)
		basic_sort(a, b);
	else
	{
		max = max_bin_digits(*a);
		ft_radix_sort(a, b, max);
	}
	clear_stack(a);
	clear_stack(b);
}

static int	ft_err(void)
{
	write (2, "Error\n", 6);
	return (0);
}

static int	ft_init(char **argv, int x)
{
	t_stack	**a;
	t_stack	**b;

	a = NULL;
	b = NULL;
	if (ft_parse(argv, x) < 0)
		return (ft_err());
	a = store_in_stack(a, argv, x);
	if (a == 0)
		return (ft_err());
	if (ft_issorted(*a))
		return (clear_stack(a));
	b = malloc (sizeof(t_stack **));
	if (!b)
	{
		ft_err();
		return (clear_stack(a));
	}
	*b = NULL;
	ft_pushswap(a, b);
	if (x == 0)
		free_arr(argv);
	return (1);
}

/*Main for Push Swap*/
int	main(int argc, char **argv)
{
	char	**arr;

	arr = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (0);
		if (arr[0] == (void *)0)
			return (free_arr(arr));
		if (ft_init(arr, 0))
			return (0);
		else
			return (free_arr(arr));
	}
	else
		ft_init(argv, 1);
	return (0);
}
