/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:36:21 by ricmanue          #+#    #+#             */
/*   Updated: 2024/07/24 11:49:32 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					cost;
	bool				higher_median;
	bool				cheapest;

	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

//error handling
int				ft_input_error(char *nbr);
int				ft_dup_error(t_stack_node *stack, int num);
void			ft_free_stack(t_stack_node **stack);
void			ft_error_handle(t_stack_node **stack);

//stack initialization
int				ft_atol(const char *nbr);
void			ft_init_stack_a(t_stack_node **stack, char **argv);
void			ft_index(t_stack_node *stack);
void			ft_cost(t_stack_node *a, t_stack_node *b);
t_stack_node	*ft_set_cheapest(t_stack_node *stack);
void			ft_prep_stack_a(t_stack_node *a, t_stack_node *b);
void			ft_prep_stack_b(t_stack_node *a, t_stack_node *b);

//commands
void			pb(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

//sorting
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);

//prep
void			ft_prep_push_a(t_stack_node **a, t_stack_node *target_node);
void			ft_prep_push_b(t_stack_node **b, t_stack_node *target_node);
void			ft_min_to_top(t_stack_node **a);

//utils_stack
int				length(t_stack_node *stack);
t_stack_node	*last_node(t_stack_node *stack);
t_stack_node	*min_nbr(t_stack_node *stack);
t_stack_node	*max_nbr(t_stack_node *stack);
bool			ft_sorted(t_stack_node *stack);
#endif
