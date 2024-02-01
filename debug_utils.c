/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:04:51 by jebitrus          #+#    #+#             */
/*   Updated: 2024/01/05 16:04:58 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_details(char c, t_stack *stack)
{
	ft_printf ("stack%c\n", c);
	print_stack(stack);
	ft_printf ("%c size: %d\n", c, ft_stksize(stack));
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	ft_printf("    nval: data\n");
	while (current != NULL)
	{
		ft_printf("    %d: %d\n", current->nval, current->content);
		current = current->next;
	}
}

int	clear_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = 0;
	while (*stack)
	{
		(*stack)->content = 0;
		(*stack)->nval = 0;
		temp = *stack;
		*stack = temp->next;
		free(temp);
		temp = NULL;
	}
	free (stack);
	stack = NULL;
	return (0);
}

int	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i ++;
	}
	free(arr);
	arr = NULL;
	return (0);
}
