/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a->b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:39:45 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/22 16:12:46 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	median = stack_len(stack) / 2;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->higher_median = false;
		else
			stack->higher_median = true;
		stack = stack->next;
		i++;
	}
}

static void	ft_a_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*temp;
	t_stack_node	*target;
	long			smaller_target;

	while (a)
	{
		smaller_target = LONG_MIN;
		temp = b;
		while (temp)
		{
			if (temp->nbr > smaller_target && temp->nbr < a->nbr)
			{
				smaller_target = temp->nbr;
				target = temp;
			}
			temp = temp->next;
		}
		if (smaller_target == LONG_MIN)
			a->target = max_nbr(b);
		else
			a->target = smaller_target;
		a = a->next;
	}
}

void	ft_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = lenght(*a);
	len_b = lenght(*b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->higher_median))
			a->cost = len_a - (a->index);
		if (a->target->higher_median)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
	}
}

t_stack_node	ft_set_cheapest(t_stack_node *stack)
{
	long			cheapest;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest)
		{
			cheapest = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
	return (*cheapest_node);
}

void	ft_prep_stack_a(t_stack_node *a, t_stack_node *b)
{
	index(a);
	index(b);
	a_target(a, b);
	cost(a, b);
	cheapest(a);
}
