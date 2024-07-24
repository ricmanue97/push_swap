/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:34:21 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/24 11:50:04 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	ft_init_stack_a(&a, argv);
	if (!ft_sorted(a))
	{
		if (length(a) == 2)
			sa(&a);
		else if (length(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	ft_free_stack(&a);
}
