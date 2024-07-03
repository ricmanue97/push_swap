/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a->b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:39:45 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/02 17:50:13 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index(t_stack_node *x)
{
	int	i;
	int	median;

	i = 0;
	median = stack_len(x) / 2;
	if (!x)
		return ;
	while (x)
	{
		x->index = i;
		if (i <= median)
			x->higher_median = false;
		else
			x->higher_median = true;
		x = x->next;
		i++;
	}
}

static void	a_target(t_stack_node *a, t_stack_node *b)
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

void	init_stack_a(t_stack_node *a, t_stack_node *b)
{
	index(a);
	index(b);
	a_target(a, b);
	cost(a, b);
	cheapest(a);
}
