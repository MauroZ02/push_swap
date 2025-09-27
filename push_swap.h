/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:51 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/27 17:04:28 by mzangaro         ###   ########.fr       */
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

/* mvs_push.c */
t_node	*remove_front(t_node **top);
void	add_front(t_node **top, t_node *n);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);

/* mvs_reverse_rot.c */
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* mvs_rotate.c */
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

/* mvs_swap.c */
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

/* stack_utils_0.c */
t_node	*new_node(int value);
void	add_back(t_node **a, t_node *n);
int		stack_len(t_node *stack);
void	free_stack(t_node **stack);
void	exit_and_free(t_node **a, t_node **b);

/* parsing_0.c */
int		has_space(const char *str);
int		has_duplicate(t_node *a, int v);
int		is_digit(const char *str);
int		is_sorted(t_node *stack);

/* parsing_1.c */
int		aux_overflow(const char *str, int *out_i, int *out_sign);
int		overflow(const char *str, int *out);
int		atoi_overflow(const char *str, int *out, t_node *a);

/* indexing.c */
int		count_smaller(t_node *head, int value);
void	assign_index(t_node *a);
int		find_smaller_index(t_node *a);
void	smaller_to_top(t_node **a, int pos);

/* mini_sort.c */
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	sort_stack(t_node **a, t_node **b);

/* k_sort_0.c */
int		find_max_index(t_node *stack);
int		pos_index(t_node *stack, int index);
void	pos_to_top_a(t_node **a, int pos);
void	pos_to_top_b(t_node **b, int pos);

/* algorithm.c */
void	phase_one(t_node **a, t_node **b);
void	phase_two(t_node **a, t_node **b);
void	k_sort(t_node **a, t_node **b);

/* main_utils.c */
void	verify_args(char **parts, t_node **a, t_node **b);
char	*only_space(const char *arg);
char	**split_args(const char *arg, t_node **a, t_node **b);

#endif
