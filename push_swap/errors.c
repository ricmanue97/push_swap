/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:55:02 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/03 15:10:19 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_error(char *nbr)
{
	int	i;

	i = 0;
	if (!(nbr[i] == '+' || nbr[i] == '-' || (nbr[i] >= '0' && nbr[i] <= '9')))
		return (1);
	i++;
	if (!(nbr[i] >= '0' && nbr[i] <= '9'))
		return (1);
	while (nbr[i] != '\0')
	{
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	dup_error(t_stack_node *stack, int num)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->nbr == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		free(stack);
		stack = tmp;
	}
	*stack = NULL;
}

void	error_handle(t_stack_node *stack)
{
	free_stack(stack);
	write (1, "error", 6);
	exit (1);
}
