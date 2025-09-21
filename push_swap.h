/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:51 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/21 19:35:15 by mzangaro         ###   ########.fr       */
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
	int				i;
	int				value;
	struct s_node	*next;
}	t_node;

/* movements_0.c */
t_node	*remove_front(t_node **top);
void	add_front(t_node **top, t_node *n);
void	add_back(t_node **a, t_node *n);
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

/* parsing_0.c */
void	free_stack(t_node **stack);
void	exit_and_free(t_node **a, t_node **b);
int		has_space(const char *str);
int		is_digit(const char *str);
int		has_duplicate(t_node *a, int v);

/* parsing_1.c */
int		aux_overflow(const char *str, int *out_i, int *out_sign);
int		overflow(const char *str, int *out);
int		atoi_overflow(const char *str, int *out, t_node *a);

/* stack_core.c */
t_node	*new_node(int value);
t_node	*last_node(t_node *a);
int		stack_len(t_node *stack);
int		is_sorted(t_node *stack);

#endif