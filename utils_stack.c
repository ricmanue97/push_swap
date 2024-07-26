/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:25:46 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/26 13:27:52 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	length(t_stack_node *stack)
{
	int				i;
	t_stack_node	*tmp;

	i = 0;
	if (!stack)
		return (0);
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack_node	*last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack_node	*min_nbr(t_stack_node *stack)
{
	t_stack_node	*min_node;
	long			small_target;

	small_target = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < small_target)
		{
			small_target = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*max_nbr(t_stack_node *stack)
{
	t_stack_node	*max_node;
	long			big_target;

	big_target = LONG_MIN;
	while (stack != NULL)
	{
		if (stack->nbr > big_target)
		{
			big_target = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

bool	ft_sorted(t_stack_node *stack)
{
	if (!stack)
		return (false);
	while (stack != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
