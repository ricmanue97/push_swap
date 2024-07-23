/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:56:54 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/18 14:04:46 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack_node **stack, t_stack_node **stack2)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (!stack || !stack2 || !(*stack)->next || !(*stack2)->next)
		return ;
	tmp = *stack;
	tmp2 = *stack2;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	tmp->next = tmp2;
	tmp2->prev = tmp;
	*stack2 = tmp;
}

void	ft_pb(t_stack_node **a, t_stack_node **b)
{
	ft_push(a, b);
	write(1, "pb", 2);
	write(1, '\n', 1);
}

void	ft_pa(t_stack_node **a, t_stack_node **b)
{
	ft_push(b, a);
	write(1, "pa", 2);
	write(1, '\n', 1);
}
