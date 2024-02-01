/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:42:25 by jebitrus          #+#    #+#             */
/*   Updated: 2024/01/03 15:42:30 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct node
{
	int			content;
	int			nval;
	struct node	*next;
}				t_stack;

/* Debug Utils */

void	print_stack(t_stack *stack);
int		clear_stack(t_stack **stack);
void	print_details(char c, t_stack *stack);
int		free_arr(char **arr);

/* Stack Utils */

void	ft_stkadd_front(t_stack **stack, t_stack *new);
void	ft_stkadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stknew(int content);
int		ft_stksize(t_stack *stack);

/* Push_swap */

//long long	ft_atoll(const char *nptr);
int		ft_parse(char **argv, int x);
//long long		ft_atoll(const char *nptr);
t_stack	**store_in_stack(t_stack **a, char **argv, int i);

/* Moves */

void	swap(char c, t_stack **ptr);
void	rot(char c, t_stack **ptr);
void	rev_rot(char c, t_stack **ptr);
void	push(char c, t_stack **x, t_stack **y);

/* Double Moves */

void	swap_both(t_stack **a, t_stack **b);
void	rot_both(t_stack **a, t_stack **b);
void	rev_rot_both(t_stack **a, t_stack **b);

/* Basic Sort */

void	basic_sort(t_stack **a, t_stack **b);

/* Normalize */

void	normalize(t_stack **stack);
int		ft_issorted(t_stack *a);

/* Radix Sort */

void	ft_radix_sort(t_stack **a, t_stack **b, int max);

#endif
