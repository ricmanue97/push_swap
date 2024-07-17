/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:59:00 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/17 14:18:12 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;
	
	if (!*stack || !(*stack)->next)
		 return ;
	tmp = *stack;
	tmp2 = tmp->next;
	tmp2->next->prev = tmp;
	tmp2->next = tmp;
	tmp2->prev = NULL;
	*stack = tmp2;
}

void	sa(t_stack_node *a)
{
	swap(a);
	write(1, "sa", 2);
	write(1, '\n', 1);
}

void	sb(t_stack_node *b)
{
	swap(b);
	write(1, "sb", 2);
	write(1, '\n', 1);
}

void	ss(t_stack_node *a, t_stack_node *b)
{
	swap(a);
	swap(b);
	write(1, "ss", 2);
	write(1, '\n', 1);
}