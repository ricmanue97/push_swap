/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:12:42 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/22 16:12:05 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prep_push_a(t_stack_node **a, t_stack_node *target_node)
{
	if (target_node->higher_median)
		ra(*a);
	else
		rra(*a);
}

void	ft_prep_push_b(t_stack_node **b, t_stack_node *target_node)
{
	if (target_node->higher_median)
		rb(*b);
	else
		rrb(*b);
}

void	ft_min_to_top(t_stack_node **a)
{
	t_stack_node	*tmp;

	tmp = min_nbr(*a);
	while ((*a)->nbr != tmp->nbr)
	{
		if (tmp->higher_median)
			ra(a);
		else
			rra(a);
	}
}
