/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:51 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/08 22:31:58 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/* movements_0.c */
t_node	*new_node(int value);
t_node	*remove_front(t_node **top);
void	add_at_top(t_node **top, t_node *n);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);

/* movements_1.c */
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

/* movements_2.c*/
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

/* movements_3.c*/
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* parsing.c */
void	free_stack(t_node **stack);
void	exit_and_free(t_node **a, t_node **b);

/* stack_core.c */
t_node	*last_node(t_node *a);
void	add_back(t_node **a, t_node *n);
int		stack_len(t_node *stack);
int		is_sorted(t_node *stack);

#endif