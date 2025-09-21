/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:36:57 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/21 21:31:25 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a)
{
	t_node	*first;
	t_node	*next;

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

	first = *a;
	next = first->next;
	last = next->next;
	if (a == NULL || *a == NULL || next == NULL || last == NULL)
		return;
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
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;

	first = *a;
	second = first->next;
	third = second->next;
	last = third->next;
	pb(a, b);
	sort_three(a);
	pa(a, b);
	if (first->value > second->value)
		sa(a);
	else if (first->value < last->value)
	{
		
	}

}
void	sort_five(t_node **a, t_node **b)
{
	
}

void	sort_stack(t_node **a, t_node **b)
{
	if (stack_len(a) == 2)
		sort_two(a);
	else if (stack_len(a) == 3)
		sort_three(a);
	else if (stack_len(a) == 4)
		sort_four(a, b);
	else if (stack_len(a) == 5)
		sort_five(a, b);
	else if (stack_len(a) > 5)
		k_sort(a, b);
}
