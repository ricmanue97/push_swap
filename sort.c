/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:50:48 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/24 11:55:40 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_both(t_stack_node **a,
	t_stack_node **b,
	t_stack_node *cheapest_node)
{
	while (!(*a == cheapest_node) && !(*b == cheapest_node->target))
		rr(a, b);
	ft_index(*a);
	ft_index(*b);
}

static void	ft_rev_rotate_both(t_stack_node **a,
	t_stack_node **b,
	t_stack_node *cheapest_node)
{
	while (!(*a == cheapest_node) && !(*b == cheapest_node->target))
		rrr(a, b);
	ft_index(*a);
	ft_index(*b);
}

static void	ft_move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = ft_set_cheapest(*a);
	if (cheapest_node->higher_median && cheapest_node->target->higher_median)
		ft_rev_rotate_both(a, b, cheapest_node);
	else
		ft_rotate_both(a, b, cheapest_node);
	ft_prep_push_a(a, cheapest_node);
	ft_prep_push_b(b, cheapest_node->target);
	pb(a, b);
}

static void	ft_move_b_to_a(t_stack_node **b, t_stack_node **a)
{
	ft_prep_push_a(a, (*b)->target);
	pa(a, b);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = length(*a);
	if (len > 3 && !ft_sorted(*a))
		pb(a, b);
	if (len > 3 && !ft_sorted(*a))
		pb(a, b);
	while (len > 3 && !ft_sorted(*a))
	{
		ft_prep_stack_a(*a, *b);
		ft_move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		ft_prep_stack_a(*a, *b);
		ft_move_b_to_a(b, a);
	}
	ft_index(*a);
	ft_min_to_top(a);
}
