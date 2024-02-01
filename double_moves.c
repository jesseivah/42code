/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:05:37 by jebitrus          #+#    #+#             */
/*   Updated: 2024/01/05 16:05:46 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack **a, t_stack **b)
{
	if (*a && *b && (*a)->next && (*b)->next)
	{
		swap('x', a);
		swap('x', b);
		write (1, "ss\n", 3);
	}
}

void	rot_both(t_stack **a, t_stack **b)
{
	if (*a && *b && (*a)->next && (*b)->next)
	{
		rot('x', a);
		rot('x', b);
		write (1, "rr\n", 3);
	}
}

void	rev_rot_both(t_stack **a, t_stack **b)
{
	if (*a && *b && (*a)->next && (*b)->next)
	{
		rev_rot('x', a);
		rev_rot('x', b);
		write (1, "rrr\n", 4);
	}
}
