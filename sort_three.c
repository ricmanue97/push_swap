/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:14:57 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/23 14:14:09 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node *tmp;

	tmp = max_nbr(*a);
	if (tmp == *a)
		ra(a);
	else if ((*a)->next == tmp)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
