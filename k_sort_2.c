/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:32:10 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/25 19:32:58 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_and_organise(t_node **a, t_node **b, t_chunk *ck)
{
	if (!a || !*a || !b || !ck)
		return ;
	pb(a, b);
	if ((*b)->i <= ck->soft)
		rb(b);
}

/* Llevar a TOP en A (emite ra/rra) */
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

/* Llevar a TOP en B (emite rb/rrb) */
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
