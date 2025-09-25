/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:19:53 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/25 04:48:18 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_first_pos_in_chunk(t_node *a, int high)
{
	t_node *current = a;
	int pos = 0;
	while (current != NULL)
	{
		if (current->i <= high)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

static void	find_last_pos_and_len(t_node *a, int high, int *pos_bottom, int *len)
{
	t_node *current = a;
	int pos = 0, local = 0;
	*pos_bottom = -1;
	while (current != NULL)
	{
		if (current->i <= high)
			*pos_bottom = pos;
		pos++;
		local++;
		current = current->next;
	}
	*len = local;
}

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

/* this function scans the stack and finds the suitable index to push either
	 a index in top position, or in bottom position. */
int	pos_in_chunk(t_node *a, int high)
{
	int pos_top, pos_bottom, len;
	if (a == NULL)
		return (-1);
	pos_top = find_first_pos_in_chunk(a, high);
	if (pos_top == -1)
		return (-1);
	find_last_pos_and_len(a, high, &pos_bottom, &len);
	if (pos_top <= (len - pos_bottom))
		return (pos_top);
	return (pos_bottom);
}
