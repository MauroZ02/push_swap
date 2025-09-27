/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k-sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:19:53 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/27 21:17:08 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* case A -> smaller than j; then push to B
	case B-> is inside the range; then push to B
	case C-> is greater than range; then rotate A */
static void	stratify(t_node **a, t_node **b, int *base, int range)
{
	if ((*a)->i <= (*base))
	{
		pb(a, b);
		(*base)++;
	}
	else if ((*a)->i <= (*base) + range)
	{
		pb(a, b);
		(*base)++;
		if (*a && (*a)->i > (*base) + range)
			rr(a, b);
		else
			rb(b);
	}
	else
		ra(a);
}

/* calculates the √stack to stratify the stack */
void	phase_one(t_node **a, t_node **b)
{
	int	base;
	int	range;
	int	size;

	if (!a || !*a)
		return ;
	size = stack_len(*a);
	range = 0;
	while ((range * range) <= size)
		range++;
	range--;
	range = (range * 14) / 10;
	base = 0;
	while (*a)
	{
		stratify(a, b, &base, range);
	}
}

/* finds the greatest index, leads it to top and pushes it to A */
void	phase_two(t_node **a, t_node **b)
{
	int	max;
	int	pos;

	while (*b)
	{
		max = find_max_index(*b);
		pos = pos_index(*b, max);
		if (pos == -1)
			break ;
		pos_to_top_b(b, pos);
		pa(a, b);
	}
	if (a && *a)
	{
		pos = pos_index(*a, 0);
		if (pos != -1)
			pos_to_top_a(a, pos);
	}
}

void	k_sort(t_node **a, t_node **b)
{
	int	len;

	if (a == NULL || *a == NULL)
		return ;
	len = stack_len(*a);
	if (len <= 5 || is_sorted(*a))
		return ;
	phase_one(a, b);
	phase_two(a, b);
}
