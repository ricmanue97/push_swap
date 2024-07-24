/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:00:03 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/24 11:51:10 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = last_node(*stack);
	tmp->next->prev = NULL;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	*stack = tmp;
}

void	ra(t_stack_node **a)
{
	ft_rotate(a);
	write(1, "ra", 2);
	write(1, "\n", 1);
}

void	rb(t_stack_node **b)
{
	ft_rotate(b);
	write(1, "rb", 2);
	write(1, "\n", 1);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr", 2);
	write(1, "\n", 1);
}
