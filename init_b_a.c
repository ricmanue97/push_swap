/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:31:27 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/24 11:27:51 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_b_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*temp;
	t_stack_node	*target;
	long			bigger_target;

	while (b)
	{
		bigger_target = LONG_MAX;
		temp = a;
		while (temp)
		{
			if (temp->nbr < bigger_target && temp->nbr > b->nbr)
			{
				bigger_target = temp->nbr;
				target = temp;
			}
			temp = temp->next;
		}
		if (bigger_target == LONG_MAX)
			b->target = min_nbr(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	ft_prep_stack_b(t_stack_node *a, t_stack_node *b)
{
	ft_index(a);
	ft_index(b);
	ft_b_target(a, b);
}
