/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:08:36 by jebitrus          #+#    #+#             */
/*   Updated: 2024/01/05 16:08:45 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* max loc*/
t_stack	*get_max_loc(t_stack *stack)
{
	t_stack	*max;
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current && current->nval > 0)
		current = current->next;
	max = current;
	while (current)
	{
		if (current->content > max->content && current->nval == 0)
			max = current;
		current = current->next;
	}
	return (max);
}

void	normalize(t_stack **stack)
{
	int			size;
	t_stack		*this;

	this = get_max_loc(*stack);
	size = ft_stksize(*stack);
	while (size > 0)
	{
		this->nval = size;
		size --;
		this = get_max_loc(*stack);
	}
}

int	ft_issorted(t_stack *a)
{
	t_stack	*current;

	current = a;
	while (current && current->next)
	{
		if (current->content < (current->next)->content)
			current = current->next;
		else
			return (0);
	}
	return (1);
}
