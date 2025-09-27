/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k-sort_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 02:19:50 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/27 21:15:21 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* it returns the max index value, not its position. (-1) = Error */
int	find_max_index(t_node *stack)
{
	t_node	*current;
	int		max;

	if (stack == NULL)
		return (-1);
	current = stack;
	max = current->i;
	while (current != NULL)
	{
		if (current->i > max)
			max = current->i;
		current = current->next;
	}
	return (max);
}

/* it returns the position of the desired index. (-1) = Error */
int	pos_index(t_node *stack, int index)
{
	t_node	*current;
	int		pos;

	if (stack == NULL)
		return (-1);
	current = stack;
	pos = 0;
	while (current != NULL)
	{
		if (current->i == index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

/* leads the desired a index to top */
void	pos_to_top_a(t_node **a, int pos)
{
	int	len;
	int	steps;

	if (!a || !*a || pos < 0)
		return ;
	len = stack_len(*a);
	if (pos <= len / 2)
	{
		steps = pos;
		while (steps > 0)
		{
			ra(a);
			steps--;
		}
	}
	else
	{
		steps = len - pos;
		while (steps > 0)
		{
			rra(a);
			steps--;
		}
	}
}

/* leads the desired b index to top */
void	pos_to_top_b(t_node **b, int pos)
{
	int	len;
	int	steps;

	if (!b || !*b || pos < 0)
		return ;
	len = stack_len(*b);
	if (pos <= len / 2)
	{
		steps = pos;
		while (steps > 0)
		{
			rb(b);
			steps--;
		}
	}
	else
	{
		steps = len - pos;
		while (steps > 0)
		{
			rrb(b);
			steps--;
		}
	}
}
