/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:12:45 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/18 14:04:31 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = last_node(*stack);
	tmp2->prev->next = NULL;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = NULL;
	*stack = tmp2;
}

void	ft_rra(t_stack_node **a)
{
	ft_reverse_rotate(a);
	write(1, "rra", 3);
	write(1, '\n', 1);
}

void	ft_rrb(t_stack_node **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb", 3);
	write(1, '\n', 1);
}

void	ft_rrr(t_stack_node **a, t_stack_node **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr", 3);
	write(1, '\n', 1);
}
