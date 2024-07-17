/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:54:32 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/12 10:10:50 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atol(const char *nbr)
{
	int		i;
	int		neg;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			neg = -1;
		i++;
	}
	while (nbr[i] != '\0')
	{
		num = num * 10 + (nbr[i] - 48);
		i++;
	}
	return (neg * num);
}

static void	add_node(t_stack_node **a, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!a)
		return ;
	node = malloc(sizeof (t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = last_node(*a);
		last->next = node;
		node->prev = last;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	long	nbr;

	i = 0;
	while (argv[i] != '\0')
	{
		if (input_error(argv[i]) == 1)
			error_handle(a);
		nbr = atol(argv[i]);
		if (nbr < INT_MIN && nbr > INT_MAX)
			error_handle(a);
		if (dup_error(*a, nbr) == 1)
			error_handle(a);
		add_node(a, nbr);
		i++;
	}
}
