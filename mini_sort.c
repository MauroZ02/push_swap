/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:36:57 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/27 20:33:43 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a)
{
	t_node	*first;
	t_node	*next;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	next = first->next;
	if (first->value > next->value)
		sa(a);
}

void	sort_three(t_node **a)
{
	t_node	*first;
	t_node	*next;
	t_node	*last;

	if (a == NULL || *a == NULL || (*a)->next == NULL
		|| (*a)->next->next == NULL)
		return ;
	first = *a;
	next = first->next;
	last = next->next;
	if (first->value > next->value && first->value > last->value)
		ra(a);
	else if (first->value < next->value && next->value > last->value)
		rra(a);
	first = *a;
	next = first->next;
	last = next->next;
	if (first->value > next->value)
		sa(a);
}

void	sort_four(t_node **a, t_node **b)
{
	int		pos;

	if (a == NULL || *a == NULL || (*a)->next == NULL
		|| (*a)->next->next == NULL || (*a)->next->next->next == NULL)
		return ;
	pos = find_smaller_index(*a);
	smaller_to_top(a, pos);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	int	pos;

	if (a == NULL || *a == NULL || (*a)->next == NULL
		|| (*a)->next->next == NULL || (*a)->next->next->next == NULL
		|| (*a)->next->next->next->next == NULL)
		return ;
	pos = find_smaller_index(*a);
	smaller_to_top(a, pos);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_stack(t_node **a, t_node **b)
{
	int	len;

	if (is_sorted(*a))
		return ;
	len = stack_len(*a);
	if (len == 2)
		sort_two(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 4)
		sort_four(a, b);
	else if (len == 5)
		sort_five(a, b);
	else if (len > 5)
		k_sort(a, b);
}
