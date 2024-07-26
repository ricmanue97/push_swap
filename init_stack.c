/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:54:32 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/26 16:15:11 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *nbr)
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

static void	ft_add_node(t_stack_node **a, int nbr)
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
	if (*a == NULL)
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

void	ft_init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	long	nbr;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_input_error(argv[i]) == 1)
			ft_error_handle(a);
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN && nbr > INT_MAX)
			ft_error_handle(a);
		if (ft_dup_error(*a, nbr) == 1)
			ft_error_handle(a);
		ft_add_node(a, nbr);
		i++;
	}
}
