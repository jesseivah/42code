/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:41:25 by jebitrus          #+#    #+#             */
/*   Updated: 2024/01/03 15:41:32 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_stack **a, t_stack **b, int max)
{
	int		digit;
	int		size;
	int		j;
	t_stack	*current;

	digit = 0;
	size = ft_stksize(*a);
	while (digit < max)
	{
		j = 0;
		while (j < size)
		{
			current = *a;
			if (((current->nval >> digit) & 1) == 1)
				rot ('a', a);
			else
				push ('b', a, b);
			j ++;
		}
		digit ++;
		while (ft_stksize(*b) > 0)
			push ('a', b, a);
	}
}
