/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:55:02 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/26 16:14:07 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_input_error(char *nbr)
{
	int	i;

	i = 0;
	if (!(nbr[i] == '+' || nbr[i] == '-' || (nbr[i] >= '0' && nbr[i] <= '9')))
		return (1);

	if ((nbr[i] < '0' && nbr[i] > '9'))
		return (1);
	while (nbr[i])
	{
		if ((nbr[i] < '0' && nbr[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_dup_error(t_stack_node *stack, int num)
{
	if (!stack)
	{
		return (0);
	}
	while (stack != NULL)
	{
		if (stack->nbr == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_free_stack(t_stack_node **a)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (a == NULL)
		return ;
	current = *a;
	while (current != NULL)
	{
		current->nbr = 0;
		temp = current;
		current = current->next;
		free(temp);
	}
	*a = NULL;
	return ;
/* 	t_stack_node	*tmp;

	if (!*stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL; */
}

void	ft_error_handle(t_stack_node **stack)
{
	ft_free_stack(stack);
	write (1, "Error\n", 7);
	exit (1);
}
